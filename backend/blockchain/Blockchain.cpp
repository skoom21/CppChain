#include "Blockchain.h"
#include "MerkleTree.h" // Include MerkleTree

Blockchain::Blockchain() {
    // Initialize the blockchain with a genesis block
    Block genesisBlock;
    chain.push_back(genesisBlock);
}

void Blockchain::mineBlock(const vector<Transaction>& transactions) {
    // Create a new block with transactions
    Block newBlock = createNewBlock(transactions);

    // Add the block to the blockchain
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid() const {
    // Check block hashes, previousHash references, PoW, etc.
    // Ensure that Merkle root in each block matches the transactions
    // Verify the chain against consensus rules

    // Iterate through each block in the chain
    for (int i = 1; i < chain.size(); i++) {
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];

        // Check if the current block's previousHash matches the hash of the previous block
        if (currentBlock.getPreviousHash() != previousBlock.calculateHash()) {
            return false;
        }

        // Check if the current block's hash is valid
        if (!currentBlock.isHashValid()) {
            return false;
        }

        // Check if the Merkle root in the current block matches the transactions
        vector<string> transactionData;
        for (const Transaction& transaction : currentBlock.getTransactions()) {
            string transactionStr = transaction.sender + ":" + transaction.receiver + ":" + to_string(transaction.amount);
            transactionData.push_back(transactionStr);
        }

        MerkleTree merkleTree(transactionData);
        string calculatedMerkleRoot = merkleTree.getMerkleRoot();
        if (currentBlock.getMerkleRoot() != calculatedMerkleRoot) {
            return false;
        }

        // Implement other chain validation logic, including PoW, consensus rules, etc.
    }

    return true;
}
}

Block Blockchain::createNewBlock(const vector<Transaction>& transactions) {
    // Create a new block with transactions
    Block newBlock;

    // Calculate the Merkle root for the transactions
    vector<string> transactionData;
    for (const Transaction& transaction : transactions) {
        // Convert each transaction to a string (you may need to define a format)
        // For example: "sender:receiver:amount"
        string transactionStr = transaction.sender + ":" + transaction.receiver + ":" + to_string(transaction.amount);
        transactionData.push_back(transactionStr);
    }

    MerkleTree merkleTree(transactionData); // Create a Merkle tree
    string merkleRoot = merkleTree.getMerkleRoot(); // Get the Merkle root

    // Set the Merkle root in the new block
    newBlock.setMerkleRoot(merkleRoot);

    // Implement other block creation logic, including mining, nonce calculation, etc.

    return newBlock;
}
