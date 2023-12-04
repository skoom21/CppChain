#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H

#include <vector>
#include <string>

using namespace std;

class MerkleTree {
public:
    MerkleTree(const vector<string>& transactions);
    string getMerkleRoot() const;
private:
    vector<string> merkleTree;
    string calculateMerkleRoot(const vector<string>& merkleTree);
};

#endif // MERKLE_TREE_H
