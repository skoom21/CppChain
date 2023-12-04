#include <iostream>
#include "Blockchain.h"

int main() {
    Blockchain blockchain;

    // Create some transactions
    Transaction transaction1("Mary", "John", 100);
    Transaction transaction2("Bob", "Alice", 50);
    Transaction transaction3("Alice", "John", 75);
    Transaction transaction4("John", "Alice", 10);
    Transaction transaction5("Alice", "Bob", 5);

    // Mine blocks
    blockchain.mineBlock({transaction1, transaction2});
    blockchain.mineBlock({transaction3, transaction4});
    blockchain.mineBlock({transaction5});

    // Print out the blockchain
    blockchain.printChain();

    // Check validity
    cout << "Is chain valid? " << blockchain.isChainValid() << endl;

    // Now let's tamper with the data
    blockchain.getChain()[1].getTransactions()[0].setAmount(1000);

    // Check validity again
    cout << "Is chain valid? " << blockchain.isChainValid() << endl;

    return 0;

}

