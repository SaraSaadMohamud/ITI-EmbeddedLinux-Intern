#ifndef _SAVINGS_ACCOUNT_HPP_
#define _SAVINGS_ACCOUNT_HPP_

/**
 * @file SavingsAccount.hpp
 * @brief Defines the SavingsAccount class.
 *
 * This file contains the declaration of the SavingsAccount class,
 * which extends the Account class by providing interest accumulation
 * and savings-specific withdrawal behavior.
 *
 * Savings accounts support:
 * - Interest rate management
 * - Interest application to the account balance
 * - Savings account-specific withdrawal rules
 * - Tracking the number of active savings accounts
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */

#include "Account.hpp"

/**
 * @class SavingsAccount
 * @brief Represents a savings bank account.
 *
 * The SavingsAccount class inherits from Account and adds an
 * interest rate that can be applied to increase the account balance.
 *
 * It overrides the withdrawal and account information display
 * functions to implement savings account behavior.
 */
class SavingsAccount : public Account
{
    public:
    /**
     * @brief Constructs a new SavingsAccount object.
     *
     * Initializes the account owner, initial balance,
     * and annual interest rate.
     *
     * @param name Account owner's name.
     * @param balance Initial account balance.
     * @param interest_rate Interest rate applied to the account.
    */
    SavingsAccount(const std::string &name,
            double balance,
            const std::string &password,
            double interest_rate,
            unsigned int account_id = 0);

    /**
     * @brief Destroys the SavingsAccount object.
    */
    ~SavingsAccount() override;

    /**
     * @brief Displays complete savings account information.
     *
     * Overrides the base Account implementation to include
     * the account's interest rate.
    */
    void displayAccountInfo() const override;

    /**
     * @brief Withdraws money from the savings account.
     *
     * Implements the withdrawal rules specific to a savings account.
     *
     * @param amount Amount to withdraw.
    */
    void withdraw(double amount) override;
    
    /**
     * @brief Gets the account's interest rate.
     *
     * @return Current interest rate.
    */
    double getInterestRate() const;

    /**
     * @brief Applies interest to the current account balance.
     *
     * Calculates the earned interest based on the current
     * balance and interest rate, then updates the balance.
    */
    void applyInterest();

    /**
     * @brief Gets the number of active savings accounts.
     *
     * @return Number of existing SavingsAccount objects.
    */
    static unsigned int getSavingsAccountCount();

    private:
    /**
     * @brief Interest rate associated with the account.
    */
    double interest_rate_;


    /**
     * @brief Tracks the number of active savings accounts.
    */
    static unsigned int savings_account_count_;
};
#endif /* _SAVINGS_ACCOUNT_HPP_ */