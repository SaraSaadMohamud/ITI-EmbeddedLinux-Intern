/**
 * @file Bank.cpp
 * @brief Implements the Bank class.
 *
 * This file contains the implementation of the Bank class, which manages
 * a collection of bank accounts. It provides functionality for adding,
 * removing, searching, depositing, withdrawing, transferring funds,
 * and displaying account information.
 *
 * The Bank class owns all Account objects stored in its internal
 * collection and is responsible for releasing their allocated memory.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */

#include "Bank.hpp"
#include <iostream>
#include <stdexcept>

Bank::Bank(const std::string &bank_name) : bank_name_(bank_name)
{}

Bank::~Bank()
{
    for(Account* account : accounts_)
    {
        delete account;
    }
}

const std::string &Bank::getBankName() const
{
    return bank_name_;
}

void Bank::addAccount(Account* new_acc)
{
    if(new_acc == nullptr)
    {
        throw std::invalid_argument("Invalid input: null account pointer.");
    }
    if (findAccount(new_acc->getAccountID()) != nullptr)
    {
        throw std::invalid_argument("Account has already been added.");
    }
    accounts_.push_back(new_acc);
}

void Bank::removeAccount(unsigned int account_id)
{
    Account* copy = findAccount(account_id);

   if(copy == nullptr)
   {
    throw std::invalid_argument("Bank doesn't have this account.");
   }

   
   for(auto iterator = accounts_.begin() ; iterator != accounts_.end() ; ++iterator)
   {
    if ((*iterator )== copy)
    {
        delete (*iterator);
        accounts_.erase(iterator);
        return;
    }
   } 
}

Account* Bank::findAccount(unsigned int account_id) const
{
    for(auto account_ptr : accounts_)
    {
        if((account_ptr->getAccountID()) == account_id)
        {
            return(account_ptr);
        }
    }

    return(nullptr);
}

void Bank::deposit(double amount, unsigned int account_id)
{
    Account* target_account = findAccount(account_id);
    if(target_account == nullptr)
    {
        throw std::invalid_argument("Account not found.");
    }
    target_account->deposit(amount);

    Transaction copy_transaction(Transaction::TransactionType::Deposit,amount,0,account_id);
    addTransaction(copy_transaction);
}

void Bank::withdraw(double amount, unsigned int account_id)
{
    Account* target_account = findAccount(account_id);
    if(target_account == nullptr)
    {
        throw std::invalid_argument("Account not found.");
    }
    target_account->withdraw(amount);

    Transaction copy_transaction(Transaction::TransactionType::Withdraw,amount,account_id, 0);
    addTransaction(copy_transaction);
}

void Bank::transfer(double amount,
                  unsigned int account1_id,
                  unsigned int account2_id)
{
    Account* sender_account = findAccount(account1_id);
    Account* receiver_account = findAccount(account2_id);

    if(!sender_account)
    {
        throw std::invalid_argument("Sender Account not found.");
    }
    if (!receiver_account)
    {
        throw std::invalid_argument("Receiver Account not found.");
    }

    if(sender_account == receiver_account)
    {
        throw std::invalid_argument("You can't Transfer to the same account.");
    }

    sender_account->withdraw(amount);
    receiver_account->deposit(amount);

    Transaction copy_transaction(Transaction::TransactionType::Transfer,amount,account1_id,account2_id);
    addTransaction(copy_transaction);
}

unsigned int Bank::getAccountsCount() const
{
    return accounts_.size();
}

void Bank::addTransaction(const Transaction & obj)
{
    transactions_.push_back(obj);
}

void Bank::displayAccounts() const
{
    if(accounts_.empty())
    {
        std::cout<<"No Accounts Yes!\n";
        return;
    }

    for(auto iterator : accounts_)
    {
        iterator->displayAccountInfo();
    }
}

void Bank::displayBankAccountTransaction(unsigned int account_id) const
{
    Account * target_account = findAccount(account_id);
    bool flag = false;
    if(target_account == nullptr)
    {
        throw std::invalid_argument("Account not found.");
    }

    for(const auto &transaction : transactions_)
    {
        if( (transaction.getTransactionReceiverAccountID() == account_id)|| 
            (transaction.getTransactionSenderAccountID()   == account_id) )
        {
            transaction.displayTransaction();
            flag = true;
        }
    }

    if(!flag)
    {
        std::cout<<"No Transaction for this Account Yet!\n"<<std::endl;
    }
}
    

void Bank::displayTransactions() const
{
    if(transactions_.empty())
    {
        std::cout<<"No Transactions Yet!.\n";
        return;
    }
    for(const auto &count : transactions_)
    {
        count.displayTransaction();
    }
}

void Bank::displayTransactionStatistics() const
{
    unsigned int deposit = 0, withdraw = 0, transfer = 0;
     if(transactions_.empty())
    {
        std::cout<<"No Transactions Yet!.\n";
        return;
    }

    for(const auto &transaction : transactions_)
    {
        if(transaction.getTransactionType() == Transaction::TransactionType::Deposit)
        {
            ++deposit;
        }
        else if(transaction.getTransactionType() == Transaction::TransactionType::Withdraw)
        {
            ++withdraw;
        }
        else if(transaction.getTransactionType() == Transaction::TransactionType::Transfer)
        {
            ++transfer;
        }
    }

    std::cout << "------------ Transaction Statistics ------------\n";
    std::cout<<"Total Deposit       : "<<deposit                <<std::endl;
    std::cout<<"Total Withdraw      : "<<withdraw               <<std::endl;
    std::cout<<"Total Transfer      : "<<transfer               <<std::endl;
    std::cout<<"Total Transaction   : "<<transactions_.size()   <<std::endl;
}

void Bank::displayBankInfo()const 
{
    std::cout<<"----------- Bank Information -------------\n";
    std::cout<<"Name            : "<<bank_name_             <<std::endl;
    std::cout<<"Accounts        : "<<accounts_.size()       <<std::endl;
    std::cout<<"Transactions    : "<<transactions_.size()   <<std::endl;
}