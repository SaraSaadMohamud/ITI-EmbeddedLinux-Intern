#ifndef _USER_HPP_
#define _USER_HPP_

/**
 * @file User.hpp
 * @brief Declares the user interface for the Bank Management System.
 *
 * This file contains the declarations of functions that provide
 * banking services available to authenticated users, including
 * deposits, withdrawals, transfers, account information display,
 * and transaction history.
 *
 * @author Sara Saad
 * @date July 30, 2026
 */

#include "Bank.hpp"
#include "Account.hpp"

/**
 * @brief Displays the user menu.
 *
 * Presents the available banking operations for the currently
 * logged-in user and handles user interaction.
 *
 * @param bank Reference to the Bank object.
 * @param current_user Pointer to the currently authenticated account.
 */
void displayUserMenu(Bank& bank, Account* current_user);

/**
 * @brief Clears the input buffer.
 *
 * Removes any remaining characters from the input stream to
 * prevent invalid input from affecting subsequent operations.
 */
void bufferClear();

/**
 * @brief Deposits money into the current user's account.
 *
 * Prompts the user for the deposit amount and updates the
 * account balance.
 *
 * @param bank Reference to the Bank object.
 * @param current_user Pointer to the currently authenticated account.
 */
void deposit(Bank& bank, Account* current_user);

/**
 * @brief Withdraws money from the current user's account.
 *
 * Prompts the user for the withdrawal amount and deducts it
 * from the account balance if sufficient funds are available.
 *
 * @param bank Reference to the Bank object.
 * @param current_user Pointer to the currently authenticated account.
 */
void withdraw(Bank& bank, Account* current_user);

/**
 * @brief Transfers money to another account.
 *
 * Prompts the user for the recipient account information and
 * transfer amount, then performs the transaction.
 *
 * @param bank Reference to the Bank object.
 * @param current_user Pointer to the currently authenticated account.
 */
void transfer(Bank& bank, Account* current_user);

/**
 * @brief Displays the current user's account information.
 *
 * Shows details such as the account ID, owner's name,
 * account type, and current balance.
 *
 * @param current_user Pointer to the currently authenticated account.
 */
void displayAccountInfo(Account* current_user);

/**
 * @brief Displays the transaction history of the current user's account.
 *
 * Retrieves and prints all transactions associated with the
 * authenticated user's account.
 *
 * @param bank Reference to the Bank object.
 * @param current_user Pointer to the currently authenticated account.
 */
void displayAccountTransactions(Bank& bank, Account* current_user);

#endif /* _USER_HPP_ */