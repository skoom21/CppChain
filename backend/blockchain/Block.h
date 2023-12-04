#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "Transaction.h"
#include <ctime>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

using namespace std;

class Block {
public:
    Block();
    Block(int index, const string& previousHash, const vector<Transaction>& transactions,
          const string& merkleRoot, const string& timestamp, const string& nonce, const string& hash);

    string calculateHash() const;
    bool isHashValid() const;
    int getIndex() const;
    string getPreviousHash() const;
    vector<Transaction> getTransactions() const;
    string getMerkleRoot() const;
    string getTimestamp() const;
    string getNonce() const;
    string getHash() const;

    void setMerkleRoot(const string& merkleRoot);

private:
    int index;
    string previousHash;
    vector<Transaction> transactions;
    string merkleRoot;
    string timestamp;
    string nonce;
    string hash;
};

#endif // BLOCK_H
