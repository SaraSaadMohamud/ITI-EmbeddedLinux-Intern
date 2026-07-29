/**
 * @file LibraryManagementSystem.hh
 * @author Sara Saad Mahmoud
 * @brief Library Management System implemented using Object-Oriented Programming concepts.
 *
 * This project demonstrates:
 * - Classes and Objects
 * - Constructors & Destructors
 * - Inheritance
 * - Abstract Classes
 * - Interfaces
 * - Runtime Polymorphism
 * - Composition
 * - Smart Pointers (std::unique_ptr)
 * - STL Containers (std::vector)
 */

#ifndef _LIBRARY_MANAGEMENT_SYSTEM_HPP_
#define _LIBRARY_MANAGEMENT_SYSTEM_HPP_

#include <vector>
#include <string>
#include <memory>

/**
 * @brief Maximum number of books supported by the library.
 */
constexpr unsigned int max_books_num = 100;

/**
 * @brief Interface representing borrowable library resources.
 */
class Borrowable
{
public:

    /**
     * @brief Borrow a book.
     * @return true if borrowing succeeded, otherwise false.
     */
    virtual bool borrowBook() = 0;

    /**
     * @brief Return a borrowed book.
     * @return true if returning succeeded, otherwise false.
     */
    virtual bool returnBook() = 0;

    /**
     * @brief Check whether a book is available.
     * @return true if available.
     */
    virtual bool checkAvailability() const = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Borrowable() = default;
};

/**
 * @brief Represents a library book.
 */
class Book : public Borrowable
{
public:

    /**
     * @brief Number of Book objects.
     */
    static unsigned int book_count;

    Book();

    /**
     * @brief Construct a new Book object.
     * @param title Book title.
     * @param author Book author.
     * @param book_id Unique book ID.
     * @param is_available Book availability.
     */
    Book(const std::string &title,
         const std::string &author,
         unsigned int book_id,
         bool is_available);

    /**
     * @brief Copy constructor.
     * @param obj Book object.
     */
    Book(const Book &obj);

    /**
     * @brief Destroy the Book object.
     */
    virtual ~Book();

    /**
     * @return Book title.
     */
    const std::string &getBookTitle() const;

    /**
     * @return Book author.
     */
    const std::string &getBookAuthor() const;

    /**
     * @return Book ID.
     */
    unsigned int getBookID() const;

    /**
     * @return Book availability.
     */
    bool getBookStatus() const;

    /**
     * @brief Set the book title.
     * @param title New title.
     */
    void setBookTitle(const std::string &title);

    /**
     * @brief Set the author name.
     * @param author Author name.
     */
    void setBookAuthor(const std::string &author);

    /**
     * @brief Set the book ID.
     * @param id Book ID.
     */
    void setBookID(unsigned int id);

    /**
     * @brief Set the availability state.
     * @param state Availability status.
     */
    void setBookState(bool state);

    /**
     * @brief Print book information.
     */
    void displayBookInfo() const;

    bool borrowBook() override;
    bool returnBook() override;
    bool checkAvailability() const override;

    /**
     * @brief Get total number of Book objects.
     * @return Number of books.
     */
    static unsigned int getBookCount();

private:

    std::string title_;
    std::string author_;
    unsigned int book_id_;
    bool is_available_;
};

/**
 * @brief Abstract base class representing a library user.
 */
class User
{
public:

    static unsigned int user_count_;

    User();

    /**
     * @brief Construct a User.
     * @param name User name.
     * @param id User ID.
     */
    User(const std::string &name,
         unsigned int id);

    User(const User &obj);

    virtual ~User();

    /**
     * @return User name.
     */
    const std::string &getUserName() const;

    /**
     * @return User ID.
     */
    unsigned int getUserID() const;

    /**
     * @brief Set user name.
     * @param name User name.
     */
    void setUserName(const std::string &name);

    /**
     * @brief Set user ID.
     * @param id User ID.
     */
    void setUserID(unsigned int id);

    /**
     * @brief Print user information.
     */
    virtual void displayUserInfo() const = 0;

    /**
     * @brief Get total number of User objects.
     * @return User count.
     */
    static unsigned int getUserCount();

protected:

    std::string name_;
    unsigned int id_;
};

/**
 * @brief Represents a student user.
 */
class Student : public User
{
public:

    static unsigned int student_count;

    Student();

    Student(const std::string &name,
            unsigned int id,
            double gpa);

    Student(const Student &obj);

    ~Student() override;

    void displayUserInfo() const override;

    /**
     * @return Student GPA.
     */
    double getStudentGPA() const;

    /**
     * @brief Set student GPA.
     * @param gpa Student GPA.
     */
    void setStudentGPA(const double gpa);

    /**
     * @return Number of students.
     */
    static unsigned int getStudentCount();

private:

    double gpa_;
};

/**
 * @brief Represents a teacher.
 */
class Teacher : public User
{
public:

    static unsigned int teacher_count;

    Teacher();

    Teacher(const std::string &name,
            unsigned int id,
            double salary);

    Teacher(const Teacher &obj);

    ~Teacher() override;

    void displayUserInfo() const override;

    /**
     * @return Teacher salary.
     */
    double getTeacherSalary() const;

    /**
     * @brief Set teacher salary.
     * @param salary Teacher salary.
     */
    void setTeacherSalary(const double salary);

    /**
     * @return Number of teachers.
     */
    static unsigned int getTeacherCount();

private:

    double salary_;
};

/**
 * @brief Represents an engineer.
 */
class Engineer : public User
{
public:

    static unsigned int engineer_count;

    Engineer();

    Engineer(const std::string &name,
             unsigned int id,
             const std::string &specialization);

    Engineer(const Engineer &obj);

    ~Engineer() override;

    void displayUserInfo() const override;

    /**
     * @return Engineer specialization.
     */
    const std::string &getEngineerSpecialization() const;

    /**
     * @brief Set engineer specialization.
     * @param specialization Engineer specialization.
     */
    void setEngineerSpecialization(const std::string &specialization);

    /**
     * @return Number of engineers.
     */
    static unsigned int getEnginnerCount();

private:

    std::string specialization_;
};

/**
 * @brief Represents the library system.
 *
 * The library owns:
 * - A collection of books.
 * - A collection of users using std::unique_ptr.
 */
class Library
{
public:

    Library();

    /**
     * @brief Construct a library.
     * @param books Collection of books.
     * @param users Collection of users.
     */
    Library(const std::vector<Book> &books,
            std::vector<std::unique_ptr<User>> users);

    Library(Library &) = delete;

    Library &operator=(const Library &) = delete;

    ~Library();

    /**
     * @brief Add a book to the library.
     * @param book Book object.
     */
    void addBook(const Book &book);

    /**
     * @brief Add a user to the library.
     * @param user User object.
     */
    void addUser(std::unique_ptr<User> user);

    /**
     * @brief Display all books.
     */
    void displayLibraryBooks() const;

    /**
     * @brief Display all users.
     */
    void displayLibraryUsers() const;

    /**
     * @return Collection of books.
     */
    const std::vector<Book> &getLibraryBooks() const;

    /**
     * @return Collection of users.
     */
    const std::vector<std::unique_ptr<User>> &getLibraryUsers() const;

private:

    std::vector<Book> books_;
    std::vector<std::unique_ptr<User>> users_;
};

#endif /* _LIBRARY_MANAGEMENT_SYSTEM_HPP_ */