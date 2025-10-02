const notyf = new Notyf({
	duration: 2000,
	position: { x: 'right', y: 'top' },
	ripple: false,
	dismissible: true,
});


function showSuccess(message='Operation successful!') {
  notyf.success(message);
}

function showError(message='An error occurred!') {
  notyf.error(message);
}

function showInfo(message='Here is some information.') {
  notyf.open({
	type: 'info',
	message: message,
	background: '#3498db',
	icon: {
	  className: 'fas fa-info-circle',
	  tagName: 'i',
	  color: '#fff'
	}
  });
}

document.body.addEventListener("htmx:afterRequest", function(event) {
	console.log(event);
	if(event.detail.successful)
		showSuccess("Success!");
});

document.body.addEventListener("htmx:responseError", function(event) {
	try {
		let data = JSON.parse(event.detail.xhr.responseText);
		showError("Request failed: " + (data.error || event.detail.xhr.statusText));
	} catch {
		showError("Request failed");
	}
});
