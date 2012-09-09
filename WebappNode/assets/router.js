function route(handler, pquery, response) {

	var action=pquery.action;
    console.log("Routing a new petition for " + action);
    if (typeof handler[action] === 'function') {
        handler[action](response,pquery);
    } else {
        console.log("No request handler for " + action + " skipping");
        response.writeHead(404, {"Content-Type": "text/html"});
        response.write("404 Not Found");
        response.end();
    }
}
exports.route = route;