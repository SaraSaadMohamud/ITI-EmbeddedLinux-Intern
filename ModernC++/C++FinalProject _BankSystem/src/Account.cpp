/**
 * @file Account.cpp
 * @brief Implements the Account class functionality.
 *
 * This file contains the implementation of the Account class methods,
 * including account creation, destruction, balance management,
 * deposit operations, and account tracking.
 *
 * The Account class provides common behavior for all derived account
 * types and maintains a static counter for active accounts.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
*/

#include "Account.hpp"
#include <iostream>
#include <stdexcept>

/**
 * @brief Initializes the total number of created accounts.
 *
 * This static variable keeps track of the number of currently active
 * Account objects.
*/
unsigned int Account::account_number_  = 0;

/**
 * @brief Initializes the account ID generator.
 *
 * Each new account receives a unique incremented ID.
*/
unsigned int Account::next_account_id_ = 0;

/**
 * @brief Maximum allowed deposit amount per transaction.
*/
constexpr unsigned int max_amount_at_one_time = 10000;

Account::Account(const std::string &name,double balance): 
        owner_name_(name), balance_(0.0)
{
    deposit(balance);
    ++account_number_;
    account_id_ = ++next_account_id_;
}

Account::~Account()
{
    --account_number_;
}

const std::string &Account::getAccountOwnerName() const
{
    return owner_name_;
}

unsigned int Account::getAccountID() const
{
    return account_id_;
}

double Account::getAccountBalance() const
{
    return balance_;
}

void Account::setAccountOwnerName(const std::string &name)
{
    owner_name_ = name;
}

void Account::deposit(double amount)
{
    if(amount <= 0)
    {
        throw std::invalid_argument("Deposit amount must be greater than zero.");
    }

    if (amount > max_amount_at_one_time)
    {
        throw std::invalid_argument("Deposit exceeds maximum allowed amount.");
    }

    balance_ += amount;
}

unsigned int Account::getNumberOfAccounts()
{
    return account_number_;
}

void Account::displayAccountInfo() const 
{
    std::cout<<"Name        : "<<owner_name_    <<std::endl;
    std::cout<<"ID          : "<<account_id_    <<std::endl;
    std::cout<<"Balance     : "<<balance_       <<std::endl;
}