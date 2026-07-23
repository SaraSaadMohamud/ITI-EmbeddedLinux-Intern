/**
 * @file association.cpp
 * @brief Implementation of the Student and Course classes.
 *
 * This source file contains the implementation of all member functions
 * for the Student and Course classes. It demonstrates the Association
 * relationship in Object-Oriented Programming (OOP), where a Course
 * object interacts with a Student object without owning or managing
 * its lifetime.
 *
 * @author Sara Saad Mahmoud
 * @date July 2026
 * @version 1.0
 */


#include <iostream>
#include "Assocation.hh"

Student::Student()
{
    std::cout<<"Default Construcyor Called!\n";
}

Student::Student(const std::string &name, const unsigned int id, const float age)
{
    this->name_ = name;
    this->id_ = id;
    this->age_ = age;
    std::cout<<"Parametrize Construcyor Called!\n";
}

Student::Student(const Student &obj)
{
    this->name_ = obj.name_;
    this->id_   = obj.id_;
    this->age_  = obj.age_;
    std::cout<<"Copy Construcyor Called!\n";
}

Student::~Student()
{
    std::cout<<"Default Destrucyor Called!\n";
}

const std::string Student::getStudentName() const
{
    return(this->name_);
}

unsigned int Student::getStudentID() const
{
    return(this->id_);
}

float Student::getStudentAge() const
{
    return(this->age_);
}

void Student::setStudentName(const std::string &name)
{
    name_ = name;
}

void Student::setStudentID(const unsigned int id)
{
    id_ = id;
}

void Student::setStudentAge(const float age)
{
    age_ = age;
}

void Student::printStudentInfo() const
{
    std::cout<<"============== Student Information ==================\n";
    std::cout<<"Name    : "<<name_  <<std::endl;
    std::cout<<"ID      : "<<id_    <<std::endl;
    std::cout<<"Age     : "<<age_   <<std::endl;
    std::cout<<"=====================================================\n";
}

Course::Course()
{
    std::cout<<"Default Construcyor Called!\n";
}

Course::Course(const std::string &name , double course_price, unsigned int course_code)
{
    this->name_         = name;
    this->course_price_ = course_price;
    this->course_code_  = course_code;
    std::cout<<"Parametrize Construcyor Called!\n";
}

Course::Course(const Course & obj)
{
    this->name_         = obj.name_;
    this->course_price_ = obj.course_price_;
    this->course_code_  = obj.course_code_;
    std::cout<<"Copy Construcyor Called!\n";
}

Course::~Course()
{
    std::cout<<"Default Destrucyor Called!\n";
}

const std::string Course::getCourseName() const 
{
    return(this->name_);
}

double Course::getCoursePrice() const
{
    return(this->course_price_);
}

unsigned int Course::getCourseCode() const
{
    return(this->course_code_);
}

void Course::setCourseName(const std::string &name)
{
    name_ = name;
}

void Course::setCoursePrice(double price)
{
    course_price_ = price;
}

void Course::setCourseCode(unsigned int code)
{
    course_code_ = code;
}

void Course::printCourseInfo() const
{
    std::cout<<"============== Course Information ==================\n";
    std::cout<<"Name    : "<<name_          <<std::endl;
    std::cout<<"Price   : "<<course_price_  <<std::endl;
    std::cout<<"COde    : "<<course_code_   <<std::endl;
    std::cout<<"=====================================================\n";
}

void Course::showCourseStudent(Student &student) const
{
    student.printStudentInfo();
}

