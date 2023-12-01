#ifndef WEBSOCKET_SERVER_H
#define WEBSOCKET_SERVER_H

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

class WebSocketServer {
public:
    WebSocketServer();
    void run();
private:
    typedef websocketpp::server<websocketpp::config::asio> server_t;
    server_t server;
    
    void on_message(websocketpp::connection_hdl hdl, server_t::message_ptr msg);
    // Add other private functions and members as needed
};

#endif // WEBSOCKET_SERVER_H
