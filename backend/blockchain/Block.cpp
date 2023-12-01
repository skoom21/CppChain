#include "Block.h"

Block::Block() {
    // Initialize block properties here
}

Block::Block(int index, const std::string& previousHash, const std::vector<Transaction>& transactions,
             const std::string& merkleRoot, const std::string& timestamp, const std::string& nonce, const std::string& hash)
    : index(index), previousHash(previousHash), transactions(transactions),
      merkleRoot(merkleRoot), timestamp(timestamp), nonce(nonce), hash(hash) {
    // Implement constructor logic if needed
}

int Block::getIndex() const {
    return index;
}

std::string Block::getPreviousHash() const {
    return previousHash;
}

std::vector<Transaction> Block::getTransactions() const {
    return transactions;
}

std::string Block::getMerkleRoot() const {
    return merkleRoot;
}

std::string Block::getTimestamp() const {
    return timestamp;
}

std::string Block::getNonce() const {
    return nonce;
}

std::string Block::getHash() const {
    return hash;
}

void Block::setMerkleRoot(const std::string& merkleRoot) {
    this->merkleRoot = merkleRoot;
}
