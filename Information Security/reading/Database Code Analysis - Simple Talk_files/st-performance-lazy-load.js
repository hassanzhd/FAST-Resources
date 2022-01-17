var ST = ST || {};
ST.Performance = ST.Performance || {};
ST.Performance.LazyLoad = ST.Performance.LazyLoad || {};

ST.Performance.LazyLoad.Images = (function(){
    var images = null;
    var active = false;

    /**
     * Initialise the lazy loading of images.
     *
     * Check to see if any images exist on the page, and
     * if so, check which method to use to load them in.
     */
    var init = function init () {
        images = document.querySelectorAll('img[data-lazy-load]');
        if (images.length > 0) {
            if ("IntersectionObserver" in window) {
                lazyLoadUsingIntersectionObserver();
            } else {
                lazyLoadUsingScroll();
            }
        }
    };

    /**
     * Load in images using the `IntersectionObserver`
     * functionality (The preferred method).
     *
     * Unfortunately this isn't supported by all browsers
     * yet, so we have to offer another method
     * (@see `lazyLoadUsingScroll`)
     *
     * @return void
     */
    var lazyLoadUsingIntersectionObserver = function lazyLoadUsingIntersectionObserver () {
        var imageObserver = new IntersectionObserver(function(entries, observer) {
            for (var i = 0; i < entries.length; i++) {
                var entry = entries[i];
                if (entry.isIntersecting) {
                    var image = entry.target;
                    image.src = image.getAttribute('data-src');
                    image.removeAttribute('data-lazy-load');
                    imageObserver.unobserve(image);
                }
            }
        });

        for (var i=0; i<images.length; i++) {
            var image = images[i];
            imageObserver.observe(image);
        }
    };

    /**
     * Load in images using the old fashioned
     * method of checking to see if the image
     * is in the current viewport, using the
     * `resize` and `scroll` events.
     *
     * @return void
     */
    var lazyLoadUsingScroll = function lazyLoadUsingScroll () {
        if (active === false) {
            active = true;

            setTimeout(function() {
                for (var i=0; i<images.length; i++) {
                    var image = images[i];
                    if (
                        image.getBoundingClientRect().top <= window.innerHeight &&
                        image.getBoundingClientRect().bottom >= 0 &&
                        image.hasAttribute('data-lazy-load')
                    ) {
                        image.src = image.getAttribute('data-src');
                        image.removeAttribute('data-lazy-load');

                        if (i === (images.length - 1)) {
                            document.removeEventListener("scroll", lazyLoadUsingScroll);
                            window.removeEventListener("resize", lazyLoadUsingScroll);
                            window.removeEventListener("orientationchange", lazyLoadUsingScroll);
                        }
                    }
                }
                active = false;
            }, 200);
        }

        document.addEventListener("scroll", lazyLoadUsingScroll);
        window.addEventListener("resize", lazyLoadUsingScroll);
        window.addEventListener("orientationchange", lazyLoadUsingScroll);
    };

    return {
        init: init
    };
})();

window.addEventListener('DOMContentLoaded', ST.Performance.LazyLoad.Images.init);