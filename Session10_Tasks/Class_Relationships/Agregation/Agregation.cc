/** 
 * @file Agregation.cpp * 
 * @author Sara Saad Mahmoud 
 * @brief Implementation file for the Employee and Department classes. 
 * @version 1.0 * @date 2026-07-23 * 
 * @details * This source file implements the member functions of the Employee and 
 * Department classes. It demonstrates the Aggregation relationship in 
 * Object-Oriented Programming (OOP), where a Department object stores 
 * pointers to Employee objects without owning or managing their lifetime. 
 * @note 
 * he Department class does not allocate or deallocate Employee objects. 
 * Employee objects are created independently and only referenced by the 
 * Department through a std::vector of pointers. 
 * 
 */

#include <iostream>
#include "Agregation.hh"

Employee::Employee()
{
    std::cout<<"Default Constructor Called!\n";
}

Employee::Employee(const std::string &name, const unsigned int id, const double salary)
{
    name_ = name;
    id_ = id;
    salary_ = salary;
    std::cout<<"Paramtrized Constructor Called!\n";
}

Employee::Employee(const Employee &obj)
{
    name_   = obj.name_;
    id_     = obj.id_;
    salary_ = obj.salary_;
    std::cout<<"Copy Constructor Called!\n";
}

Employee::~Employee()
{
    std::cout<<"Default Destructor Called!\n";
}

const std::string &Employee::getEmployeeName() const 
{
    return(this->name_);
}

unsigned int Employee::getEmployeeID() const 
{
    return(this->id_);
}

double Employee::getEmployeeSalary() const
{   
    return(this->salary_);
}

void Employee::setEmployeeName(const std::string &name)
{
    name_ = name;
}

void Employee::setEmployeeID(const unsigned int id)
{
    id_ = id;
}

void Employee::setEmployeeSalary(const double salary)
{
    salary_ = salary;
}

void Employee::printEmployeeInfo() const
{
    std::cout<<"=============== Employee Data ===============\n";
    std::cout<<"Name    : "<<name_  <<std::endl;
    std::cout<<"ID      : "<<id_    <<std::endl;
    std::cout<<"Salary  : "<<salary_<<std::endl;
    std::cout<<"=============================================\n";
}

Department::Department()
{
    std::cout<<"Default Constructor Called!\n";
}

Department::Department(const std::string &name, unsigned int id, const std::vector<Employee*> &employee)
{
    name_       = name;
    id_         = id;
    employee_   = employee;
    std::cout<<"Paramtrized Constructor Called!\n";
}

Department::Department(const Department &obj)
{
    name_       = obj.name_;
    id_         = obj.id_;
    employee_   = obj.employee_;
    std::cout<<"Copy Constructor Called!\n";
}

Department::~Department()
{
    std::cout<<"Default Destructor Called!\n";
}

const std::string &Department::getDepartmentName() const
{
    return(this->name_);
}

unsigned int Department::getDepartmentID() const
{
    return(this->id_);
}

const std::vector<Employee*> &Department::getDepartmentEmployee() const
{
    return((this->employee_));
}

void Department::setDepartmentName(const std::string &name)
{
    name_ = name;
}

void Department::setDepartmentID(const unsigned int id)
{
    id_ = id;
}

void Department::setDepartmentEmployee(const std::vector<Employee*> &vec1)
{
    employee_ = vec1;
}

void Department::printDepartmentInfo() const
{
    std::cout<<"Department Name: "<<name_<<std::endl;
    std::cout<<"Departmetn ID: "<<id_<<std::endl;
    int size = employee_.size();
    for(int i=0 ; i<size  ;i++)
    {
        employee_[i]->printEmployeeInfo();
        std::cout<<"-----------------------------------------------------------\n";
    }
}