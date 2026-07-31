#ifndef _BANK_HPP_
#define _BANK_HPP_

#include <vector>
#include <string>
#include "Account.hpp"
#include "Transaction.hpp"
#include <fstream>
#include <sstream>
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"

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

    /**
        * @brief Displays all recorded account transactions.
        *
        * @details
        * Prints the complete transaction history stored for the account.
        * If no transactions are available, an appropriate message is displayed.
        *
        * @note This function does not modify the account or its transaction history.
    */
    void displayTransactions() const;

    /**
        * @brief Displays general information about the bank.
        *
        * @details
        * Prints an overview of the bank, such as its name, the total number
        * of accounts, and other relevant summary information.
    */
    void displayBankInfo() const;

    /**
        * @brief Displays the transaction history for a specific bank account.
        *
        * @param account_id The unique identifier of the account whose
        *        transactions are to be displayed.
        *
        * @details
        * Searches for the account with the specified ID and prints all
        * recorded transactions associated with it. If the account does
        * not exist, an appropriate message is displayed.
    */
    void displayBankAccountTransaction(unsigned int account_id) const;

    /**
        * @brief Displays transaction statistics for the bank.
        *
        * @details
        * Prints statistical information about all recorded transactions,
        * such as the total number of transactions and other available
        * transaction-related summaries.
    */
    void displayTransactionStatistics() const;

    /**
        * @brief Saves all bank accounts to persistent storage.
        *
        * Writes the current account information to a file so that
        * it can be restored when the application is restarted.
     */
    void saveAccount() const;

    /**
        * @brief Loads bank accounts from persistent storage.
        *
        * Reads the stored account information from a file and
        * reconstructs the bank's account records.
     */
    void loadAccounts();

    /**
        * @brief Saves all account transactions to persistent storage.
        *
        * Writes the transaction history of all accounts to a file,
        * preserving transaction records between program executions.
     */
    void saveTransactions() const;

    /**
        * @brief Loads account transactions from persistent storage.
        *
        * Reads transaction records from a file and restores the
        * transaction history for the corresponding accounts.
     */
    void loadTransactions();

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

    /**
        * @brief Stores all transactions associated with the account.
        *
        * @details
        * This vector maintains a history of every transaction performed
        * on the account, including deposits, withdrawals, and transfers.
        * New transactions are appended as they occur.
    */
    std::vector<Transaction> transactions_;

    /**
        * @brief Adds a new transaction to the transaction history.
        *
        * @param obj A constant reference to the Transaction object to be added.
        *
        * @details
        * Inserts the specified transaction into the collection of stored
        * transactions without modifying the original object.
    */
    void addTransaction(const Transaction & obj);
    
};

#endif /* _BANK_HPP_ */