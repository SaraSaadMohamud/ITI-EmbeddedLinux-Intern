#ifndef _BANK_HPP_
#define _BANK_HPP_

#include <vector>
#include <string>
#include "Account.hpp"

/**
 * @file Bank.hpp
 * @brief Defines the Bank class.
 *
 * This file contains the declaration of the Bank class, which manages
 * a collection of bank accounts. It provides operations for adding,
 * removing, searching, depositing, withdrawing, transferring funds,
 * and displaying account information.
 *
 * The Bank class owns the Account objects stored within it and is
 * responsible for managing their lifetime.
 *
 * @author Sara Saad Mahmoud
 * @version 1.0
 * @date Jul 2026
 */


/**
 * @class Bank
 * @brief Represents a bank that manages multiple accounts.
 *
 * The Bank class stores pointers to Account objects and provides
 * high-level banking operations such as:
 * - Creating and managing accounts
 * - Depositing and withdrawing funds
 * - Transferring money between accounts
 * - Searching for accounts by their unique ID
 * - Displaying information about all accounts
 *
 * The class is responsible for managing the lifetime of the accounts
 * stored in its internal collection.
 */
class Bank
{
public:

    /**
     * @brief Constructs a new Bank object.
     *
     * Initializes the bank with the specified name.
     *
     * @param bank_name Name of the bank.
    */
    Bank(const std::string &bank_name);


    /**
     * @brief Destroys the Bank object.
     *
     * Releases all dynamically allocated account objects owned by
     * the bank.
    */
    ~Bank();


    /**
     * @brief Gets the bank's name.
     *
     * @return Constant reference to the bank name.
    */
    const std::string &getBankName() const;


    /**
     * @brief Adds a new account to the bank.
     *
     * The bank assumes ownership of the provided account pointer.
     *
     * @param new_acc Pointer to the account to be added.
    */
    void addAccount(Account *new_acc);


    /**
     * @brief Removes an account from the bank.
     *
     * Removes the account matching the specified account ID.
     *
     * @param account_id Unique account identifier.
    */
    void removeAccount(unsigned int account_id);


    /**
     * @brief Searches for an account by its ID.
     *
     * @param account_id Unique account identifier.
     *
     * @return Pointer to the matching account if found;
     *         otherwise nullptr.
    */
    Account *findAccount(unsigned int account_id) const;


    /**
     * @brief Deposits money into an account.
     *
     * @param amount Amount to deposit.
     * @param account_id Destination account ID.
    */
    void deposit(double amount, unsigned int account_id);


    /**
     * @brief Withdraws money from an account.
     *
     * @param amount Amount to withdraw.
     * @param account_id Source account ID.
    */
    void withdraw(double amount, unsigned int account_id);


    /**
     * @brief Transfers money between two accounts.
     *
     * Withdraws the specified amount from one account and deposits
     * it into another account.
     *
     * @param amount Amount to transfer.
     * @param account1_id Source account ID.
     * @param account2_id Destination account ID.
    */
    void transfer(double amount,
                  unsigned int account1_id,
                  unsigned int account2_id);


    /**
     * @brief Gets the total number of accounts managed by the bank.
     *
     * @return Number of accounts currently stored.
    */
    unsigned int getAccountsCount() const;


    /**
     * @brief Displays information for all bank accounts.
     *
     * Calls the display function for every account managed by the bank.
    */
    void displayAccounts() const;


private:

    /**
     * @brief Name of the bank.
    */
    std::string bank_name_;


    /**
     * @brief Collection of account pointers managed by the bank.
     *
     * The Bank object owns the accounts stored in this container.
    */
    std::vector<Account *> accounts_;
};

#endif /* _BANK_HPP_ */