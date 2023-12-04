#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H

#include <vector>
#include <string>

class MerkleTree
{
public:
    MerkleTree(std::vector<std::string> transactions);
    std::string getMerkleRoot();

private:
    std::vector<std::string> merkleTree;
    std::string calculateMerkleRoot(std::vector<std::string> merkleTree);
};

#endif // MERKLE_TREE_H