/**
 * @file student_management.hh
 * @brief Declaration of the Student class.
 *
 * This file contains the declaration of the Student class, which provides
 * functionality for storing and managing student information such as
 * name, ID, subject grades, total score, average score, and final grade.
 *
 * @author Sara Saad
 * @date July 2026
 */

#ifndef _STUDENT_MANAGEMENT_HPP_
#define _STUDENT_MANAGEMENT_HPP_

#include <string>

/**
 * @brief Number of subjects for each student.
 */
constexpr std::size_t SUBJECT_NUM = 3;

/**
 * @class Student
 * @brief Represents a student's academic record.
 *
 * The Student class stores student information including:
 * - Student name
 * - Student ID
 * - Subject grades
 * - Total marks
 * - Average marks
 * - Letter grade
 */
class Student
{
    public:
    /**
     * @brief Constructs a Student object with default values.
     */
    Student();

    /**
     * @brief Default destructor.
     */
    ~Student() = default;

    /**
     * @brief Gets the student's name.
     * @return Student name.
    */
    std::string getStudentName() const;

     /**
     * @brief Gets the student's ID.
     * @return Student ID.
     */
    unsigned int getStudentID() const;

    /**
     * @brief Gets the subject grades.
     * @return Pointer to the subject grades array.
     */
    const double * getSubjectDegree() const;

    /**
     * @brief Gets the student's total marks.
     * @return Total marks.
     */
    double getTotal() const;

    /**
     * @brief Gets the student's average marks.
     * @return Average marks.
     */
    double getAverage() const;

    /**
     * @brief Gets the student's letter grade.
     * @return Grade character.
     */
    char getGrade() const ;

      /**
     * @brief Prints all student information.
     */
    void printStudent() const;

    /**
     * @brief Sets the student's name.
     * @param name Student name.
     */
    void setStudentName(const std::string &name);

    /**
     * @brief Sets the student's ID.
     * @param id Student ID.
     */
    void setStudentID(const unsigned int &id);

    /**
     * @brief Sets the subject grades.
     * @param student_degree Array containing subject grades.
     */
    void setSubjectDegree(const double student_degree[]);

    /**
     * @brief Calculates and stores the total marks.
     * @param student_degree Array containing subject grades.
     */
    void setTotal(const double student_degree[]);

    /**
     * @brief Calculates and stores the average marks.
     * @param total Total marks.
     */
    void setAverage(const double &total);

     /**
     * @brief Determines the student's letter grade.
     * @param average Student average marks.
     */
    void setGarade(const double &average);

    /**
     * @brief Sets all student information at once.
     *
     * This function initializes the student's name, ID,
     * subject grades, total, average, and letter grade.
     *
     * @param name Student name.
     * @param id Student ID.
     * @param student_degree Array containing subject grades.
     */
    void setClassData(const std::string &name, const unsigned int &id, const double student_degree[]);

    private:
    std::string student_name_;
    unsigned int student_id_;
    double subject_degree_[SUBJECT_NUM];
    double total_;
    double average_;
    char grade_;
};
#endif /* _STUDENT_MANAGEMENT_HPP_ */