#include "student_management.hh"
#include <iostream>

Student::Student()
{
    student_name_ = "0";
    student_id_ = 0;
    subject_degree_[0] = 0.0;
    subject_degree_[1] = 0.0;
    subject_degree_[2] =0.0;
    total_ =0;
    average_ = total_ / SUBJECT_NUM ;
    grade_ = '-';
}

void Student::setStudentName(const std::string &name)
{
    student_name_ = name;
}

void Student::setStudentID(const unsigned int &id)
{
    student_id_ = id;
}

void Student::setSubjectDegree(const double student_degree[])
{
    for(size_t i ; i<SUBJECT_NUM ; i++)
    {
        subject_degree_[i] = student_degree[i];
    }
}

void Student::setTotal(const double student_degree[])
{
    for(size_t i = 0 ; i<SUBJECT_NUM  ; i++)
    {
        total_ += subject_degree_[i];
    }
}

void Student::setAverage(const double &total)
{
    average_ = total / SUBJECT_NUM ;
}

void Student::setGarade(const char &average)
{
    if(average > 90)
    {
        grade_ = 'A';
    }
    else if (average > 80)
    {
        grade_ = 'B';
    }
    else if(average > 70)
    {
        grade_ = 'C';
    }
    else if (average > 60)
    {
        grade_ = 'D';
    }
    else
    {
        grade_ = 'F';
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

const double * Student::getSubjectDegree() const
{
    double arr[SUBJECT_NUM ];
    for(size_t i=0; i<SUBJECT_NUM ; i++)
    {
        arr[i] = subject_degree_[i];
    }
    return(arr);
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

class Student Student::getClassData() const
{
    class Student std1;
    std1.student_name_ = getStudentName();
    std1.student_id_ = getStudentID();
    std1.average_ = getAverage();
    std1.total_ = getTotal();
    std1.grade_ = getGrade();
    for(size_t i=0 ; i<SUBJECT_NUM ; i++)
    {
        std1.subject_degree_[i] = subject_degree_[i];
    }

    return(std1);
}


void Student::setClassData(const class Student &student_data)
{
    student_name_ = student_data.getStudentName();
    student_id_ = student_data.getStudentID();
    setSubjectDegree(student_data.getSubjectDegree());
    total_ = student_data.getTotal();
    average_ = student_data.getAverage();
    grade_ = student_data.getGrade();
}