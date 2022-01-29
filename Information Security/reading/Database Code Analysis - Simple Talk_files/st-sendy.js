var ST = ST || {};

ST.Sendy = (function($){

	var controls = 'ul.subscription-controls';
	var forms = 'form.newsletter-signup';
	var notification = forms + ' .notification';
	var control = 'input.subscription-control';

	var multipleSubscriptionNotification = '<p class="notification notification--success spaced-top--tight">You are now subscribed to Simple Talk and the .NET Newsletter</p>';

	var init = function init() {
		ST.Sendy.bindHandlers();
	};

	var post = function post(action, postdata) {
		postdata['action'] = action;

		return $.ajax({
			type: 'POST',
			url: sendyOptions.ajaxUrl,
			data: postdata
		});
	};

	var getListName = function getListName(listId) {
		for (var list in sendyOptions.lists) {
			if (sendyOptions.lists[list] === listId) {
				return list;
			}
		}
		return false;
	};

	var writeNotification = function writeNotification(responseArray) {
		// write appropriate notification to page
		if (responseArray.length > 1) {
			$(forms).append(multipleSubscriptionNotification);
		} else if (responseArray.length === 1) {
			$(forms).append(responseArray[0]);
		}
	};

	var synchronizeInputs = function synchronizeInputs(input) {
		var formState = {};

		// get state of current form checkboxes
		$(input).parents('form').find('input[type="checkbox"]').each(function() {
			formState[this.value] = this.checked;
		});

		// apply state to all forms on page
		for (var value in formState) {
			$('input[value="' + value + '"]').attr('checked', formState[value]);
		}
	};

	var changeSubscription = function (action, inputs) {
		var postdata = {};
		var responseArray = [];
		var eventLabel;
		var input;
		var result;

		var emailInput = $(inputs).parents('form').find('input[type="email"]');
		var eventAction = action.replace('sendy-', '');

		function getInputLocation(input) {
			if ( $(input).parents('.sidebar').length ) {
				return 'sidebar';
			} else if ( $(input).parents('.article').length ) {
				return 'article';
			} else if ( $(input).parents('.account').length ) {
				return 'account';
			} else {
				return 'unknown';
			}
		}

		postdata.email = emailInput.val();

		// clear existing responses
		$(notification).remove();

		for (var i = 0; i < inputs.length; i++) {
			input = inputs[i];
			postdata.list = input.value;
			eventLabel = getListName(input.value) + ' - ' + getInputLocation(input);

			result = ST.Sendy.post(action, postdata);

			result.always(function(response) {
				$(input).removeClass('hc-checkbox--loading');
				responseArray.push(response);
			});

			result.done(function(response) {
				// set input to checked if we're subscribing
				input.checked = !!(action === 'sendy-subscribe');

				// synchronize inputs in the case of multiple forms on the page
				synchronizeInputs(input);

				// track Analytics event
				if (ST.analytics.trackerId) {
					ga(ST.analytics.trackerId + '.send', 'event', 'subscription change', eventAction, eventLabel);
				}
			});

			// if we're reached the end of the inputs, write notification to page
			if (i + 1 === inputs.length) {
				result.done(function(response) {
					writeNotification(responseArray);
				});
			}
		}
	};

	var getSubscriberStatus = function getSubscriberStatus(listId) {
		var postdata = {
			'list_id' : listId
		};

		var result = ST.Sendy.post('sendy-status', postdata);
	};

	var bindHandlers = function bindHandlers() {
		if (sendyOptions.is_user_logged_in) {
			$(control).on('change click', function(event) {
				var action = (this.checked) ? 'sendy-subscribe' : 'sendy-unsubscribe';

				event.preventDefault();
				$(this).addClass('hc-checkbox--loading');
				ST.Sendy.changeSubscription(action, [this]);
			});
		} else {
			$(forms).on('submit', function(event) {
				var selectedInputs = [];

				event.preventDefault();

				// populate selectedIds
				$('form.newsletter-signup input:checked').each(function() {
					selectedInputs.push( this );
				});

				ST.Sendy.changeSubscription('sendy-subscribe', selectedInputs);
			});
		}
	};

	return {
		init: init,
		post: post,
		changeSubscription: changeSubscription,
		getSubscriberStatus: getSubscriberStatus,
		bindHandlers: bindHandlers
	};

})(jQuery);

jQuery(function() {
	ST.Sendy.init();
});