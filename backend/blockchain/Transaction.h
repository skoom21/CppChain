#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

struct Transaction {
    std::string sender;
    std::string receiver;
    double amount;

    Transaction(const std::string& sender, const std::string& receiver, double amount);
    // Add other transaction-related methods if needed
};

#endif // TRANSACTION_H
