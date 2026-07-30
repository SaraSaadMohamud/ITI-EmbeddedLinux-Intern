/**
 * @file Admin.hpp
 * @author Sara Saad Mahmoud
 * @date 2026-07-30
 * @brief Declares the administrative interface for the Bank Management System.
 *
 * @details
 * This header provides the declarations of functions used by administrators
 * to manage bank accounts and perform banking operations. The available
 * operations include:
 * - Administrator authentication.
 * - Displaying the administrator menu.
 * - Creating and removing accounts.
 * - Depositing and withdrawing funds.
 * - Transferring money between accounts.
 * - Displaying an account's transaction history.
 */

#ifndef _ADMIN_HPP_
#define _ADMIN_HPP_

#include "Bank.hpp"

/**
 * @brief Displays the administrator menu.
 *
 * @param bank A reference to the Bank object to be managed.
 */
void displayAdminMenu(Bank &bank);

/**
 * @brief Authenticates the administrator before granting access.
 */
void AdminLogin();

/**
 * @brief Creates a new bank account.
 *
 * @param bank A reference to the Bank object.
 */
void addNewAccount(Bank &bank);

/**
 * @brief Removes an existing bank account.
 *
 * @param bank A reference to the Bank object.
 */
void removeAccount(Bank &bank);

/**
 * @brief Deposits money into a bank account.
 *
 * @param bank A reference to the Bank object.
 */
void deposit(Bank &bank);

/**
 * @brief Withdraws money from a bank account.
 *
 * @param bank A reference to the Bank object.
 */
void withdraw(Bank &bank);

/**
 * @brief Transfers funds between two bank accounts.
 *
 * @param bank A reference to the Bank object.
 */
void transfer(Bank &bank);

/**
 * @brief Displays the transaction history of a bank account.
 *
 * @param bank A reference to the Bank object.
 */
void displayAccountTransaction(Bank &bank);

#endif /* _ADMIN_HPP_ */