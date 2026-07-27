/**
 * @file LibraryManagementSystem.cpp
 * @author Sara Saad Mahmoud
 * @brief Implementation of the Library Management System classes.
 * @version 1.0
 * @date Jul, 2026
 *
 * @details
 * This source file implements all member functions declared in
 * LibraryManagementSystem.hh.
 *
 * Implemented Classes:
 * - Book
 * - User
 * - Student
 * - Teacher
 * - Engineer
 * - Library
 *
 * Features:
 * - Book borrowing and returning
 * - User inheritance and runtime polymorphism
 * - Smart pointer ownership using std::unique_ptr
 * - Library book/user management
 */

#include "LibraryManagementSystem.hh"
#include <iostream>

unsigned int Book::book_count = 0;

Book::Book(): title_(""),author_(""),book_id_(0),is_available_(true)
{
   std::cout<<"Default Book Constructor Called!\n";
   book_count++;
}

Book::Book(const std::string &title, const std::string &author,
           unsigned int book_id, bool is_available)
{
    title_          = title;
    author_         = author;
    book_id_        = book_id;
    is_available_    = is_available;
    std::cout<<"Parameterized Book Constructor Called!\n";
    book_count++;
}

Book::Book(const Book &obj)
{
    title_          = obj.title_;
    author_         = obj.author_;
    book_id_        = obj.book_id_;
    is_available_    = obj.is_available_;
    std::cout<<"Copy Book Constructor Called!\n";
    book_count++;
}

Book::~Book()
{
    std::cout<<"Default Book Destructor Called!\n";
    book_count--;
}

const std::string &Book::getBookTitle() const
{
    return(this->title_);
}

const std::string &Book::getBookAuthor() const
{
    return(this->author_);
}

unsigned int Book::getBookID() const
{
    return(this->book_id_);
}

bool Book::getBookStatus() const
{
    return(this->is_available_);
}

void Book::setBookTitle(const std::string &title)
{
    title_ = title;
}

void Book::setBookAuthor(const std::string &author)
{
    author_ = author;
}

void Book::setBookID(unsigned int id)
{   
    book_id_ = id;
}

void Book::setBookState(bool state)
{
    is_available_ = state;
}

void Book::displayBookInfo() const
{
    std::cout<<"--------------------- Book General Data -------------------\n";
    std::cout<<"Title            : "<<title_                         <<std::endl;
    std::cout<<"Author           : "<<author_                        <<std::endl;
    std::cout<<"ID               : "<<book_id_                       <<std::endl;
    std::cout<<"Is Book Available: "<<std::boolalpha<<is_available_  <<std::endl;
}

bool Book::borrowBook()
{
    if(is_available_ == true)
    {
        std::cout<<"Book is Available, you can Borrow it!.\n";
        is_available_ = false;
        return(true);
    }
    else
    {
        std::cout<<"Book isn't Available, You can't borrow right now!.\n";
        return(false);
    }
}

bool Book::returnBook()
{
    if(is_available_ == true)
    {
        std::cout<<"The book has already been returned.\n";
        return(false);
    }
    else
    {
        std::cout<<"Book Successfully Returned to the Library!.\n";
        is_available_ = true;
        return(true);
    }
}

bool Book::checkAvailability() const
{
    return getBookStatus();
}

unsigned int Book::getBookCount()
{
    return book_count;
}

/*==============================================================================================================================================*/

unsigned int User::user_count_ = 0;

User::User(): name_(""), id_(0)
{   
    std::cout<<"Default User Constructor Called!\n";
    ++user_count_;
}

User::User(const std::string &name, unsigned int id): name_(name), id_(id)
{   
    std::cout<<"Parameterized User Constructor Called!\n";
    ++user_count_;
}

User::User(const User &obj): name_(obj.name_), id_(obj.id_)
{
    std::cout<<"Copy User Constructor Called!\n";
    ++user_count_;
}

User::~User()
{
    std::cout<<"Default User Destructor Called!\n";
    --user_count_;
}

const std::string &User::getUserName() const
{
    return(name_);
}

unsigned int User::getUserID() const
{
    return(id_);
}

void User::setUserName(const std::string &name)
{
    name_ = name;
}

void User::setUserID(unsigned int id)
{
    id_ = id;
}

unsigned int User::getUserCount()
{
    return(user_count_);
}

/*==============================================================================================================================================*/

unsigned int Student::student_count = 0;

Student::Student() : User(), gpa_(0.0)
{
    std::cout<<"Default Student Constructor Called!\n";
    ++student_count;
}

Student::Student(const std::string &name, unsigned int id, double gpa): User(name, id), gpa_(gpa)
{
    std::cout<<"Parameterized Student Constructor Called!\n";
    ++student_count;
}

