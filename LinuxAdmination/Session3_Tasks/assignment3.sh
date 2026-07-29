# Assignment 3 – Build Your Own Linux Shell Environment Scenario

#! bin/bash

read -s -p "Enenter Name: " employee_name
echo
read -s -p "Enter Age: " employee_age
echo
read -s -p "Enter Department: " employee_department
echo
read -s -p "Enter Salary: " employee_salary
echo

echo "================= Employee Information ==================="
echo "Employee Name		: " $employee_name
echo "Employee Age 		: " $employee_age
echo "Employee Department 	: " $employee_department
echo "Employee Salary 	: " $employee_salary
echo "========================================================="


