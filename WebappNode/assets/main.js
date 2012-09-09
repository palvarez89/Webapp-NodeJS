
var server = require("./server");
var router = require("./router");
var requestHandlers = require("./requestHandlers");
var handler = {}
handler["vibrate"] = requestHandlers.vibrate;
handler["beep"] = requestHandlers.beep;
handler["notificate"] = requestHandlers.notificate;
handler["ping"] = requestHandlers.ping;
handler["contacts"] = requestHandlers.contacts;
handler["sendSMS"] = requestHandlers.sendSMS;
handler["camera"] = requestHandlers.camera;
handler["acceleration"] = requestHandlers.acceleration;


handler["/a_donde_vas"] = requestHandlers.a_donde_vas;
handler["/disimula_disimula"] = requestHandlers.disimula_disimula;
server.start(router.route, handler);
