/**
 * @file student_management.cc
 * @brief Implementation of the Student class.
 *
 * This file contains the implementation of the Student class methods
 * for managing student information, calculating total marks,
 * average, and final letter grade.
 */

#include "student_management.hh"
#include <iostream>

Student::Student()
{
    student_name_ = "0";
    student_id_ = 0;
    subject_degree_[0] = 0.0;
    subject_degree_[1] = 0.0;
    subject_degree_[2] = 0.0;
    total_ =0;
    average_ = total_ / SUBJECT_NUM ;
    grade_ = '-';
}

void Student::setStudentName(const std::string &name)
{
    this->student_name_ = name;
}

void Student::setStudentID(const unsigned int &id)
{
    this->student_id_ = id;
}

void Student::setSubjectDegree(const double student_degree[])
{
    for(size_t i=0 ; i<SUBJECT_NUM ; i++)
    {
        this->subject_degree_[i] = student_degree[i];
    }
}

void Student::setTotal(const double student_degree[])
{
    for(size_t i = 0 ; i<SUBJECT_NUM  ; i++)
    {
        this->total_ += subject_degree_[i];
    }
}

void Student::setAverage(const double &total)
{
    this->average_ = total / SUBJECT_NUM ;
}

void Student::setGarade(const double &average)
{
    if(average > 90)
    {
        this->grade_ = 'A';
    }
    else if (average > 80)
    {
        this ->grade_ = 'B';
    }
    else if(average > 70)
    {
        this->grade_ = 'C';
    }
    else if (average > 60)
    {
        this->grade_ = 'D';
    }
    else
    {
        this->grade_ = 'F';
    }
}

std::string Student::getStudentName() const
{
    return(student_name_);
}

unsigned int Student::getStudentID() const
{
    return(student_id_);
}

const double* Student::getSubjectDegree() const
{
    return(this->subject_degree_);
}

double Student::getTotal() const
{
    return(total_);
}

double Student::getAverage() const
{
    return(average_);
}

char Student::getGrade() const 
{
    return(grade_);
}

void Student::printStudent() const
{
    std::cout<<"\n========================================= Student Data =====================================\n\n";
    std::cout<<"Name: "<<(getStudentName())<<std::endl;
    std::cout<<"ID: "<<(getStudentID())<<std::endl;
    const double *ptr = getSubjectDegree();
    for(int i =0 ; i<SUBJECT_NUM ; i++)
    {
        std::cout<<"Sub["<<i<<"]: "<<*ptr<<std::endl;
        ptr++;
    }
    ptr = nullptr;

    std::cout<<"Total: "<<getTotal()<<std::endl;
    std::cout<<"Average: "<<getAverage()<<std::endl;
    std::cout<<"Grade: "<<getGrade()<<std::endl;
    std::cout<<"\n=================================================================================================\n";
}


void Student::setClassData(const std::string &name, const unsigned int &id, const double student_degree[])
{
    this->setStudentName(name);
    this->setStudentID(id);
    this->setSubjectDegree(student_degree);
    this->setTotal(this->getSubjectDegree());
    this->setAverage(this->getTotal());
    this->setGarade(this->getAverage());
}