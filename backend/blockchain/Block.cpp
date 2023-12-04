#include "Block.h"

Block::Block()
{
    // Initialize block properties here
    
}

Block::Block(int index, const string &previousHash, const vector<Transaction> &transactions,
             const string &merkleRoot, const string &timestamp, const string &nonce, const string &hash)
    : index(index), previousHash(previousHash), transactions(transactions),
      merkleRoot(merkleRoot), timestamp(timestamp), nonce(nonce), hash(hash)
{
    // Implement constructor logic if needed
}


string Block::calculateHash() const
{
    string dataToHash = to_string(index) + previousHash + merkleRoot + timestamp + nonce;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, dataToHash.c_str(), dataToHash.length());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);
    }

    return ss.str();
}

bool Block::isHashValid() const
{
    return calculateHash() == hash;
}

int Block::getIndex() const
{
    return index;
}

string Block::getPreviousHash() const
{
    return previousHash;
}

vector<Transaction> Block::getTransactions() const
{
    return transactions;
}

string Block::getMerkleRoot() const
{
    return merkleRoot;
}

string Block::getTimestamp() const
{
    return timestamp;
}

string Block::getNonce() const
{
    return nonce;
}

string Block::getHash() const
{
    return hash;
}

void Block::setMerkleRoot(const string &merkleRoot)
{
    this->merkleRoot = merkleRoot;
}
