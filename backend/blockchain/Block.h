#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include "Transaction.h"

using namespace std;

class Block
{
public:
    Block(); // Default constructor
    Block(int size, string prevhash, vector<Transaction> transactions);

    // Additional constructor and member functions go here

private:
    int index;
    string previousHash;
    vector<Transaction> transactions;
    string merkleRoot;
    string timestamp;
    string nonce;
    string hash;

public:
    string calculateHash();
    bool isHashValid();
    int getIndex();
    string getPreviousHash();
    vector<Transaction> getTransactions();
    string getMerkleRoot();
    string getTimestamp();
    string getNonce();
    string getHash();
    void setMerkleRoot(string merkleRoot);
    void printBlock(Block block);
};

#endif // BLOCK_H
