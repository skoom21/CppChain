#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain(); // Constructor
    void mineBlock(std::vector<Transaction> transactions);
    Block createNewBlock(std::vector<Transaction> transactions);
    bool isChainValid();
    vector<Block> getChain();

    // Other utility functions like getting the last block, etc.
private:
    std::vector<Block> chain;
};

#endif // BLOCKCHAIN_H
