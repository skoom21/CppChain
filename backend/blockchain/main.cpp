#include <iostream>
#include <vector>
#include <random>
#include "Blockchain.h"
#include "httplib.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

// Function to generate random transactions
Transaction generateRandomTransaction() {
    string sender = "User" + to_string(rand() % 10); // Generate sender name
    string receiver = "User" + to_string(rand() % 10); // Generate receiver name
    double amount = (rand() % 100) + 1.0; // Generate a random amount between 1 and 100
    return Transaction(sender, receiver, amount);
}

// Function to serialize a block to JSON
json blockToJson(Block& block) {
    json blockJson;
    blockJson["index"] = block.getIndex();
    blockJson["previousHash"] = block.getPreviousHash();
    blockJson["merkleRoot"] = block.getMerkleRoot();
    blockJson["timestamp"] = block.getTimestamp();
    blockJson["nonce"] = block.getNonce();
    blockJson["hash"] = block.getHash();

    // Serialize transactions for this block
    json transactionsJson;
    for (const Transaction& transaction : block.getTransactions()) {
        json transactionJson;
        transactionJson["sender"] = transaction.sender;
        transactionJson["receiver"] = transaction.receiver;
        transactionJson["amount"] = transaction.amount;
        transactionsJson.push_back(transactionJson);
    }

    blockJson["transactions"] = transactionsJson;
    return blockJson;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    int numBlocks = 10; // Change this to the number of blocks you want to generate
    Blockchain blockchain;

    // Create an HTTP server instance
    httplib::Server server;

    // Define an endpoint to mine a block
    server.Post("/mine", [&blockchain](const httplib::Request& req, httplib::Response& res) {
        // Implement logic to mine a block and add it to the blockchain
        int numTransactions = rand() % 5 + 1;
        vector<Transaction> transactions;

        for (int j = 0; j < numTransactions; j++) {
            transactions.push_back(generateRandomTransaction());
        }

        blockchain.mineBlock(transactions);

        // Respond with a JSON message indicating success
        json responseJson;
        responseJson["message"] = "Block mined successfully.";
        res.set_content(responseJson.dump(), "application/json");
    });

    // Define an endpoint to retrieve the blockchain data
    server.Get("/blockchain", [&blockchain](const httplib::Request& req, httplib::Response& res) {
        // Serialize the blockchain to JSON
        json blockchainJson;
        for ( Block& block : blockchain.getChain()) {
            blockchainJson.push_back(blockToJson(block));
        }

        res.set_content(blockchainJson.dump(), "application/json");
    });

    // Define an endpoint to check the blockchain validity
    server.Get("/validity", [&blockchain](const httplib::Request& req, httplib::Response& res) {
        // Implement logic to check the validity of the blockchain
        bool isValid = blockchain.isChainValid();

        // Respond with a JSON message indicating validity
        json responseJson;
        responseJson["validity"] = isValid;
        res.set_content(responseJson.dump(), "application/json");
    });

    // Start the HTTP server on port 8080
    server.listen("0.0.0.0", 8080);

    return 0;
}
