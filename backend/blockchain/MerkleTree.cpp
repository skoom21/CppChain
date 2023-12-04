#include "MerkleTree.h"
#include <openssl/sha.h>

MerkleTree::MerkleTree(std::vector<std::string> transactions)
{
    // Initialize the Merkle tree with transactions
    merkleTree = transactions;

    // Build the Merkle tree by repeatedly hashing pairs of nodes
    while (merkleTree.size() > 1)
    {
        std::vector<std::string> newLevel;

        // Hash pairs of nodes
        for (size_t i = 0; i < merkleTree.size(); i += 2)
        {
            std::string combinedHash;
            combinedHash = merkleTree[i];

            if (i + 1 < merkleTree.size())
            {
                combinedHash += merkleTree[i + 1];
            }

            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256(reinterpret_cast<const unsigned char *>(combinedHash.c_str()), combinedHash.length(), hash);

            // Convert the hash to a hexadecimal string
            std::string hashedNode;
            for (int j = 0; j < SHA256_DIGEST_LENGTH; j++)
            {
                char hex[3];
                sprintf(hex, "%02x", hash[j]);
                hashedNode += hex;
            }

            newLevel.push_back(hashedNode);
        }

        merkleTree = newLevel;
    }
}

std::string MerkleTree::getMerkleRoot()
{
    // Return the Merkle root (the root of the tree)
    if (!merkleTree.empty())
    {
        return merkleTree[0];
    }
    else
    {
        return ""; // Handle this case as needed
    }
}

std::string MerkleTree::calculateMerkleRoot(std::vector<std::string> merkleTree)
{
    // Build the Merkle tree by repeatedly hashing pairs of nodes
    while (merkleTree.size() > 1)
    {
        std::vector<std::string> newLevel;

        // Hash pairs of nodes
        for (size_t i = 0; i < merkleTree.size(); i += 2)
        {
            std::string combinedHash;
            combinedHash = merkleTree[i];

            if (i + 1 < merkleTree.size())
            {
                combinedHash += merkleTree[i + 1];
            }

            unsigned char hash[SHA256_DIGEST_LENGTH];
            SHA256(reinterpret_cast<const unsigned char *>(combinedHash.c_str()), combinedHash.length(), hash);

            // Convert the hash to a hexadecimal string
            std::string hashedNode;
            for (int j = 0; j < SHA256_DIGEST_LENGTH; j++)
            {
                char hex[3];
                sprintf(hex, "%02x", hash[j]);
                hashedNode += hex;
            }

            newLevel.push_back(hashedNode);
        }

        merkleTree = newLevel;
    }

    // Return the Merkle root (the root of the tree)
    if (!merkleTree.empty())
    {
        return merkleTree[0];
    }
    else
    {
        return ""; // Handle this case as needed
    }
}
