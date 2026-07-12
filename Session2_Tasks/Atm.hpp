/**
 * @file ATM.hpp
 * @brief Header file for the Console ATM Banking System
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-12
 * @copyright None (Educational Project)
 */

#ifndef _ATM_HPP_
#define _ATM_HPP_

/********************************************** Include-Part ****************************************** */
#include <iostream>
#include <string>
#include <limits>
/********************************************** Variables ******************************************** */
/**
 * @def MAX_VALID_TRANSFER
 * @brief Maximum allowed amount per single transaction (in EGP)
 */
inline constexpr unsigned int MAX_VALID_TRANSFER = 10000;

/**
 * @def MIN_VALID_TRANSFER
 * @brief Minimum allowed amount per single transaction (in EGP)
 */
inline constexpr unsigned int MIN_VALID_TRANSFER = 5;

/**
 * @def VALID_PASS
 * @brief Hardcoded 4-digit password for the ATM demo
 */
inline constexpr unsigned int VALID_PASS = 1234;

/******************************************* Function-Prototypes ************************************** */

/**
 * @brief Handles user login with password verification
 * 
 * Prompts the user to enter the 4-digit password.
 * Allows up to 3 attempts before locking the system.
 * 
 * @return `true` if login is successful, `false` if maximum attempts reached
 */
bool logIn(void);

/**
 * @brief Displays the main ATM menu and handles user choices
 * 
 * Shows options: Withdraw, Deposit, Check Balance, and Exit.
 * Routes the user input to the appropriate functions.
 * 
 * @param balance Reference to the current account balance (may be modified)
 */
void mainMenue(unsigned int &balance);

/**
 * @brief Withdraw money from the account
 * @param balance Reference to the current balance (will be modified)
 * @param value Amount to withdraw
 */

void withdraw(unsigned int &balance, unsigned int value);
/**
 * @brief Deposit money into the account
 * @param balance Reference to the current balance (will be modified)
 * @param value Amount to deposit
 */

void deposit(unsigned int &balance, unsigned int value);
/**
 * @brief Return the current account balance
 * @param balance Const reference to the balance
 * @return Current balance in EGP
 */

unsigned int checkBalance(const unsigned int &balance);
/**
 * @brief Clear input stream error state and ignore bad input
 * Used after failed std::cin operations
 */

void clearError(void);

/******************************************************************************************************* */
#endif /*_ATM_HPP_*/