#include "Blockchain.h"
#include "MerkleTree.h"

Blockchain::Blockchain()
{
    // Initialize the blockchain with a genesis block
    Block genesisBlock;
    chain.push_back(genesisBlock);
}

void Blockchain::mineBlock(std::vector<Transaction> transactions)
{
    // Create a new block with transactions
    Block newBlock = createNewBlock(transactions);

    // Add the block to the blockchain
    chain.push_back(newBlock);
    newBlock.printBlock(newBlock);
}

bool Blockchain::isChainValid()
{
    // Check block hashes, previousHash references, PoW, etc.
    // Ensure that Merkle root in each block matches the transactions
    // Verify the chain against consensus rules

    // Iterate through each block in the chain
    for (int i = 1; i < chain.size(); i++)
    {
        Block &currentBlock = chain[i];
        Block &previousBlock = chain[i - 1];

        // Check if the current block's previousHash matches the hash of the previous block
        if (currentBlock.getPreviousHash() != previousBlock.calculateHash())
        {
            return false;
        }

        // Check if the current block's hash is valid
        if (!currentBlock.isHashValid())
        {
            return false;
        }

        // Check if the Merkle root in the current block matches the transactions
        std::vector<std::string> transactionData;
        for (Transaction &transaction : currentBlock.getTransactions())
        {
            std::string transactionStr = transaction.sender + ":" + transaction.receiver + ":" + std::to_string(transaction.amount);
            transactionData.push_back(transactionStr);
        }

        MerkleTree merkleTree(transactionData);
        std::string calculatedMerkleRoot = merkleTree.getMerkleRoot();
        if (currentBlock.getMerkleRoot() != calculatedMerkleRoot)
        {
            return false;
        }
    }

    return true;
}

Block Blockchain::createNewBlock(std::vector<Transaction> transactions)
{
    // Create a new block with transactions
    Block newBlock(chain.size(), chain.back().getHash(), transactions);

    // Calculate the Merkle root for the transactions
    std::vector<std::string> transactionData;
    for (Transaction &transaction : transactions)
    {
        // Convert each transaction to a string
        std::string transactionStr = transaction.sender + ":" + transaction.receiver + ":" + std::to_string(transaction.amount);
        transactionData.push_back(transactionStr);
    }

    MerkleTree merkleTree(transactionData);
    std::string merkleRoot = merkleTree.getMerkleRoot();
    newBlock.setMerkleRoot(merkleRoot);

    // Implement other block creation logic, including mining, nonce calculation, etc.

    return newBlock;
}

vector<Block> Blockchain::getChain()
{
    return chain;
}