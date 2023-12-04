#include <iostream>
#include <vector>
#include <random>
#include "Blockchain.h" // Assuming you've included your blockchain classes

using namespace std; // Add this line to use the std namespace

// Function to generate random transactions
Transaction generateRandomTransaction() {
    string sender = "User" + to_string(rand() % 10); // Generate sender name
    string receiver = "User" + to_string(rand() % 10); // Generate receiver name
    double amount = (rand() % 100) + 1.0; // Generate a random amount between 1 and 100
    return Transaction(sender, receiver, amount);
}

// Function to simulate a blockchain with random blocks
void simulateBlockchain(int numBlocks) {
    Blockchain blockchain;

    for (int i = 0; i < numBlocks; i++) {
        int numTransactions = rand() % 5 + 1; // Generate 1 to 5 random transactions for each block
        vector<Transaction> transactions;

        for (int j = 0; j < numTransactions; j++) {
            transactions.push_back(generateRandomTransaction());
        }

        blockchain.mineBlock(transactions);

        printBlockAsJSON(blockchain.getChain().back()); // Print the last block as JSON
        // Print some information about the generated block
        cout << "Block " << i + 1 << " mined with " << numTransactions << " transactions." << endl;
    }

    // Check the validity of the blockchain
    if (blockchain.isChainValid()) {
        cout << "Blockchain is valid!" << endl;
    } else {
        cout << "Blockchain is NOT valid!" << endl;
    }
}

void printBlockAsJSON(const Block& block) {
    cout << "{" << endl;
    cout << "  \"index\": " << block.getIndex() << "," << endl;
    cout << "  \"previousHash\": \"" << block.getPreviousHash() << "\"," << endl;
    cout << "  \"merkleRoot\": \"" << block.getMerkleRoot() << "\"," << endl;
    cout << "  \"timestamp\": \"" << block.getTimestamp() << "\"," << endl;
    cout << "  \"nonce\": \"" << block.getNonce() << "\"," << endl;
    cout << "  \"hash\": \"" << block.getHash() << "\"" << endl;
    cout << "}" << endl;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    int numBlocks = 10; // Change this to the number of blocks you want to generate
    simulateBlockchain(numBlocks);

    return 0;
}
