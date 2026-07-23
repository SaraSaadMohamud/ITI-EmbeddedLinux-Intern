/**
 * @file main.cpp
 * @brief Entry point for demonstrating the Association relationship in OOP.
 *
 * This program creates independent Student and Course objects, then
 * demonstrates an Association relationship by allowing the Course
 * object to access and display information about a Student object
 * without owning or managing its lifetime.
 *
 * Association Characteristics:
 * - Student and Course objects exist independently.
 * - Neither object is responsible for creating or destroying the other.
 * - The relationship is established through a member function using
 *   a reference to an existing Student object.
 *
 * @author Sara Saad Mahmoud
 * @date July 2026
 * @version 1.0
 */

#include "Assocation.hh"
#include <iostream>

int main()
{
    Student s1("Sara",100,23.0);
    Course c1("Linux",5000.0, 100);

    c1.showCourseStudent(s1);
    c1.printCourseInfo();

    return(0);
}