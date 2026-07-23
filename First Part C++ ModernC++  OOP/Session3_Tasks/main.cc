/**
 * @file main.cpp
 * @brief Entry point of the Payroll Management System.
 *
 * This file controls the program execution flow by:
 * - Collecting employee information.
 * - Calculating the salary before tax.
 * - Applying an optional bonus.
 * - Calculating the final salary after tax.
 * - Displaying the payroll report.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-13
 */

/*=================================  Include ==================================*/

#include "payroll_system.hpp"

/**
 * @brief Global variables defined in payroll_system.cpp.
 *
 * These variables store the salary after applying the bonus
 * and the final net salary after tax deduction.
 */
extern double salary_after_bonus, net_salary;


/**
 * @brief Program entry point.
 *
 * The program performs the following steps:
 * 1. Reads employee information.
 * 2. Calculates the salary before tax.
 * 3. Displays the calculated salary.
 * 4. Optionally applies a bonus.
 * 5. Calculates the net salary after tax deduction.
 * 6. Displays the final payroll report.
 *
 * If invalid input is entered three consecutive times,
 * the program terminates.
 *
 * @return int Returns 0 when the program terminates.
 */
int main()
{
    double pre_tax_salary = calculateSalaryBeforeTax();
    if(pre_tax_salary == -1)
    {
        return(0);
    }
    else
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout<<"\n Salary before TAX: "<<pre_tax_salary<<" $\n\n";
    }
    
     salary_after_bonus = addBonus(pre_tax_salary);
    if(salary_after_bonus == -1)
    {
        return(0);
    }
    else if (salary_after_bonus == pre_tax_salary){}
    else
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout<<"\n Bonuce added.\n Current Salary before TAX: "<<salary_after_bonus<<" $\n\n";
    }

    net_salary = calculateSalaryAfterTax(salary_after_bonus);
    payRoll();

    return(0);
}

