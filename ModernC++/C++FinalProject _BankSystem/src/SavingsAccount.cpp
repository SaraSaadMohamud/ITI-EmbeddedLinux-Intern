/**
 * @file SavingsAccount.cpp
 * @brief Implements the SavingsAccount class.
 *
 * This file contains the implementation of the SavingsAccount class,
 * which extends the Account class by adding interest calculation,
 * savings-specific withdrawal rules, and tracking the number of
 * active savings accounts.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
*/

#include "SavingsAccount.hpp"
#include <iostream>
#include <stdexcept>

/**
 * @brief Maximum allowed interest rate for a savings account.
*/
constexpr double max_interest_rate = 20.0;

/**
 * @brief Minimum balance that must remain after a withdrawal.
*/
constexpr double min_balance_value = 1000.0;

/**
 * @brief Initializes the number of active savings accounts.
*/
unsigned int SavingsAccount::savings_account_count_ = 0;

/********************************************************************************************************************************************* */

SavingsAccount::SavingsAccount(const std::string &name,
        double balance,
        double interest_rate): Account(name,balance),interest_rate_(interest_rate)
{
    if(interest_rate_ <= 0)
    {
        throw std::invalid_argument("Interest rate amount must be greater than zero.");
    }

    if(interest_rate_ > max_interest_rate)
    {
        throw std::invalid_argument("Interest rate maximum allowed amount.");
    }
    ++savings_account_count_;
}

SavingsAccount::~SavingsAccount()
{
    --savings_account_count_;
}

void SavingsAccount::displayAccountInfo() const 
{
    Account::displayAccountInfo();
    std::cout<<"Interest Rate: "<<interest_rate_<<"%"<<std::endl;
}

void SavingsAccount::withdraw(double amount) 
{
    if(amount <= 0)
    {
        throw std::invalid_argument("Withdraw amount must be greater than zero.");
    }

    if((balance_ - amount ) < min_balance_value)
    {
        throw std::invalid_argument("Withdrawal would reduce the balance below the minimum required balance.");
    }

    balance_ -= amount;

}

double SavingsAccount::getInterestRate() const
{
    return interest_rate_;
}

void SavingsAccount::applyInterest()
{
    double interest_add_value;

    interest_add_value = (interest_rate_ / 100.0);
    balance_ += (balance_ * interest_add_value);
}


unsigned int SavingsAccount::getSavingsAccountCount()
{
    return savings_account_count_;
}