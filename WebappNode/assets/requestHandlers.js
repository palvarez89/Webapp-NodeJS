function a_donde_vas(response, callback) {
    console.log("Handler for request 'a_donde_vas' dispatched.");
    response.writeHead(200, {"Content-Type": "text/html"});
    response.write("Patatas traigo");
    response.end();
}
function disimula_disimula(response, callback) {
    console.log("Handler for request 'disimula_disimula' dispatched.");
    response.writeHead(200, {"Content-Type": "text/html"});
    response.write("Y la mula dijo si");
    response.end();
}


var bridge = require("bridge");
var vibrator = null;
var notificator = null;
var beeper = null;
var SMSsender = null;
var Photograph = null;
var Accelerometer = null;

function vibrate(response, pquery) {

	if(vibrator==null) vibrator = bridge.load('com.example.api.NodeVibratorImpl', this);
	var time=null;
	if(pquery.time){
		console.log("Vibra un tiempo");
		time=(pquery.time, 10);
		console.log(time);
		
		vibrator.vibrate(time);
	}
	else if(pquery.pattern){
		console.log("Vibra un patron");
		var pattern = pquery.pattern.split(",");
		for(var i=0; i<pattern.length; i++) { pattern[i] = parseInt(pattern[i], 10); } 
		console.log(pattern);
		vibrator.vibratePattern(pattern,-1);
	
	}
	else{
		console.log("Vibra un tiempo predefinido");
		time=500;
		console.log(time);
		vibrator.vibrate(time);
	}

	
	var callback = (pquery.callback ? pquery.callback : '');
	var returnObject = {ok: true};
    var returnObjectString = JSON.stringify(returnObject);

    //push back the response including the callback shenanigans
    response.writeHead(200, {'Content-Type': 'application/javascript'});
    response.end(callback + '(\'' + returnObjectString + '\')');
	

    console.log(returnObject);
}

function beep (response,pquery) {
	if(beeper==null) beeper = bridge.load('com.beep.api.NodeBeeperImpl', this);
	var callback = (pquery.callback ? pquery.callback : '');
	var times = null;
	if(!pquery.times) {
		times = 1;
	}
	else{
		times = parseInt(pquery.times,10);
	}
	beeper.beep(times);
	console.log("Beep "+times+" veces");

	var returnObject = {ok: true};
    var returnObjectString = JSON.stringify(returnObject);

    //push back the response including the callback shenanigans
    response.writeHead(200, {'Content-Type': 'application/javascript'});
    response.end(callback + '(\'' + returnObjectString + '\')');
	

    console.log(returnObject);

}


function notificate (response,pquery) {
	if(notificator==null) notificator = bridge.load('com.notification.api.NodeNotificatorImpl', this);
	var callback = (pquery.callback ? pquery.callback : '');
	var ticker = null;
	var title = null;
	var text = null;
	var returnObject = null;
	
	if(!pquery.ticker || !pquery.title || !pquery.text) {
		console.log("Datos incompletos");
		returnObject = {ok: false};
	}
	else{
		title=pquery.title;
		text=pquery.text;
		ticker=pquery.ticker;
		
		notificator.notification(ticker,title,text);

		console.log("Notificate Title: "+title+" Text: "+text+" Ticker: "+ticker);
		returnObject = {ok: true};
	}
	

    var returnObjectString = JSON.stringify(returnObject);

    //push back the response including the callback shenanigans
    response.writeHead(200, {'Content-Type': 'application/javascript'});
    response.end(callback + '(\'' + returnObjectString + '\')');
	

    console.log(returnObject);

}


function ping (response,pquery) {
	var callback = (pquery.callback ? pquery.callback : '');
	var returnObject = {ok: true};
    var returnObjectString = JSON.stringify(returnObject);

    //push back the response including the callback shenanigans
    response.writeHead(200, {'Content-Type': 'application/javascript'});
    response.end(callback + '(\'' + returnObjectString + '\')');
	

    console.log(returnObject);

}

var contactList = bridge.load('com.contacts.api.NodeContactsImpl', this);

function contacts (response,pquery) {
	var callback = (pquery.callback ? pquery.callback : '');
	
	var arrayContactos = [];
	var nombre;
	var arrayNumeros;
	var contactSize = contactList.size();
	for(i=0;i<contactSize;i++){
		nombre=contactList.getName(i);
		arrayNumeros=contactList.getNumbers(i);
		
		arrayContactos.push({
			name: {givenName: nombre},
			phoneNumbers: arrayNumeros
		});
		
	}
	
	
	
	var returnObject = {contacts: arrayContactos,
						ok: true};
    var returnObjectString = JSON.stringify(returnObject);

    //push back the response including the callback shenanigans
    response.writeHead(200, {'Content-Type': 'application/javascript'});
    response.end(callback + '(\'' + returnObjectString + '\')');
	

    console.log(returnObject);

}


function sendSMS (response,pquery) {

	if (SMSsender==null) SMSsender = bridge.load('com.SMS.api.NodeSMSImpl', this);
	var callback = (pquery.callback ? pquery.callback : '');
	
	if(!pquery.number || !pquery.body) {
		console.log("Datos incompletos");
		returnObject = {ok: false};
	}
	else {
		console.log("Enviando sms a: "+pquery.number+" Con texto: "+pquery.body);
		SMSsender.sendSMS(pquery.number,pquery.body);
		var returnObject = {ok: true};
	}
    var returnObjectString = JSON.stringify(returnObject);
	
    //push back the response including the callback shenanigans
    response.writeHead(200, {'Content-Type': 'application/javascript'});
    response.end(callback + '(\'' + returnObjectString + '\')');
	

    console.log(returnObject);

}

function camera (response,pquery) {
	
	if (Photograph == null) Photograph = bridge.load('com.camera.api.NodeCameraImpl', this);
	Photograph.makePhoto();
	var path = Photograph.getPath();
	var filename = Photograph.getName();
	

	var callback = (pquery.callback ? pquery.callback : '');
	
	var returnObject = {fullPath: path, name: filename, ok: true};
	var returnObjectString = JSON.stringify(returnObject);
	
    //push back the response including the callback shenanigans
    response.writeHead(200, {'Content-Type': 'application/javascript'});
    response.end(callback + '(\'' + returnObjectString + '\')');
	

    console.log(returnObject);
}


function acceleration(response, pquery) {

    if (Accelerometer == null) Accelerometer = bridge.load('com.acceleration.api.NodeAccelerationImpl', this);
	
    var ax = Accelerometer.getX();
    var ay = Accelerometer.getY();
    var az = Accelerometer.getZ();

    var callback = (pquery.callback ? pquery.callback : '');
    ax= ax/10000;
    ay= ay/10000;
    az= az/10000;

    var returnObject = {
        x: ax,
        y: ay,
        z: az,
        ok: true
    };
    var returnObjectString = JSON.stringify(returnObject);

    //push back the response including the callback shenanigans
    response.writeHead(200, {
        'Content-Type': 'application/javascript'
    });
    response.end(callback + '(\'' + returnObjectString + '\')');


    console.log(returnObject);
}

exports.a_donde_vas = a_donde_vas;
exports.disimula_disimula = disimula_disimula;
exports.vibrate = vibrate;
exports.beep = beep;
exports.notificate = notificate;
exports.ping = ping;
exports.contacts = contacts;
exports.sendSMS = sendSMS;
exports.camera = camera;
exports.acceleration = acceleration;

