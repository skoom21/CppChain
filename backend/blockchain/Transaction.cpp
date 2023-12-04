#include "Transaction.h"

Transaction::Transaction(std::string sender, std::string receiver, double amount)
    : sender(sender), receiver(receiver), amount(amount)
{
    // Constructor initializes transaction details
}

void Transaction::printTransaction()
{
    // Implement this function to print transaction details
    std::cout << "Sender: " << sender << std::endl;
    std::cout << "Receiver: " << receiver << std::endl;
    std::cout << "Amount: " << amount << std::endl;
}
