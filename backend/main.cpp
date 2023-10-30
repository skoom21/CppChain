#include "blockchain.h"
#include "server.h"

int main() {
    Server server("localhost", 8080);

    // Start the server
    server.run();

    return 0;
}
