/**
 * @file Transaction.cpp
 * @brief Implements the Transaction class.
 *
 * This file contains the implementation of the Transaction class,
 * which represents banking transactions such as deposits,
 * withdrawals, and transfers. Each transaction is assigned
 * a unique identifier and records the transaction date and
 * time at the moment of its creation.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */

#include "Transaction.hpp"
#include <chrono> 
#include <format>
#include <stdexcept>
#include <iostream>

/**
 * @brief Initializes the number of active transactions.
*/
unsigned int Transaction::transaction_count_     = 0;

/**
 * @brief Initializes the transaction ID generator.
 *
 * Each new transaction receives a unique incrementing ID.
 */
unsigned int Transaction::next_transaction_id_   = 0;


Transaction::Transaction(TransactionType transaction_type,
            double amount,
            unsigned int sender_account_id,
            unsigned int receiver_account_id) : transaction_type_(transaction_type), 
            transaction_id_(++next_transaction_id_),
            amount_(amount),
            sender_account_id_(sender_account_id),
            receiver_account_id_(receiver_account_id)
{
    if(amount <= 0)
    {
        throw std::invalid_argument("Transaction failed: invalid amount.");
    }
    
    ++transaction_count_;

    auto now = std::chrono::system_clock::now();
    transaction_date_ = std::format("{:%d/%m/%Y}", now);
    transaction_time_ = std::format("{:%H:%M:%S}", now);

}

const std::string &Transaction::getTransactionDate() const
{
    return transaction_date_;
}

const std::string &Transaction::getTransactionTime() const
{
    return transaction_time_;
}

unsigned int Transaction::getTransactionID() const
{
    return transaction_id_;
}

Transaction::TransactionType Transaction::getTransactionType() const
{
    return transaction_type_;
}

unsigned int Transaction::getTransactionSenderAccountID() const
{
    return sender_account_id_;
}

unsigned int Transaction::getTransactionReceiverAccountID() const
{
    return receiver_account_id_;
}

double Transaction::getTransactionAmount() const
{
    return amount_;
}

void Transaction::displayTransaction() const
{
    std::cout<<"===========================================\n";
    switch(transaction_type_)
    {
        case TransactionType::Deposit :
            std::cout<<"Transaction Type    : Deposit"                  <<std::endl;
            std::cout<<"Receiver Account ID : "<<receiver_account_id_   <<std::endl;
            break;
        case TransactionType::Withdraw:
            std::cout<<"Transaction Type    : Withdraw"                 <<std::endl;
            std::cout<<"Sender Account ID   : "<<sender_account_id_     <<std::endl;
            break;
        case TransactionType::Transfer:
            std::cout<<"Transaction Type    : Transfer"                 <<std::endl;
            std::cout<<"Sender Account ID   : "<<sender_account_id_     <<std::endl;
            std::cout<<"Receiver Account ID : "<<receiver_account_id_   <<std::endl;
            break;
    }
    std::cout<<"Transaction ID      : "<<transaction_id_        <<std::endl;
    std::cout<<"Transaction Amount  : "<<amount_                <<std::endl;
    std::cout<<"Transaction Date    : "<<transaction_date_      <<std::endl;
    std::cout<<"Transaction Time    : "<<transaction_time_      <<std::endl;
    std::cout<<"===========================================\n";
}

unsigned int Transaction::getTransactionCount()
{
    return transaction_count_;
}