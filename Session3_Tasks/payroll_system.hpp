/**
 * @file payroll_system.hpp
 * @brief Header file for the Payroll Management System.
 *
 * This file contains the declarations of all functions and constants
 * used to calculate employee salaries, bonuses, taxes, and generate
 * the payroll report.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-13
 */

#ifndef _PAYROLL_SYSTEM_HPP_
#define _PAYROLL_SYSTEM_HPP_

/************************************************** Include Part ******************************************** */
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

/**
 * @brief Clears the input stream after an invalid input.
 *
 * Resets the error flags of the input stream and discards
 * any remaining characters in the input buffer.
 */
void clearError(void);

/**
 * @brief Calculates the employee's salary before tax.
 *
 * Requests employee information, validates the input,
 * and computes the gross salary including overtime pay.
 *
 * @return Gross salary before tax.
 * @retval -1 If the maximum number of invalid attempts is reached.
 */
double calculateSalaryBeforeTax(void);

/**
 * @brief Adds a bonus to the employee's salary.
 *
 * The user chooses whether to apply a bonus.
 * If accepted, a 10% bonus is added to the current salary.
 *
 * @param salary Current salary before tax.
 * @return Salary after adding the bonus.
 * @retval -1 If the maximum number of invalid attempts is reached.
 */
double addBonus(double salary);

/**
 * @brief Calculates the employee's net salary after tax.
 *
 * Deducts the tax percentage from the salary.
 *
 * @param salary Salary before tax.
 * @return Net salary after tax deduction.
 */
double calculateSalaryAfterTax(double salary);


/**
 * @brief Displays the payroll report.
 *
 * Prints the employee information, tax amount,
 * and final net salary.
 */
void payRoll(void);

/**
 * @brief Fixed tax percentage.
 *
 * Represents a 10% tax deduction applied to the employee salary.
 */
inline constexpr double tax_percent = 0.10;

#endif /*_PAYROLL_SYSTEM_HPP_*/