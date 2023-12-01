#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "Transaction.h"

class Block {
public:
    Block();
    Block(int index, const std::string& previousHash, const std::vector<Transaction>& transactions,
          const std::string& merkleRoot, const std::string& timestamp, const std::string& nonce, const std::string& hash);

    int getIndex() const;
    std::string getPreviousHash() const;
    std::vector<Transaction> getTransactions() const;
    std::string getMerkleRoot() const;
    std::string getTimestamp() const;
    std::string getNonce() const;
    std::string getHash() const;

    void setMerkleRoot(const std::string& merkleRoot);

private:
    int index;
    std::string previousHash;
    std::vector<Transaction> transactions;
    std::string merkleRoot;
    std::string timestamp;
    std::string nonce;
    std::string hash;
};

#endif // BLOCK_H
