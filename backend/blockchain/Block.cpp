#include "Block.h"
#include <string>
#include <ctime>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

Block::Block()
{
    // Initialize default values for a new block
    index = 0;
    previousHash = "";
    merkleRoot = "";
    timestamp = to_string(time(0));
    nonce = "";
    hash = "";
}

Block::Block(int size, string prevhash, vector<Transaction> transactions)
{
    // Implement this constructor to initialize a new block with the provided data
    // You should set the index, previousHash, transactions, and calculate the hash

    // Example:
    index = size;
    previousHash = prevhash;
    this->transactions = transactions;
    timestamp = to_string(time(0));
    nonce = "0";
    hash = calculateHash();
}

string Block::calculateHash()
{
    // Implement this function to calculate and return the hash of the block

    // Example:
    string dataToHash = to_string(index) + previousHash + merkleRoot + timestamp + nonce;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, dataToHash.c_str(), dataToHash.length());
    SHA256_Final(hash, &sha256);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }

    return ss.str();
}

bool Block::isHashValid()
{
    return calculateHash() == hash;
}

// Implement the remaining member functions as needed

void Block::printBlock(Block block) {
   // Implement this function to print block details
   // Example:
   cout << "Block Information:" << endl;
   cout << "Index: " << block.getIndex() << endl;
   cout << "Previous Hash: " << block.getPreviousHash() << endl;
   // Print other block details
}

int Block::getIndex() {
   return index;
}

string Block::getPreviousHash() {
   return previousHash;
}

vector<Transaction> Block::getTransactions() {
   return transactions;
}

string Block::getMerkleRoot() {
   return merkleRoot;
}

string Block::getTimestamp() {
   return timestamp;
}

string Block::getNonce() {
   return nonce;
}


string Block::getHash() {
   return hash;
}

void Block::setMerkleRoot(string merkleRoot) {
   this->merkleRoot = merkleRoot;
}

