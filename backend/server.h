#ifndef SERVER_H
#define SERVER_H

#include "blockchain.h"
#include <httplib.h>

class Server {
public:
    Server(const std::string& address, int port);

    void run();

private:
    Blockchain blockchain;
    httplib::Server server;
};

#endif // SERVER_H
