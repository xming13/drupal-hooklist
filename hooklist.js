(function() {
    var $ = jQuery;

    $(document).ready(function() {
        // highlight.js - init
        hljs.initHighlightingOnLoad();
        
        // toggle code sample
        $('.toggle').click(function() {
            var sample = this.parentNode.nextElementSibling;

            if (sample) {
                if (this.innerHTML === '+') {
                    $(sample).fadeIn('fast');
                    this.innerHTML = '-';
                } else {
                    $(sample).fadeOut('fast');
                    this.innerHTML = '+';
                }
            }
        });

        // filter tags
        $('.tag.filter').click(function() {
            var tagType = '';
            var tagPrefix = 'tag-';

            // extract tagType to class with tagPrefix
            // e.g. extract 'optional' from 'tag-optional'
            var cssClasses = this.attributes['class'].value.split(' ');
            for (var i = 0; i < cssClasses.length; i++) {
                if (cssClasses[i].indexOf(tagPrefix) > -1) {
                    tagType = cssClasses[i].slice(tagPrefix.length);
                    break;
                }
            }

            var tagFilter = $('.filter.tag-' + tagType);

            if (tagFilter) {
                tagFilter.toggleClass('selected');

                $('.hook').each(function() {
                    if ($(this).hasClass('hook-' + tagType) && tagFilter.hasClass('selected')) {
                        $(this).show();
                    } else {
                        // check if other filter is selected 
                        // and matches the current element
                        
                        var tagTypes = filterAndRemovePrefix(
                            this.attributes['class'].value.split(' '), 'hook-');

                        for (var i = 0; i < tagTypes.length; i++) {
                            if ($('.filter.selected.tag-' + tagTypes[i]).length > 0) {
                                break;
                            }
                            if (i === tagTypes.length - 1) {
                                $(this).hide();
                            }
                        }
                    }
                });
            }
        });

        // filter array to those that have the prefix 
        // and return an array by removing the prefix
        // 
        // e.g. stringArr: ['tag-abc', 'tag-def', 'orange']
        //      prefix   : 'tag'
        //      return ['abc', 'def']
        function filterAndRemovePrefix(stringArr, prefix) {
            var result = [];
            for (var i = 0; i < stringArr.length; i++) {
                if (stringArr[i].indexOf(prefix) > -1) {
                    result.push(stringArr[i].slice(prefix.length));
                }
            }
            return result;
        }
    });
})();