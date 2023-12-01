#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H

#include <vector>
#include <string>

class MerkleTree {
public:
    MerkleTree(const std::vector<std::string>& transactions);
    std::string getMerkleRoot() const;
private:
    std::vector<std::string> merkleTree;
    std::string calculateMerkleRoot(const std::vector<std::string>& merkleTree);
};

#endif // MERKLE_TREE_H
