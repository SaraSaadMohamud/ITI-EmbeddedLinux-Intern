/**
 * @file main.cc
 * @brief Demonstrates the Student Management System.
 *
 * This program creates two Student objects and demonstrates two
 * different ways of initializing student information:
 *
 * 1. Calling each setter function individually.
 * 2. Calling the setClassData() function to initialize all data at once.
 *
 * The program then prints each student's information including
 * name, ID, subject grades, total marks, average, and final grade.
 *
 * @author Sara Saad
 * @date July 2026
 */


#include "student_management.hh"
#include "iostream"
#include <limits>

int main()
{
    class Student student1;
    class Student student2;

    std::string student_name_;
    unsigned int student_id_;
    double subject_degree_[SUBJECT_NUM];

    std::cout<<"Enter Student Name: ";
    std::getline(std::cin, student_name_);

    std::cout<<"Enter Student ID: ";
    std::cin>>student_id_;

    for(int i=0 ; i<SUBJECT_NUM ; i++)
    {
        std::cout<<"Subject["<<i+1<<"] Degree: ";
        std::cin>>subject_degree_[i];
    }

    student1.setStudentName(student_name_);
    student1.setStudentID(student_id_);
    student1.setSubjectDegree(subject_degree_);
    student1.setTotal(subject_degree_);
    student1.setAverage(student1.getTotal());
    student1.setGarade(student1.getAverage());

    student1.printStudent();

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::string student_name;
    unsigned int student_id;
    double subject_degree[SUBJECT_NUM];
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"Enter Student Name: ";
    std::getline(std::cin, student_name);

    std::cout<<"Enter Student ID: ";
    std::cin>>student_id;

    for(int i=0 ; i<SUBJECT_NUM ; i++)
    {
        std::cout<<"Subject["<<i+1<<"] Degree: ";
        std::cin>>subject_degree[i];
    }

    student2.setClassData(student_name, student_id, subject_degree);
    student2.printStudent();

    return 0;
}