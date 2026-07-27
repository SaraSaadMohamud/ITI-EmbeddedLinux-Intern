/**
 * @file main.cpp
 * @author Sara Saad Mahmoud
 * @brief Test driver for the Library Management System.
 * @version 1.0
 * @date Jul, 2026
 *
 * @details
 * This file demonstrates and validates the functionality of the
 * Library Management System by creating objects and invoking
 * their public interfaces.
 *
 * The following features are tested:
 * - Book construction and manipulation
 * - User inheritance hierarchy
 * - Runtime polymorphism
 * - Borrowable interface
 * - Library management
 * - Object statistics using static members
 */

#include "LibraryManagementSystem.hh"
#include <iostream>
/**
 * @brief Tests all Book class functionalities.
 *
 * This function verifies:
 * - Constructors
 * - Getters
 * - Setters
 * - Book information display
 * - Borrowing and returning books
 * - Availability checking
 * - Static object counter
 *
 * @param b1 Default constructed book.
 * @param b2 Parameterized book.
 * @param b3 Parameterized book.
 * @param b4 Copy constructed book.
 */
void testBook(Book &b1,Book &b2, Book &b3, Book &b4);

/**
 * @brief Tests the User hierarchy.
 *
 * This function validates:
 * - Student
 * - Teacher
 * - Engineer
 * objects and their overridden member functions.
 *
 * @param s1 Student object.
 * @param t1 Teacher object.
 * @param e1 Engineer object.
 */
void testUsers(Student &s1, Teacher &t1, Engineer &e1);

/**
 * @brief Tests runtime polymorphism using the Borrowable interface.
 *
 * Demonstrates dynamic dispatch through a Borrowable pointer.
 *
 * @param b2 Book object implementing Borrowable.
 */
void testBorrowable(Book &b2);

/**
 * @brief Tests Library management operations.
 *
 * This function verifies:
 * - Adding books
 * - Adding users
 * - Smart pointer ownership
 * - Displaying stored books
 * - Displaying registered users
 *
 * @param lib Library object.
 * @param b1 Book object.
 * @param b2 Book object.
 * @param b3 Book object.
 */
void testLibrary(Library &lib, Book &b1,Book &b2, Book &b3);

/**
 * @brief Prints statistics of all created objects.
 *
 * Displays the total numbers of:
 * - Books
 * - Users
 * - Students
 * - Teachers
 * - Engineers
 */
void printStatistics();

int main()
{
    Book b1;
    Book b2("Clean Code","Robert C. Martin", 1001, true);
    Book b3 = {"Design Patterns", "Erich Gamma",1002,true};
    Book b4(b3);
    Student s1("Mariam",1001,80.0);
    Teacher t1("Ahmed",2001,10000.0);
    Engineer e1("Sara",3001,"Embedded");
    Library lib;

    testBook(b1,b2,b3,b4);

    testUsers(s1,t1,e1);

    testBorrowable(b2);

    testLibrary(lib,b1,b2,b3);

    printStatistics();

    return 0;
}

void testBook(Book &b1,Book &b2, Book &b3, Book &b4)
{
    std::cout << "\n================ Book Test ================\n";

    std::cout<<b2.getBookAuthor()<<std::endl;
    std::cout<<b3.getBookTitle()<<std::endl;
    std::cout<<b4.getBookID()<<std::endl;

    b1.setBookState(false);

    b1.displayBookInfo();
    b2.displayBookInfo();
    b3.displayBookInfo();
    b4.displayBookInfo();

    b2.borrowBook();
    std::cout<<b2.checkAvailability()<<std::endl;
    b2.borrowBook();

    b2.returnBook();
    b3.returnBook();
    b2.returnBook();
    b2.checkAvailability();

    std::cout<<"Book Numbers: "<<Book::getBookCount()<<std::endl;
}

void testUsers(Student &s1, Teacher &t1, Engineer &e1)
{
    std::cout << "\n========== User Test ==========\n";

    s1.displayUserInfo();
    t1.displayUserInfo();
    e1.displayUserInfo();

    s1.setStudentGPA(85.0);
    t1.setTeacherSalary(15000.0);
    e1.setEngineerSpecialization("Robotics");

    std::cout<<s1.getStudentGPA()<<std::endl;
    std::cout<<t1.getTeacherSalary()<<std::endl;
    std::cout<<e1.getEngineerSpecialization()<<std::endl;

    std::cout<<Student::getStudentCount()   <<std::endl;
    std::cout<<Teacher::getTeacherCount()   <<std::endl;
    std::cout<<Engineer::getEnginnerCount() <<std::endl;
}

void testBorrowable(Book &b2)
{

    Borrowable* ptr = &b2;
    ptr->borrowBook();
    ptr->checkAvailability();
    ptr->returnBook();
}

void testLibrary(Library &lib, Book &b1,Book &b2, Book &b3)
{
    std::cout<< "\n========== Library Test ==========\n";

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    lib.addUser(std::make_unique<Student>("Sara",1001,3.8));
    lib.addUser(std::make_unique<Teacher>("Ali",2002,12000));   
    lib.addUser(std::make_unique<Engineer>("Mona",3003,"Embedded"));

    lib.displayLibraryBooks();
    lib.displayLibraryUsers();

}
void printStatistics()
{
    std::cout
    << "\n========== Statistics ==========\n";

    std::cout
    << "Books     : "
    << Book::getBookCount()
    << '\n';

    std::cout
    << "Users     : "
    << User::getUserCount()
    << '\n';

    std::cout
    << "Students  : "
    << Student::getStudentCount()
    << '\n';

    std::cout
    << "Teachers  : "
    << Teacher::getTeacherCount()
    << '\n';

    std::cout
    << "Engineers : "
    << Engineer::getEnginnerCount()
    << '\n';
}