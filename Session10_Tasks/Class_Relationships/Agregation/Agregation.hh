/**
 * @file Agregation.hh
 * @author Sara Saad Mahmoud
 * @brief Demonstrates the Aggregation relationship in Object-Oriented Programming (OOP) using C++.
 * @version 1.0
 * @date 2026-07-23
 *
 * @details
 * This project illustrates the Aggregation relationship between two independent
 * classes: Employee and Department.
 *
 * In this implementation, a Department object maintains a collection of pointers
 * to Employee objects using a std::vector. The Department class does not own,
 * create, or destroy the Employee objects; therefore, the lifetime of Employee
 * objects is completely independent of the Department object.
 *
 * This example demonstrates the concept of weak ownership (Aggregation) in OOP.
 *
 * @note
 * Department stores only pointers to Employee objects.
 * Destroying a Department object does not destroy the Employee objects.

 */

#ifndef _AGREGATION_HPP_
#define _AGREGATION_HPP_

#include <string>
#include <vector>

/**
 * @class Employee
 * @brief Represents an employee in the company.
 *
 * The Employee class stores personal and salary information
 * for an employee. Employee objects are created independently
 * and may be shared among multiple objects.
 */
class Employee
{
public:

    /**
     * @brief Default constructor.
     */
    Employee();

    /**
     * @brief Parameterized constructor.
     *
     * @param name Employee name.
     * @param id Employee identification number.
     * @param salary Employee salary.
     */
    Employee(const std::string &name,
             const unsigned int id,
             const double salary);

    /**
     * @brief Copy constructor.
     *
     * @param obj Employee object to copy.
     */
    Employee(const Employee &obj);

    /**
     * @brief Destructor.
     */
    ~Employee();

    /**
     * @brief Returns the employee's name.
     *
     * @return Constant reference to the employee name.
     */
    const std::string &getEmployeeName() const;

    /**
     * @brief Returns the employee ID.
     *
     * @return Employee ID.
     */
    unsigned int getEmployeeID() const;

    /**
     * @brief Returns the employee salary.
     *
     * @return Employee salary.
     */
    double getEmployeeSalary() const;

    /**
     * @brief Sets the employee name.
     *
     * @param name New employee name.
     */
    void setEmployeeName(const std::string &name);

    /**
     * @brief Sets the employee ID.
     *
     * @param id New employee ID.
     */
    void setEmployeeID(const unsigned int id);

    /**
     * @brief Sets the employee salary.
     *
     * @param salary New employee salary.
     */
    void setEmployeeSalary(const double salary);

    /**
     * @brief Prints all employee information.
     */
    void printEmployeeInfo() const;

private:

    /** Employee name. */
    std::string name_;

    /** Employee identification number. */
    unsigned int id_;

    /** Employee salary. */
    double salary_;
};

/**
 * @class Department
 * @brief Represents a company department.
 *
 * The Department class aggregates multiple Employee objects
 * by storing pointers to them inside a std::vector.
 *
 * The Department does not own Employee objects and is not
 * responsible for their creation or destruction.
 */
class Department
{
public:

    /**
     * @brief Default constructor.
     */
    Department();

    /**
     * @brief Parameterized constructor.
     *
     * @param name Department name.
     * @param id Department identification number.
     * @param employee Vector containing pointers to Employee objects.
     */
    Department(const std::string &name,
               unsigned int id,
               const std::vector<Employee*> &employee);

    /**
     * @brief Copy constructor.
     *
     * @param obj Department object to copy.
     */
    Department(const Department &obj);

    /**
     * @brief Destructor.
     */
    ~Department();

    /**
     * @brief Returns the department name.
     *
     * @return Constant reference to the department name.
     */
    const std::string &getDepartmentName() const;

    /**
     * @brief Returns the department ID.
     *
     * @return Department ID.
     */
    unsigned int getDepartmentID() const;

    /**
     * @brief Returns the employee collection.
     *
     * @return Constant reference to the vector of Employee pointers.
     */
    const std::vector<Employee*> &getDepartmentEmployee() const;

    /**
     * @brief Sets the department name.
     *
     * @param name New department name.
     */
    void setDepartmentName(const std::string &name);

    /**
     * @brief Sets the department ID.
     *
     * @param id New department ID.
     */
    void setDepartmentID(const unsigned int id);

    /**
     * @brief Sets the employee collection.
     *
     * @param vec1 Vector containing pointers to Employee objects.
     */
    void setDepartmentEmployee(const std::vector<Employee*> &vec1);

    /**
     * @brief Prints the department information and all employees.
     */
    void printDepartmentInfo() const;

private:

    /** Department name. */
    std::string name_;

    /** Department identification number. */
    unsigned int id_;

    /**
     * @brief Collection of pointers to Employee objects.
     *
     * This vector demonstrates Aggregation. The Department
     * references Employee objects but does not own them.
     */
    std::vector<Employee*> employee_;
};

#endif /* _AGREGATION_HPP_ */
