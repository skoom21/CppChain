#include "Blockchain.h"
#include "MerkleTree.h" // Include MerkleTree

Blockchain::Blockchain() {
    // Initialize the blockchain with a genesis block
    Block genesisBlock;
    chain.push_back(genesisBlock);
}

void Blockchain::mineBlock(const std::vector<Transaction>& transactions) {
    // Create a new block with transactions
    Block newBlock = createNewBlock(transactions);

    // Add the block to the blockchain
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid() const {
    // Implement chain validation logic here
    // Check block hashes, previousHash references, PoW, etc.
    // Ensure that Merkle root in each block matches the transactions
    // You may also need to verify the chain against consensus rules
    return true; // Return true for simplicity
}

Block Blockchain::createNewBlock(const std::vector<Transaction>& transactions) {
    // Create a new block with transactions
    Block newBlock;

    // Calculate the Merkle root for the transactions
    std::vector<std::string> transactionData;
    for (const Transaction& transaction : transactions) {
        // Convert each transaction to a string (you may need to define a format)
        // For example: "sender:receiver:amount"
        std::string transactionStr = transaction.sender + ":" + transaction.receiver + ":" + std::to_string(transaction.amount);
        transactionData.push_back(transactionStr);
    }

    MerkleTree merkleTree(transactionData); // Create a Merkle tree
    std::string merkleRoot = merkleTree.getMerkleRoot(); // Get the Merkle root

    // Set the Merkle root in the new block
    newBlock.setMerkleRoot(merkleRoot);

    // Implement other block creation logic, including mining, nonce calculation, etc.

    return newBlock;
}
