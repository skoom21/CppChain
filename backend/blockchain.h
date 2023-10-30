#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"

class Blockchain {
public:
    Blockchain();
    ~Blockchain();

    void addBlock(const std::string& data);
    bool isValid() const;
    void display() const;
    const std::string getJsonRepresentation() const;

private:
    Block* genesisBlock;
    Block* lastBlock;
};

#endif // BLOCKCHAIN_H
