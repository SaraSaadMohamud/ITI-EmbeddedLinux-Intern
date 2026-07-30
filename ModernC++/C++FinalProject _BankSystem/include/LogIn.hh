#ifndef _LOGIN_HH_
#define _LOGIN_HH_

/**
 * @file Login.hh
 * @brief Declares the login interface for the Bank Management System.
 *
 * This file contains the declarations of functions responsible for
 * displaying the main menu and authenticating administrators and
 * users before granting access to their respective interfaces.
 *
 * @author Sara Saad
 * @date July 30, 2026
 */

#include "Bank.hpp"
#include "Utilities.hpp"
#include "Admin.hpp"
#include "User.hpp"

/**
 * @brief Displays the main menu of the banking system.
 *
 * Presents the available options, such as administrator login,
 * user login, and system exit.
 *
 * @param bank Reference to the Bank object.
 */
void displayMainMenu(Bank &bank);

/**
 * @brief Authenticates an administrator.
 *
 * Prompts the administrator for login credentials and, if
 * authentication succeeds, grants access to the administrator menu.
 *
 * @param bank Reference to the Bank object.
 */
void adminLogIn(Bank &bank);

/**
 * @brief Authenticates a user.
 *
 * Prompts the user for account credentials and, if authentication
 * succeeds, grants access to the user menu.
 *
 * @param bank Reference to the Bank object.
 */
void userLogIn(Bank &bank);

#endif /* _LOGIN_HH_ */