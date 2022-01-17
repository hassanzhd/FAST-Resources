(function ($) {
    'use strict';

    /**
     * All of the code for your public-facing JavaScript source
     * should reside in this file.
     *
     * Note that this assume you're going to use jQuery, so it prepares
     * the $ function reference to be used within the scope of this
     * function.
     *
     * From here, you're able to define handlers for when the DOM is
     * ready:
     *
     * $(function() {
     *
     * });
     *
     * Or when the window is loaded:
     *
     * $( window ).load(function() {
     *
     * });
     *
     * ...and so on.
     *
     * Remember that ideally, we should not attach any more than a single DOM-ready or window-load handler
     * for any particular page. Though other scripts in WordPress core, other plugins, and other themes may
     * be doing this, we should try to minimize doing that in our own work.
     */

    $(document).ready(function () {
       // console.log('CBX WP Bookmark init');

        var ajaxurl = cbxwpbookmark.ajaxurl;

        //on click create category
        $('.cbxwpbkmarkaddnewcatcreate').on('click', function (event) {
            event.preventDefault();

            var $addnewwrap = $(this).parents('.cbxwpbkmarkaddnewwrap');
            var $globalparent = $(this).parents('.cbxwpbkmarkwrap');

            var $cat_name = $addnewwrap.find('.cbxwpbkmarkaddnewcatinput');

            var $object_id = $(this).data('object_id');

            var $privacy = $addnewwrap.find('.cbxwpbkmarkaddnewcatselect');

            //console.log($privacy.val());

            //check if the input text field is empty or not
            //if the text input for category name validate then send ajax request

            if ($cat_name.val() != '') {
                $globalparent.find(".cbx-onclick-loading").show();
                //send ajax request
                var data = {
                    'action': 'cbx_add_category',
                    'security': cbxwpbookmark.nonce,
                    'catename': $cat_name.val(),
                    'privacy': $privacy.val(),
                    'object_id': $object_id
                };

                // We can also pass the url value separately from ajaxurl for front end AJAX implementations
                $.post(ajaxurl, data, function (response) {
                    //console.log('Got this from the server: ' + response);
                    response = $.parseJSON(response);
                    if (response.code == 2) {

                        //category created
                        $cat_name.val('');

                        var cats = $.parseJSON(response.cats);
                        //console.log(cats);
                        var catoptions = '';

                        $.each(cats, function (key, val) {

                            catoptions += "<li class=\"cbxlbjs-item\" data-privacy=" + cats[key].privacy + " data-incat=" + cats[key].incat + "  data-value='" + cats[key].id + "'>Add to " + cats[key].cat_name + "</li>";


                        });


                        $globalparent.find('.cbxwpbkmarklist').html(catoptions);

                        $globalparent.find(".cbx-onclick-loading").hide();


                        //hide the category create panel and show the add new category button link again
                        $globalparent.find('.cbxwpbkmarkaddnewwrap, .cbxwpbkmarkcreatecatmsg').hide();
                        $globalparent.find('.cbxwpbkmarkaddnewcattrig, .cbxwpbkmarkselwrap').show();


                    }
                    else {
                        //failed or duplicate
                        $globalparent.find('.cbx-onclick-loading').show('slow');


                    }
                });

            }
            else {
                $(".cbx-bookmark-sms").html("<span class=''></span>")
                console.log('input field is empty');
            }

        });


        //on click add category
        $('.cbxwpbkmarkaddnewcattrig').on('click', function (event) {
            event.preventDefault();
            $(this).next('.cbxwpbkmarkaddnewwrap').show();
            $(this).hide();
        });


        //on click on +add  it will open the boomark panel
        $('.cbxwpbkmarktrig').on('click', function (event) {
            event.stopPropagation();
            event.preventDefault();

            var $object_id = $(this).data('object_id'); //post id
            var $object_type = $(this).data('type'); //post type

            var $open = $(this).data("open");
            var $bookmarkpanel = $(this).next('.cbxwpbkmarklistwrap');


            $($bookmarkpanel).toggle("fast", function () {
                $(this).data("open", 1);
                //not opened yet, good to go
                //show the ajax icon
                $bookmarkpanel.find('.cbxwpbkmarkloading').show();
                //send ajax request to popular the categories as fresh

                var data = {
                    'action': 'cbx_find_category',
                    'security': cbxwpbookmark.nonce,
                    'object_id': $object_id,
                    'object_type': $object_type
                };

                // We can also pass the url value separately from ajaxurl for front end AJAX implementations
                $.post(ajaxurl, data, function (response) {
                    // console.log('Got this from the server: ' + response);
                    response = $.parseJSON(response);
                    //  console.log(response);
                    if (response && response.code == 1) {
                        //categories found
                        $bookmarkpanel.find('.cbxwpbkmarkloading').hide();
                        $bookmarkpanel.find('.cbxwpbkmarkselwrap').show();
                        var cats = $.parseJSON(response.cats);
                        var catoptions = '';

                        $.each(cats, function (key, val) {
                            catoptions += "<li class=\"cbxlbjs-item\" data-privacy=" + cats[key].privacy + " data-incat=" + cats[key].incat + "  data-value='" + cats[key].id + "'>Add to <span class=\"cbxlbjs-item-name\">" + cats[key].cat_name + "</span></li>";
                        });

                        $bookmarkpanel.find('.cbxwpbkmarklist').html(catoptions);

                        //$bookmarkpanel.find( ".cbxwpbkmarklist" ).each( function( index, element ){
                            //search (fuzzy search plugin)
                            //console.log(element);

                            //var catholder = $bookmarkpanel.find('.cbxwpbkmarklist');
                            //console.log(catholder);
                            //console.log($(catholder));

                            /*
                            var bookmarksearch = new List(catholder, {
                                valueNames: ['cbxlbjs-item-name'],
                                plugins: [ ListFuzzySearch() ]
                            });
                            */

                        //});
                    }
                    else {
                        //failed to get category for this user
                        //console.log(response);
                        $bookmarkpanel.find('.cbxwpbkmarkloading, .cbxwpbkmarkaddnewcattrig').hide();
                        $bookmarkpanel.find('.cbxwpbkmarkaddnewwrap, .cbxwpbkmarkcreatecatmsg').show();
                    }
                });
            });

            if ($open) {
                //already opened
                //$bookmarkpanel.hide();

            } else {


            }
        });
        //on click Add Bookmark

        $("body").mouseup(function (e) {
            var subject = $(".cbxwpbkmarklistwrap");

            if ((e.target.id != 'cbxwpbkmarklistwrap-' + subject.data('object_id')) && !subject.has(e.target).length) {
                subject.fadeOut();
            }
        });


        //adding click event on the list
        $('.cbxwpbkmark-lbjs').on('click', '.cbxlbjs-item', function () {


            var $bookmarkpanel = $(this).parents('.cbxwpbkmarklistwrap');
            $bookmarkpanel.find(".cbx-onclick-loading").show();


            var $object_id = $bookmarkpanel.data('object_id');
            var $object_type = $bookmarkpanel.data('type'); //object type

            console.log($object_type);
            console.log($object_id);

            var $cat_id = $(this).attr('data-value');

            var $item = $(this);

            //now send ajax request to save this post id and category as bookmark for this user
            //post id already in variable $object_id

            var addcat = {
                'action': 'cbx_add_bookmark',
                'security': cbxwpbookmark.nonce,
                'cat_id': $cat_id,
                'object_id': $object_id,
                'object_type': $object_type
            };

            $.post(ajaxurl, addcat, function (response) {

                response = $.parseJSON(response)
                if (response.code) {

                    $item.attr('data-incat', response.operation);
                    $bookmarkpanel.find(".cbx-onclick-loading").hide();
                }
                else {
                    console.log(response);
                }
            });


        });


        /* User Front Admin */


        //my category update event

        //save button action
        $('.cbxbookmark-category-list').on('click', 'a.cbxbookmark-cat-save', function (event) {


            event.preventDefault();


            var $parent = $(this).closest('li.cbxbookmark-mycat-item');

            var _$this = $(this);


            var $ucatid = $parent.data('id'); //get this value from the parent data attribute


            //get new value
            var $ucatname = $parent.find('.cbxbmedit-catname').val();
            var $uprivacy = $parent.find('.cbxbmedit-privacy').val();


            var updatedata = {
                'action': 'cbx_update_bookmark_category',
                'security': cbxwpbookmark.nonce,
                'id': $ucatid,
                'catname': $ucatname,
                'privacy': $uprivacy
            };

            _$this.find('span').css({
                'display': 'inline-block'
            });

            // We can also pass the url value separately from ajaxurl for front end AJAX implementations
            $.post(ajaxurl, updatedata, function (response) {

                response = $.parseJSON(response);

                if (response.flag == 1) {

                    $parent.find(".cbxbookmark-mycat-editbox").hide();
                    $parent.data('privacy', response.privacy);
                    $parent.data('name', response.catname);
                    $parent.find(".cbxlbjs-item-widget").html(response.catname);


                }
                else if (response.flag == 0) {
                    //$(".msg").html(response.msg);
                    $parent.parent('.cbxbookmark-category-list').prev('.cbxbookmark-errormsg').html(response.msg);
                }

                _$this.find('span').css({
                    'display': 'none'
                });

            });

        });


        //my category edit button action
        //edit button action and it opens the edit panel for the clicked item
        $('.cbxbookmark-category-list').on('click', 'a.cbxbookmark-edit-btn', function (event) {

            event.preventDefault();
            var $parent = $(this).parent('.cbxbookmark-mycat-item');

            var _$this = $(this);
            //  $(_$thisedit).removeClass("cbxbookmark-delete-btn");

            var $catid = $parent.data('id');
            var $catname = $parent.data('name');
            var $privacy = $parent.data('privacy');

            var $editpanel = $parent.find(".cbxbookmark-mycat-editbox");
            if ($editpanel.length == 0) {
                var $template = $.parseJSON(cbxwpbookmark.cat_template);

                /* Repalcing Input Values */
                var $template = $template.replace(/##catname##/g, $catname);
                $parent.append($template);

                if ($privacy == 0) {
                    $parent.find(".cbxbmedit-privacy option:eq(1)").prop('selected', true);
                    $parent.find(".cbxbmedit-privacy option:eq(0)").prop('selected', false);
                }

                if ($privacy == 1) {
                    $parent.find(".cbxbmedit-privacy option:eq(0)").prop('selected', true);
                    $parent.find(".cbxbmedit-privacy option:eq(1)").prop('selected', false);
                }
            }
            else {
                $editpanel.show();
                $parent.find('.cbxbmedit-catname').val($catname);
                //$parent.find('.cbxbmedit-privacy').val($privacy);

                if ($privacy == 0) {
                    $parent.find(".cbxbmedit-privacy option:eq(1)").prop('selected', true);
                    $parent.find(".cbxbmedit-privacy option:eq(0)").prop('selected', false);
                }

                if ($privacy == 1) {
                    $parent.find(".cbxbmedit-privacy option:eq(0)").prop('selected', true);
                    $parent.find(".cbxbmedit-privacy option:eq(1)").prop('selected', false);
                }
            }


        });


        //close action for edit panel for each single item
        $('.cbxbookmark-category-list').on('click', '.cbxbookmark-cat-close', function (e) {

            e.preventDefault();
            //$(".cbxbookmark-mycat-editbox").css("display", "none");
            $(this).parent(".cbxbookmark-mycat-editbox").css("display", "none");

        });


        //my category delete button action
        $('.cbxbookmark-category-list').on('click', 'a.cbxbookmark-delete-btn', function (event) {
            event.preventDefault();


            if (!confirm(cbxwpbookmark.areyousuretodeletecat)) {
                return false;
            }

            var $id = $(this).data('id');

            var _$this = $(this);

            //  console.log($id);
            var data = {
                'action': 'cbx_delete_bookmark_category',
                'security': cbxwpbookmark.nonce,
                'id': $id
            };
            // We can also pass the url value separately from ajaxurl for front end AJAX implementations

            if (_$this) {

                _$this.find('span').css({
                    'display': 'inline-block'
                });

                $.post(ajaxurl, data, function (response) {
                    //console.log('Got this from the server: ' + response);
                    response = $.parseJSON(response);
                    //  console.log( response );

                    if (response.msg == 0) {

                        // success Message
                        var message = cbxwpbookmark.category_delete_success;

                        // Remove the li tag if the category deleted
                        $(_$this).parent("li").remove();

                        // Loading success message on .msg div element
                        $(".msg").html(message);

                    }
                    else {
                        var message = cbxwpbookmark.category_delete_error;
                        $(".msg").html(message);
                    }
                    //console.log(message);

                    _$this.find('span').css({
                        'display': 'none'
                    });
                });
            }
        });


        /**
         * delete bookmark
         */
        $('.cbxwpbookmark-mylist').on('click', 'a.cbxbookmark-post-delete', function (event) {
            event.preventDefault();

            if (!confirm(cbxwpbookmark.areyousuretodeletebookmark)) {
                return false;
            }

            var $postdelete = $(this);
            //var $userid = $postdelete.data("userid");
            var $objectid = $postdelete.data("id");

            var data = {
                'action': 'cbx_delete_bookmark_post',
                'security': cbxwpbookmark.nonce,
                //'userid': $userid,
                'postid': $objectid
            };
            // We can also pass the url value separately from ajaxurl for front end AJAX implementations

            if ($postdelete) {

                $postdelete.find('span').css({
                    'display': 'inline-block'
                });

                $.post(ajaxurl, data, function (response) {
                    //console.log('Got this from the server: ' + response);
                    response = $.parseJSON(response);
                    console.log(response);

                    if (response.msg == 0) {
                        // Remove the li tag if the bookmark is deleted
                        $postdelete.parent("li").remove();
                        // success Message
                        //var message = "Bookmark Removed";

                        // Loading success message on .msg div element
                        //$(".postmsg").html(message);
                        $(".msg").html(cbxwpbookmark.bookmark_removed);
                        //console.log($objectid);
                    }
                    else if (response.msg == 1) {
                        //var message = "Faild to Bookmark";
                        //$(".postmsg").html(message);
                        $(".msg").html(cbxwpbookmark.bookmark_failed);
                    }
                    $postdelete.find('span').css({
                        'display': 'none'
                    });
                });


            }
        });


        //implementing the bookmark load more feature

        $('.cbxbookmark-more').on('click', function (e) {
            e.preventDefault();
            var _this = $(this);

            $('.cbxwpbm_ajax_icon').show();

            var prev = _this.prev('ul.cbxwpbookmark-mylist');
            var limit = _this.data('limit');
            var offset = _this.data('offset');
            var catid = _this.data('catid');

            var order = _this.data('order');
            var orderby = _this.data('orderby');
            var userid = _this.data('userid');

            var totalpage = _this.data('totalpage');
            var currpage = _this.data('currpage');

            if (currpage + 1 >= totalpage) {
                _this.hide();
            } else {
                _this.show();
            }

            var addcat = {
                'action': 'cbx_bookmark_loadmore',
                'security': cbxwpbookmark.nonce,
                'limit': limit,
                'offset': offset,
                'catid': catid,
                'order': order,
                'orderby': orderby,
                'userid': userid
            };

            $.post(ajaxurl, addcat, function (response) {

                response = $.parseJSON(response);

                if (response.code) {
                    $('.cbxbookmark-more').data('offset', limit + offset);
                    $('.cbxbookmark-more').data('currpage', currpage + 1);
                    setTimeout(function () {
                        $('.cbxwpbm_ajax_icon').hide();
                        prev.append(response.data);

                    }, 2000);

                } else {
                    console.log('Error loading data. Response code=' + response.code);
                }


            });


        });

        //category search using fuzzy logic
        /* filter dinosaurs as you type */
        $(".cbxwpbkmarkwrap").on('keyup','.cbxlbjs-searchbar', function () {


            var $this = $(this);
            var val = $this.val();



            var catlistholder = $this.parent('.cbxlbjs-searchbar-wrapper').next('.cbxwpbkmarklist');


            if (this.value.length > 0) {
                catlistholder.find('li').hide().filter(function () {
                    return $(this).text().toLowerCase().indexOf(val.toLowerCase()) != -1;
                }).show();
            }
            else {
                catlistholder.find('li').show();
            }

        });







    });

})(jQuery);

