




// If you change this script be aware it might be cached, see the action
//
// This code aims to be resilient to failures from within the relying
// site. There's no need to be as defensive when interacting with
// provider site end-points as they're in the same project as this
// script and hence should be maintained, tested and deployed together
//
(function() { "use strict";

    var htmlStyle = document.documentElement.style;

    var previousVisibilityValue = htmlStyle.visibility;

    var renderDocument = function() {
        
        // We avoid overwriting any changes to the document's
        // visibility style that might have been made since ours
        //
        if (htmlStyle.visibility === "hidden") {
            
            htmlStyle.visibility = previousVisibilityValue;
        }
    };
    
    // In case the relying site's getIdentityConfiguration method
    // fails in such a way that it never calls our continuation
    // function we allow the document to render after a time-out
    //
    var safetyTimerId = setTimeout(renderDocument, 2000); // 2 seconds
    
    // Prevent the document from being visible to avoid the page
    // flashing-up before a login or logout redirect occurs
    //
    htmlStyle.visibility = "hidden";
    
    var isNonNullObject = function(property) {
      
        return typeof property === "object" && property !== null;
    };

    var getQueryParameters = function(result) {
        
        var queryPairs = [];
            
        if (   isNonNullObject(result.identity)
            && typeof result.identity.redgateId === "string") {
        
            queryPairs.push({ key:  "remoteRedgateId",
                              value: result.identity.redgateId });
        }
        
        if (   isNonNullObject(result.configuration)
            && isNonNullObject(result.configuration.urls)) {
                
            var urls = result.configuration.urls;
                
            if (typeof urls.login === "string") {
                
                queryPairs.push({ key: "loginUrl", value: urls.login });
            }
            
            if (typeof urls.logout === "string") {
                
                queryPairs.push({ key: "logoutUrl", value: urls.logout });
            }
        }
        
        return queryPairs;
    };
    
    var createQueryString = function(queryPairs) {
        
        if (queryPairs.length === 0) return "";
        
        var queryParts = [];
        
        queryParts = queryPairs.map(function(p) {

           return p.key + "=" + encodeURIComponent(p.value);
        });
        
        return "?" + queryParts.join("&");
    };
    
    // This is a safety cut-out intended to prevent a category of
    // failures from resulting in an infinite redirect loop which
    // would prevent users from interacting with the site entirely
    //
    var isSafeToRedirect = function(configuration) {
        
        // If the page has been rendered then we've missed our chance
        //
        if (   htmlStyle.visibility !== "hidden"
            || !isNonNullObject(configuration)
            || typeof configuration.appId !== "string") {
        
            return false;
        }
        
        // We have multiple apps with their own
        // logins hosted under the same domain(s)
        //
        var storageKey = "synchroniseIdentity.recentRedirectTimesUtc."
                       + configuration.appId.toLowerCase();

        var recentRedirectTimesUtc =
            JSON.parse(sessionStorage.getItem(storageKey)) || [];
        
        var nowUtc = new Date().getTime();

        recentRedirectTimesUtc = recentRedirectTimesUtc.filter(function(t) {
            
            // 15 seconds as each synchronisation step can reasonably
            // take 5 seconds with our current safety cut-out time
            // values and we shouldn't perform 3 or more back-to-back
            //
            return nowUtc - t <= 15000;
        });
        
        // We legitimately logout and login as two successive
        // redirect steps if the logged-in Redgate IDs don't match
        //
        if (recentRedirectTimesUtc.length >= 2) return false;
        
        recentRedirectTimesUtc.push(nowUtc);
        
        sessionStorage.setItem(storageKey,
                               JSON.stringify(recentRedirectTimesUtc));
        return true;
    };
    
    var performSynchronisationStep = function(synchronisationStep,
                                              configuration) {

        if (   typeof synchronisationStep.visitUrl === "string"
            && isSafeToRedirect(configuration)) {
                
            window.location = synchronisationStep.visitUrl;
            
            // We've got as far as asking the browser to redirect so
            // cancel the previous safety cut-out and start a new
            // one to give the browser time to load the next page
            //
            setTimeout(renderDocument, 3000); // 3 seconds
            
            clearTimeout(safetyTimerId);
        }
        else {
            
            // This must be in an else clause as setting window.location
            // doesn't immediately prevent script execution or rendering
            //
            renderDocument();
        }
    };
    
    var synchroniseIdentity = function(result) {

        // We avoid using jQuery here and make AJAX requests directly as:
        // 1. The relying site might not have included it everywhere
        // 2. We don't want to risk creating a jQuery version clash
        // 3. It's not easy to cleanly include jQuery and sandbox it
        //
        var xmlHttpRequest = new XMLHttpRequest();

        xmlHttpRequest.open("GET",
                            "https://identityprovider.red-gate.com/identity/synchronisationstep"
                            + createQueryString(getQueryParameters(result)));
                            
        xmlHttpRequest.withCredentials = true;
                            
        xmlHttpRequest.onerror = xmlHttpRequest.onabort = renderDocument;
                            
        xmlHttpRequest.onload = function(progressEvent) {
            
            var response = progressEvent.target;

            if (response.status < 200 || response.status >= 300) {
                
                renderDocument();
            }
            else {

                // At the time of writing, due to IE, we have to manually
                // parse the response rather than set the request to JSON
                //
                // While JSON.parse can throw we shouldn't
                // get a success status code with a malformed
                // or unrelated content from our own end-point
                //
                performSynchronisationStep(JSON.parse(response.response),
                                           result.configuration);
            }
        };
        
        xmlHttpRequest.send();
    };
    
    try {
        
        Redgate.Authentication.getIdentityConfiguration(function(result) {
            
            // We allow getIdentityConfiguration implementations to call
            // our continuation with no parameters to indicate a failure.
            // That allows us to render the document before the time-out
            //
            if (isNonNullObject(result)) synchroniseIdentity(result);
            else renderDocument();
        });
    }
    catch (exception) { renderDocument(); throw exception; }

})();