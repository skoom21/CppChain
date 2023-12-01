#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain();
    void mineBlock(const std::vector<Transaction>& transactions);
    bool isChainValid() const;
    Block createNewBlock(const std::vector<Transaction>& transactions);
    // Other utility functions like getting the last block, etc.
private:
    std::vector<Block> chain;
};

#endif // BLOCKCHAIN_H
