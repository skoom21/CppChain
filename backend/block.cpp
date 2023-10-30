#include "block.h"
#include <sstream>
#include <openssl/sha.h>

Block::Block(int index, const std::string& data, const std::string& previousHash, Block* previousBlock)
    : index(index), data(data), previousHash(previousHash), previous(previousBlock) {
    timestamp = time(nullptr);
    calculateHash();
    next = nullptr;
    if (previousBlock) {
        previousBlock->setNext(this);
    }
}


int Block::getIndex() const {
    return index;
}

const std::string& Block::getPreviousHash() const {
    return previousHash;
}

const std::string& Block::getHash() const {
    return hash;
}

const std::string& Block::getData() const {
    return data;
}

time_t Block::getTimestamp() const {
    return timestamp;
}

Block* Block::getNext() const {
    return next;
}

Block* Block::getPrevious() const {
    return previous;
}

void Block::setNext(Block* block) {
    next = block;
}

void Block::setPrevious(Block* block) {
    previous = block;
}

std::string Block::calculateHash() const {
    std::string dataToHash = std::to_string(blockNumber) + data + previousHash;
    hash = dataToHash;
    return hash;
}
