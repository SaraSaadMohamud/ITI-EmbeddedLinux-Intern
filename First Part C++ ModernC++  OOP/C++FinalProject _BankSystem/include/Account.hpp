#ifndef _ACCOUNT_HPP_
#define _ACCOUNT_HPP_
/**
 * @file Account.hpp
 * @brief Defines the abstract base class for different types of bank accounts.
 *
 * This file contains the declaration of the Account class, which provides
 * common functionality and attributes shared by all account types.
 *
 * The class supports:
 * - Account owner management
 * - Account balance handling
 * - Account identification
 * - Deposit operations
 * - Virtual withdrawal functionality
 * - Tracking the total number of created accounts
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */

#include <string>

/**
 * @class Account
 * @brief Abstract base class representing a bank account.
 *
 * The Account class provides the basic interface for all account types.
 * It manages account information such as owner name, account ID, and balance.
 *
 * Derived classes must implement the withdraw() function to provide
 * account-specific withdrawal behavior.
 *
 * @note This class cannot be instantiated directly because withdraw()
 *       is a pure virtual function.
 */
class Account
{
    public:
     /**
     * @brief Constructs a new Account object.
     *
     * Initializes the account owner name and account balance.
     * A unique account ID is automatically assigned.
     *
     * @param name Account owner's name.
     * @param balance Initial account balance.
     */
    Account(const std::string &name,
            double balance);

    /**
     * @brief Virtual destructor.
     *
     * Ensures proper destruction of derived class objects when
     * accessed through an Account pointer.
     */
    virtual ~Account();

     /**
     * @brief Gets the account owner's name.
     *
     * @return Constant reference to the owner's name.
     */
    const std::string &getAccountOwnerName() const;

    /**
     * @brief Gets the unique account ID.
     *
     * @return The account identification number.
     */
    unsigned int getAccountID() const;

    /**
     * @brief Gets the current account balance.
     *
     * @return Current balance of the account.
    */
    double getAccountBalance() const;

    /**
     * @brief Updates the account owner's name.
     *
     * @param name New owner name.
     */
    void setAccountOwnerName(const std::string &name);

    /**
     * @brief Displays account information.
     *
     * This function can be overridden by derived classes to display
     * additional account-specific information.
     */
    virtual void displayAccountInfo() const ;

     /**
     * @brief Gets the total number of created accounts.
     *
     * @return Number of accounts created.
     */
    static unsigned int getNumberOfAccounts();
    
    /**
     * @brief Deposits money into the account.
     *
     * Adds the specified amount to the account balance.
     *
     * @param amount Amount of money to deposit.
     */
    virtual void deposit(double amount);

    /**
     * @brief Withdraws money from the account.
     *
     * This function must be implemented by derived classes according
     * to their withdrawal rules.
     *
     * @param amount Amount of money to withdraw.
     *
     * @pure
    */
    virtual void withdraw(double amount) = 0;

    protected:
    /**
     * @brief Current account balance.
     *
     * Protected member accessible by derived account classes.
    */
    double balance_; 

    private:
    /**
     * @brief Account owner's name.
    */
    std::string owner_name_;

    /**
     * @brief Unique identifier assigned to the account.
    */
    unsigned int account_id_;

    /**
     * @brief Stores the next available account ID.
    */
    static unsigned int next_account_id_;

    /**
     * @brief Tracks the total number of created accounts.
    */
    static unsigned int account_number_;
};

#endif /* _ACCOUNT_HPP_ */