#ifndef _STUDENT_MANAGEMENT_HPP_
#define _STUDENT_MANAGEMENT_HPP_

#include <string>

constexpr std::size_t SUBJECT_NUM = 3;

class Student
{
    public:
    Student();
    ~Student() = default;

    std::string getStudentName() const;
    unsigned int getStudentID() const;
    const double * getSubjectDegree() const;
    double getTotal() const;
    double getAverage() const;
    char getGrade() const ;
    class Student getClassData() const;

    void setStudentName(const std::string &name);
    void setStudentID(const unsigned int &id);
    void setSubjectDegree(const double student_degree[]);
    void setTotal(const double student_degree[]);
    void setAverage(const double &total);
    void setGarade(const char &average);
    void setClassData(const class Student &student_data);

    private:
    std::string student_name_;
    unsigned int student_id_;
    double subject_degree_[SUBJECT_NUM];
    double total_;
    double average_;
    char grade_;
};
#endif /* _STUDENT_MANAGEMENT_HPP_ */