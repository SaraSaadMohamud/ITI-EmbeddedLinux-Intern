/** 
 * @file main.cpp 
 * @author Sara Saad Mahmoud 
 * @brief Demonstrates the Aggregation relationship in Object-Oriented Programming (OOP). 
 * @version 1.0 
 * @date 2026-07-23 
 * @details 
 * This program demonstrates the Aggregation relationship between the 
 * Employee and Department classes. 
 * Three Employee objects are created independently and stored in a 
 * std::vector as pointers. The vector is then passed to a Department 
 * object, allowing the Department to reference the employees without 
 * taking ownership of them. 
 * Since the Department does not create or destroy the Employee objects, 
 * both classes have independent lifetimes, which is the defining 
 * characteristic of the Aggregation relationship.
 * 
 */

#include <iostream>
#include "Agregation.hh"

int main()
{
    Employee e1("Sara",50,15000.0);
    Employee e2("Ahmed",55,11000.0);
    Employee e3("Adel",60,10000.0);
    std::vector<Employee *> vec1 = {&e1,&e2,&e3};

    Department d1("Valeo",1050,vec1);
    d1.printDepartmentInfo();
    
    return(0);
}