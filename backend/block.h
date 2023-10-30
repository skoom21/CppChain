#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>

class Block {
public:
    Block(int index, const std::string& data, const std::string& previousHash, Block* previousBlock);

    int getIndex() const;
    const std::string& getPreviousHash() const;
    const std::string& getHash() const;
    const std::string& getData() const;
    time_t getTimestamp() const;
    const std::string& calculateHash();

    Block* getNext() const;
    Block* getPrevious() const;
    void setNext(Block* block);
    void setPrevious(Block* block);

private:
    int index;
    std::string previousHash;
    std::string data;
    time_t timestamp;
    std::string hash;
    Block* next;
    Block* previous;
};
