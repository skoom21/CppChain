#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

struct Transaction {
    std::string sender;
    std::string receiver;
    double amount;

    Transaction(std::string sender, std::string receiver, double amount);
    void printTransaction();
};

#endif // TRANSACTION_H
