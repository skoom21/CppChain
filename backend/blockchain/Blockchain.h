#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();
    void mineBlock(const vector<Transaction>& transactions);
    bool isChainValid() const;
    Block createNewBlock(const vector<Transaction>& transactions);
    // Other utility functions like getting the last block, etc.
private:
    vector<Block> chain;
};

#endif // BLOCKCHAIN_H