Student::Student (const Student &obj): User(obj), gpa_(obj.gpa_)
{
    std::cout<<"Copy Student Constructor Called!\n";
    ++student_count;
}

Student::~Student() 
{
    std::cout<<"Default Student Destructor Called!\n";
    --student_count;
}

void Student::displayUserInfo() const
{
    std::cout<<"-------------------- Student Name --------------------\n";
    std::cout<<"Name    : "<<name_  <<std::endl;
    std::cout<<"ID      : "<<id_    <<std::endl;
    std::cout<<"GPA     : "<<gpa_   <<std::endl;
}

double Student::getStudentGPA() const
{
    return (gpa_);
}

void  Student::setStudentGPA(const double gpa)
{
    gpa_ = gpa;
}


unsigned int Student::getStudentCount()
{
    return(student_count);
}

/*==============================================================================================================================================*/
unsigned int Teacher::teacher_count = 0;

Teacher::Teacher(): User(), salary_(0)
{
    std::cout<<"Default Teacher Constructor Called!\n";
    ++teacher_count;
}
Teacher::Teacher (const std::string &name, unsigned int id, double salary): User(name, id), salary_(salary)
{
    std::cout<<"Parameterized Teacher Constructor Called!\n";
    ++teacher_count;
}

Teacher::Teacher (const Teacher &obj) : User(obj) , salary_(obj.salary_)
{
    std::cout<<"Copy Teacher Constructor Called!\n";
    ++teacher_count;
}

Teacher::~Teacher() 
{
    std::cout<<"Default Teacher Destructor Called!\n";
    --teacher_count;
}

void Teacher::displayUserInfo() const 
{
    std::cout<<"----------------- Teacher Data ---------------------\n";
    std::cout<<"Name    : "<<name_      <<std::endl;
    std::cout<<"ID      : "<<id_        <<std::endl;
    std::cout<<"Salary  : "<<salary_   <<std::endl;
}

double Teacher::getTeacherSalary() const
{
    return(salary_);
}

void Teacher::setTeacherSalary(const double salary)
{
    salary_ = salary;
}

unsigned int Teacher::getTeacherCount()
{
    return(teacher_count);
}

/*==============================================================================================================================================*/

unsigned int Engineer::engineer_count = 0;

Engineer::Engineer(): User(), specialization_("")
{
    std::cout<<"Default Engineer Constructor Called!\n";
    engineer_count++;
}

Engineer::Engineer(const std::string &name, unsigned int id, const std::string &specialization): User(name, id), specialization_(specialization)
{
    std::cout<<"Parameterized Egineer Constructor Called!\n";
    engineer_count++;
}

Engineer::Engineer(const Engineer &obj) : User(obj), specialization_(obj.specialization_)
{
    std::cout<<"Copy Engineer Constructor Called!\n";
    engineer_count++;
}

Engineer::~Engineer() 
{       
    std::cout<<"Default Enginner Destructor Called!\n";
    engineer_count--;
}

void Engineer::displayUserInfo() const
{
    std::cout<<"----------------- Engineer Data ---------------------\n";
    std::cout<<"Name            : "<<name_              <<std::endl;
    std::cout<<"ID              : "<<id_                <<std::endl;
    std::cout<<"Specialization  : "<<specialization_    <<std::endl;
}

const std::string &Engineer::getEngineerSpecialization() const
{
    return(specialization_);
}

void Engineer::setEngineerSpecialization(const std::string &specialization)
{
    specialization_ = specialization;
}

unsigned int Engineer::getEnginnerCount()
{
    return(engineer_count);
}

/*==============================================================================================================================================*/

Library::Library() : books_(), users_()
{
    std::cout<<"Default Library Constructor Called!\n";
}

Library::Library(const std::vector<Book> &books, std::vector<std::unique_ptr<User>> users) : books_(books), users_(std::move(users))
{
    std::cout<<"Parameterized Library Constructor Called!\n";
}

Library::~Library()
{
    std::cout<<"Default Library Destructor Called!\n";
}

void Library::addBook(const Book &book)
{
    books_.push_back(book);
}

void Library::addUser(std::unique_ptr<User> user)
{
    users_.push_back(std::move(user));
}

void Library::displayLibraryBooks() const
{
    for(auto i=books_.begin() ; i < books_.end() ; ++i)
    {
        i->displayBookInfo();
    }
}

void Library::displayLibraryUsers() const
{
    for(auto i= users_.begin() ; i < users_.end() ; ++i)
    {
       (*i)->displayUserInfo();
    }
}

const std::vector<Book> &Library::getLibraryBooks() const
{
    return books_;
}

const std::vector<std::unique_ptr<User>> &Library::getLibraryUsers() const
{
    return users_;
}

/*==============================================================================================================================================*/