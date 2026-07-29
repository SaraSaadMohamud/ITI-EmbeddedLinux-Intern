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
    
}

void Bank::withdraw(double amount, unsigned int account_id)
{
    Account* target_account = findAccount(account_id);
    if(target_account == nullptr)
    {
        throw std::invalid_argument("Account not found.");
    }

    target_account->withdraw(amount);
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
}

unsigned int Bank::getAccountsCount() const
{
    return accounts_.size();
}

void Bank::displayAccounts() const
{
    for(auto iterator : accounts_)
    {
        iterator->displayAccountInfo();
    }
}