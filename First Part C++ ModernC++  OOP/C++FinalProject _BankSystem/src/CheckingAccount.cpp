/**
 * @file CheckingAccount.cpp
 * @brief Implements the CheckingAccount class.
 *
 * This file contains the implementation of the CheckingAccount class,
 * which extends the Account class by providing overdraft support,
 * checking account-specific withdrawal rules, and tracking the
 * number of active checking accounts.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */

#include "CheckingAccount.hpp"
#include<iostream>
#include <stdexcept>

/**
 * @brief Initializes the number of active checking accounts.
*/
unsigned int CheckingAccount::checking_account_count_ = 0;

CheckingAccount::CheckingAccount(const std::string &name,
        double balance,
        double overdraft_limit) : Account(name, balance), overdraft_limit_(0.0)
{
    if(overdraft_limit <= 0)
    {
        throw std::invalid_argument("Overdraft Limit must be greater than zero.");
    }
    
    overdraft_limit_ = overdraft_limit;
    ++checking_account_count_;
}

CheckingAccount::~CheckingAccount()
{
    --checking_account_count_;
}

void CheckingAccount::displayAccountInfo() const
{
    Account::displayAccountInfo();
    std::cout<<"Overdraft Limit :$ "<<overdraft_limit_<<std::endl;
}

void CheckingAccount::withdraw(double amount) 
{
    if(amount <= 0)
    {
        throw std::invalid_argument("Withdrawal amount must be greater than zero.");
    }

    if((balance_ + overdraft_limit_) < amount)
    {
        throw std::invalid_argument("Withdrawal exceeds the available balance and overdraft limit.");
    }

    balance_ -= amount;
}

double CheckingAccount::getOverdraftLimit() const
{
    return overdraft_limit_;
}

unsigned int CheckingAccount::getCheckingAccountCount()
{
    return checking_account_count_;
}