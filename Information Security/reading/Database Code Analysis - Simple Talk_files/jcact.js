var _gaq = _gaq || [];

jQuery(function($) {

    // -- Set Options --
    
    var debugMode = false;
    if (jcact_script_options && jcact_script_options.debugMode === 'true') {
        debugMode = true;
    }
    var contentSelector = ".entry-content";
    if (jcact_script_options && jcact_script_options.contentSelector) {
        contentSelector = jcact_script_options.contentSelector;
    }
    var contentSelector = ".entry-content";
    if (jcact_script_options && jcact_script_options.contentSelector) {
        contentSelector = jcact_script_options.contentSelector;
    }
    // Default time delay before checking location
    var delayAfterScroll = 100;
    if (jcact_script_options && jcact_script_options.delayAfterScroll) {
        delayAfterScroll = parseInt(jcact_script_options.delayAfterScroll);
    }
    // # px before tracking a reader
    var startedReadingLocation = 150;
    if (jcact_script_options && jcact_script_options.startedReadingLocation) {
        startedReadingLocation = parseInt(jcact_script_options.startedReadingLocation);
    }
      
    // Set some flags for tracking & execution
    var timer = 0;
    var scroller = false;
    var endContent = false;
    var didComplete = false;

    // Set some time variables to calculate reading time
    var startTime = new Date();
    var beginning = startTime.getTime();
    var totalTime = 0;

    // Get some information about the current page
    var pageTitle = document.title;

    // Track the aticle load
    if (!debugMode) {
        _gaq.push(['_trackEvent', 'Reading', 'ArticleLoaded', '', , true]);
    } else {
        alert('The page has loaded. Woohoo.');
    }

    // Check the location and track user
    function trackLocation() {
        bottom = $(window).height() + $(window).scrollTop();
        height = $(document).height();

        // If user starts to scroll send an event
        if (bottom > startedReadingLocation && !scroller) {
            currentTime = new Date();
            scrollStart = currentTime.getTime();
            timeToScroll = Math.round((scrollStart - beginning) / 1000);
            if (!debugMode) {
                _gaq.push(['_trackEvent', 'Reading', 'StartReading', '', timeToScroll]);
            } else {
                alert('started reading ' + timeToScroll);
            }
            scroller = true;
        }

        // If user has hit the bottom of the content send an event
        if (bottom >= $(contentSelector).scrollTop() + $(contentSelector).innerHeight() && !endContent) {
            currentTime = new Date();
            contentScrollEnd = currentTime.getTime();
            timeToContentEnd = Math.round((contentScrollEnd - scrollStart) / 1000);
            if (!debugMode) {
                _gaq.push(['_trackEvent', 'Reading', 'ContentBottom', '', timeToContentEnd]);
            } else {
                alert('end content section ' + timeToContentEnd);
            }
            endContent = true;
        }

        // If user has hit the bottom of page send an event
        if (bottom >= height && !didComplete) {
            currentTime = new Date();
            end = currentTime.getTime();
            totalTime = Math.round((end - scrollStart) / 1000);
            if (!debugMode) {
                if (totalTime < 60) {
                    _gaq.push(['_setCustomVar', 5, 'ReaderType', 'Scanner', 2]);
                } else {
                    _gaq.push(['_setCustomVar', 5, 'ReaderType', 'Reader', 2]);
                }
                _gaq.push(['_trackEvent', 'Reading', 'PageBottom', pageTitle, totalTime]);
            } else {
                alert('bottom of page ' + totalTime);
            }
            didComplete = true;
        }
    }

    // Track the scrolling and track location
    $(window).scroll(function() {
        if (timer) {
            clearTimeout(timer);
        }

        // Use a buffer so we don't call trackLocation too often.
        timer = setTimeout(trackLocation, delayAfterScroll);
    });
});
