/**
 * @file association.hpp
 * @brief Demonstrates the Association relationship in Object-Oriented Programming (OOP).
 *
 * This project illustrates the concept of **Association** between two independent
 * classes: Student and Course.
 *
 * In this example:
 * - A Course can interact with a Student object.
 * - Neither class owns the other.
 * - The lifetime of each object is managed independently.
 * - The relationship is established temporarily through member functions.
 *
 * @author Sara Saad Mahmoud
 * @date July 2026
 * @version 1.0
 */

#ifndef _ASSOCATION_HPP_
#define _ASSOCATION_HPP_

#include <string>

/**
 * @class Student
 * @brief Represents a student with basic personal information.
 */
class Student
{
public:
    /**
     * @brief Default constructor.
     */
    Student();

    /**
     * @brief Parameterized constructor.
     * @param name Student name.
     * @param id Student ID.
     * @param age Student age.
     */
    Student(const std::string &name, const unsigned int id, const float age);

    /**
     * @brief Copy constructor.
     * @param obj Student object to copy.
     */
    Student(const Student &obj);

    /**
     * @brief Destructor.
     */
    ~Student();

    /**
     * @brief Gets the student's name.
     * @return Student name.
     */
    const std::string getStudentName() const;

    /**
     * @brief Gets the student ID.
     * @return Student ID.
     */
    unsigned int getStudentID() const;

    /**
     * @brief Gets the student age.
     * @return Student age.
     */
    float getStudentAge() const;

    /**
     * @brief Sets the student's name.
     * @param name New student name.
     */
    void setStudentName(const std::string &name);

    /**
     * @brief Sets the student ID.
     * @param id New student ID.
     */
    void setStudentID(const unsigned int id);

    /**
     * @brief Sets the student's age.
     * @param age New student age.
     */
    void setStudentAge(const float age);

    /**
     * @brief Prints all student information.
     */
    void printStudentInfo() const;

private:
    std::string name_;   /**< Student name. */
    unsigned int id_;    /**< Student ID. */
    float age_;          /**< Student age. */
};

/**
 * @class Course
 * @brief Represents a course with its details.
 *
 * This class demonstrates an Association relationship with the
 * Student class by interacting with a Student object without
 * owning or managing its lifetime.
 */
class Course
{
public:
    /**
     * @brief Default constructor.
     */
    Course();

    /**
     * @brief Parameterized constructor.
     * @param name Course name.
     * @param course_price Course price.
     * @param course_code Course code.
     */
    Course(const std::string &name, double course_price, unsigned int course_code);

    /**
     * @brief Copy constructor.
     * @param obj Course object to copy.
     */
    Course(const Course &obj);

    /**
     * @brief Destructor.
     */
    ~Course();

    /**
     * @brief Gets the course name.
     * @return Course name.
     */
    const std::string getCourseName() const;

    /**
     * @brief Gets the course price.
     * @return Course price.
     */
    double getCoursePrice() const;

    /**
     * @brief Gets the course code.
     * @return Course code.
     */
    unsigned int getCourseCode() const;

    /**
     * @brief Sets the course name.
     * @param name New course name.
     */
    void setCourseName(const std::string &name);

    /**
     * @brief Sets the course price.
     * @param price New course price.
     */
    void setCoursePrice(double price);

    /**
     * @brief Sets the course code.
     * @param code New course code.
     */
    void setCourseCode(unsigned int code);

    /**
     * @brief Prints the course information.
     */
    void printCourseInfo() const;

    /**
     * @brief Displays information about a student enrolled in the course.
     *
     * This function demonstrates an Association relationship by using
     * a Student object without owning it.
     *
     * @param student Reference to an existing Student object.
     */
    void showCourseStudent(Student &student) const;

private:
    std::string name_;           /**< Course name. */
    double course_price_;        /**< Course price. */
    unsigned int course_code_;   /**< Course code. */
};

#endif /* _ASSOCATION_HPP_ */