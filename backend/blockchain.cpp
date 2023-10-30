#include "blockchain.h"
#include <iostream>
#include <nlohmann/json.hpp>

Blockchain::Blockchain() {
    genesisBlock = new Block(0, "Genesis Block", "0", nullptr);
    lastBlock = genesisBlock;
}

Blockchain::~Blockchain() {
    for (Block* block : blocks) {
        delete block;
    }
}

void Blockchain::addBlock(const std::string& data) {
    Block* newBlock = new Block(lastBlock->getIndex() + 1, data, lastBlock->getHash(), lastBlock);
    lastBlock = newBlock;
}

bool Blockchain::isValid() const {
    for (size_t i = 1; i < blocks.size(); i++) {
        Block* currentBlock = blocks[i];
        Block* previousBlock = blocks[i - 1];

        if (currentBlock->getHash() != currentBlock->calculateHash()) {
            return false;
        }

        if (currentBlock->getPreviousHash() != previousBlock->getHash()) {
            return false;
        }
    }

    return true;
}

void Blockchain::display() const {
    for (const Block* block : blocks) {
        std::cout << "Block #" << block->getIndex() << std::endl;
        std::cout << "Timestamp: " << asctime(localtime(&block->getTimestamp()));
        std::cout << "Data: " << block->getData() << std::endl;
        std::cout << "Previous Hash: " << block->getPreviousHash() << std::endl;
        std::cout << "Hash: " << block->getHash() << std::endl;
        std::cout << "-------------------" << std::endl;
    }
}

const std::string Blockchain::getJsonRepresentation() const {
    nlohmann::json blockchainJson;
    for (const Block* block : blocks) {
        nlohmann::json blockJson;
        blockJson["index"] = block->getIndex();
        blockJson["timestamp"] = block->getTimestamp();
        blockJson["data"] = block->getData();
        blockJson["previousHash"] = block->getPreviousHash();
        blockJson["hash"] = block->getHash();
        blockchainJson.push_back(blockJson);
    }
    return blockchainJson.dump();
}
