#include "MerkleTree.h"
#include <iostream>
#include <openssl/sha.h>

MerkleTree::MerkleTree(const vector<string>& transactions) {
    // Initialize the Merkle tree with transactions
    merkleTree = transactions;

    // Build the Merkle tree by repeatedly hashing pairs of nodes
    while (merkleTree.size() > 1) {
        vector<string> newLevel;

        // Hash pairs of nodes
        for (size_t i = 0; i < merkleTree.size(); i += 2) {
            string combinedHash;
            combinedHash = merkleTree[i];

            if (i + 1 < merkleTree.size()) {
                combinedHash += merkleTree[i + 1];
            }

            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256(reinterpret_cast<const unsigned char*>(combinedHash.c_str()), combinedHash.length(), hash);

            // Convert the hash to a hexadecimal string
            string hashedNode;
            for (int j = 0; j < SHA256_DIGEST_LENGTH; j++) {
                char hex[3];
                sprintf(hex, "%02x", hash[j]);
                hashedNode += hex;
            }

            newLevel.push_back(hashedNode);
        }

        merkleTree = newLevel;
    }
}

string MerkleTree::getMerkleRoot() const {
    // Return the Merkle root (the root of the tree)
    if (!merkleTree.empty()) {
        return merkleTree[0];
    } else {
        return ""; // Handle this case as needed
    }
}

string MerkleTree::calculateMerkleRoot(const vector<string>& merkleTree) {
    // Implement the calculation of the Merkle root here
    // Similar to what's done in the constructor
    // Return the Merkle root
}
