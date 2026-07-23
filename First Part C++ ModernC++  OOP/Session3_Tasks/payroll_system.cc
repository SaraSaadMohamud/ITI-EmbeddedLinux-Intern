/**
 * @file payroll_system.cpp
 * @brief Implementation of the Payroll Management System.
 *
 * This source file implements all payroll-related functions, including
 * employee data collection, salary calculation, bonus application,
 * tax deduction, payroll generation, and input validation.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-13
 */

/*=================================  Include ==================================*/
#include "payroll_system.hpp"

/*============================== Global Variables ==============================*/

/** Employee full name. */
std::string name;

/** Employee unique identifier. */
unsigned int id;

/** Total working hours. */
double working_hours;

/** Employee hourly wage. */
double houre_rate;
/** Overtime working hours. */

double over_time;
/** Employee position ('m' = Manager, 'e' = Employee). */
char position;

/** Salary after bonus and final net salary. */
double salary_after_bonus, net_salary;

/** Calculated tax amount. */
double tax_amount;

/*============================== Function Definitions ==============================*/

double calculateSalaryBeforeTax(void)
{
    
    double preTaxSalary;

    std::cout<<"Employee Name: ";
    std::getline(std::cin,name);

    int attempts=0;
    do{
        
        std::cout<<"Employee ID: ";
        if(!(std::cin>>id))
        {
            std::cout<<"Invalid ID!.\n";
            clearError();
            attempts++;
            if(attempts>=3)
            {
                return(-1);
            }
        }
    }while(id<=0);

    attempts=0;
    do{
        std::cout<<"Working Hours: ";
        if(!(std::cin>>working_hours))
        {
            std::cout<<"Invalid input!.\n";
            clearError();
            attempts++;
            if(attempts>=3)
            {
                return(-1);
            }
        }
    }while(working_hours<=0);

    attempts=0;
    do{
        std::cout<<"Hourly Rate: ";
        if(!(std::cin>>houre_rate))
        {
            std::cout<<"Invalid Rate!.\n";
            clearError();
            attempts++;
            if(attempts>=3)
            {
                return(-1);
            }
        }
    }while(houre_rate<=0);

     do{

        std::cout<<"Position [m = manager , e = employee]: ";
        std::cin>>position;
    }while((position!='m') && (position!='e'));

    attempts=0;
    do{
        std::cout<<"OverTime Hours: ";
        if(!(std::cin>>over_time))
        {
            std::cout<<"Invalid input!.\n";
            clearError();
            attempts++;
            if(attempts>=3)
            {
                return(-1);
            }
        }
    }while(over_time<0);

    preTaxSalary = ( (houre_rate * working_hours) + ( over_time * (houre_rate*1.5) ));

    return(preTaxSalary);
}
/*==================================================================================*/

double addBonus(double salary)
{
    char bonus;
    double manager_bonus_value = (0.10 * salary);
    double employee_bonus_value = (0.05 * salary);
    unsigned int attempt=0;
    double salaryAfterBonus;

    do{
        if(position == 'm')
            std::cout<<"Adding [10%] Bonus ? (y / n): ";
        else
            std::cout<<"Adding [5%] Bonus ? (y / n): "; 
        std::cin>>bonus;
        attempt++;
        if(attempt>=3)
        {
            return(-1);
        }
    }while((bonus!= 'y') && (bonus != 'n'));

    if(bonus == 'y')
    {
        if (position == 'm')
        salaryAfterBonus = (salary + manager_bonus_value);
        else 
        salaryAfterBonus = (salary + employee_bonus_value);
    }
    else 
    {
        salaryAfterBonus = salary ;
    }
    
    return(salaryAfterBonus);
}
/*==================================================================================*/

double calculateSalaryAfterTax(double salary)
{
   tax_amount = (salary * tax_percent);
   double net_salary = salary - tax_amount ;
   return (net_salary);
}
/*==================================================================================*/

void payRoll(void)
{
    std::cout<<"\n========================= PayRoll ==============================\n\n";
    std::cout<<"Employee : "<<name<<std::endl;
    std::cout<<"ID: "<<id<<std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout<<"Salary: "<<salary_after_bonus<<" $\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout<<"TAX[10%]: "<<tax_amount<<" $"<<std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout<<"Net Salary: "<<net_salary<<" $\n";
}
/*==================================================================================*/

void clearError(void )
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
/*==================================================================================*/