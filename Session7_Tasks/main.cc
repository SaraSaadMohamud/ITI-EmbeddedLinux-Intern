#include "student_management.hh"
#include "iostream"



int main()
{
    class Student student1;
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

    std::cout<<"\n============================== Result Manue ================================== \n\n";
    std::cout<<"Name: "<<student1.getStudentName()<<std::endl;
    std::cout<<"ID: "<<student1.getStudentID()<<std::endl;
    std::cout<<"Subjects Total: "<<student1.getTotal()<<std::endl;
    std::cout<<"Average: "<<student1.getAverage()<<std::endl;
    std::cout<<"Grade: "<<student1.getGrade()<<std::endl;
    std::cout<<std::endl;


    return 0;
}