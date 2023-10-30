#include "server.h"
#include <iostream>
#include <httplib.h>

Server::Server(const std::string& address, int port)
    : server(address.c_str(), port) {
    // Define server endpoints
    server.Get("/get_blockchain", [&](const httplib::Request&, httplib::Response& res) {
        std::string blockchainJson = blockchain.getJsonRepresentation();
        res.set_content(blockchainJson, "application/json");
    });

    server.Get("/get_last_block", [&](const httplib::Request&, httplib::Response& res) {
        std::string lastBlockJson = blockchain.getJsonRepresentation();
        res.set_content(lastBlockJson, "application/json");
    });

    server.Post("/add_block", [&](const httplib::Request& req, httplib::Response& res) {
        // Parse JSON data from the request
        nlohmann::json jsonData = nlohmann::json::parse(req.body);

        if (jsonData.find("data") != jsonData.end()) {
            std::string data = jsonData["data"];
            blockchain.addBlock(data);
            res.set_content("Block added successfully", "text/plain");
        } else {
            res.status = 400; // Bad Request
            res.set_content("Invalid request data", "text/plain");
        }
    });
}

void Server::run() {
    std::cout << "Blockchain server is running..." << std::endl;
    server.listen();
}
