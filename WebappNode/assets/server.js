var http = require("http");
var querystring = require('querystring');
var url = require("url");
function serverStart(route, handler) {
    http.createServer(function(request, response) {
 
 
		var pquery = querystring.parse(url.parse(request.url).query); 
		
		console.log(pquery);
		// var strArray = pquery.array.split(",");
		// for(var i=0; i<strArray.length; i++) { strArray[i] = parseInt(strArray[i], 10); } 
		// console.log(strArray);
		
		
		// var callback = (pquery.callback ? pquery.callback : '');
	
		// var peticion=pquery.action;

        route(handler, pquery, response);
        response.writeHead(200, {"Content-Type": "text/html"});
        response.write("¿Que pasa tronco?");
        response.end();
    }).listen(4444);
    console.log("Server started...");
}
exports.start = serverStart;
/*
var http = require('http');
var querystring = require('querystring');
var url = require('url');

http.createServer(function (req, res) {
    //grab the callback from the query string   
    var pquery = querystring.parse(url.parse(req.url).query);   
    var callback = (pquery.callback ? pquery.callback : '');
	
	
	
	console.log("pquery.action:");
	console.log(pquery.action);
	
	
	
	
    //we probably want to send an object back in response to the request
    var returnObject = {message: "Hello World!"};
    var returnObjectString = JSON.stringify(returnObject);

    //push back the response including the callback shenanigans
    res.writeHead(200, {'Content-Type': 'application/javascript'});
    res.end(callback + '(\'' + returnObjectString + '\')');
}).listen(4444);
console.log('Server running at http://127.0.0.1:4444/');*/