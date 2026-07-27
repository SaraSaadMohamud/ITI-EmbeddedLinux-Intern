#  Library Management System (C++ OOP)

A console-based **Library Management System** implemented in **Modern C++** to demonstrate the fundamental and advanced concepts of **Object-Oriented Programming (OOP)**.

This project was developed as a practical application of C++ OOP principles including inheritance, polymorphism, abstract classes, interfaces, composition, smart pointers, and STL containers.

---

##  Features

- 📖 Book Management
  - Add books
  - Display book information
  - Borrow books
  - Return books
  - Check availability

- 👥 User Management
  - Student
  - Teacher
  - Engineer

- 🏛 Library Management
  - Store books
  - Register users
  - Display library data

- 📊 Object Statistics
  - Total books
  - Total users
  - Total students
  - Total teachers
  - Total engineers

---

# 🏗 Class Diagram

```
                    Borrowable (Interface)
                  +-----------------------+
                  | +borrowBook()         |
                  | +returnBook()         |
                  | +checkAvailability()  |
                  +-----------^-----------+
                              |
                              |
                         +----+-----+
                         |   Book    |
                         +----------+

                          User (Abstract)
                    +----------------------+
                    | name                 |
                    | id                   |
                    +----------^-----------+
                               |
          +--------------------+--------------------+
          |                    |                    |
      Student              Teacher             Engineer

                         Library
                  +----------------------+
                  | vector<Book>         |
                  | vector<unique_ptr>   |
                  +----------------------+
```

---

#  Object-Oriented Programming Concepts

This project demonstrates the following concepts:

- Classes & Objects
- Constructors
- Copy Constructors
- Destructors
- Encapsulation
- Inheritance
- Abstract Classes
- Interfaces
- Runtime Polymorphism
- Composition
- Smart Pointers (`std::unique_ptr`)
- STL Containers (`std::vector`)
- Static Members
- Function Overriding
- Dynamic Dispatch

---

# 📂 Project Structure

```
Library-Management-System/
│
├── LibraryManagementSystem.hh
├── LibraryManagementSystem.cpp
├── main.cpp
└── README.md
```

---

#  Class Overview

##  Book

Represents a library book.

### Responsibilities

- Store book information
- Borrow a book
- Return a book
- Check availability

---

##  User (Abstract Class)

Base class for all library users.

Derived classes:

- Student
- Teacher
- Engineer

Each derived class overrides

```cpp
displayUserInfo()
```

---

##  Borrowable (Interface)

Defines the common behavior of borrowable resources.

```cpp
virtual bool borrowBook() = 0;
virtual bool returnBook() = 0;
virtual bool checkAvailability() const = 0;
```

---

##  Library

Responsible for managing

- Books
- Users

Uses

```cpp
std::vector<Book>
```

and

```cpp
std::vector<std::unique_ptr<User>>
```

to demonstrate ownership using smart pointers.

---

#  Smart Pointer Usage

The project uses

```cpp
std::unique_ptr<User>
```

instead of raw pointers.

Example

```cpp
lib.addUser(
    std::make_unique<Student>(
        "Sara",
        1001,
        3.8
    )
);
```

Benefits

- Automatic memory management
- No manual `delete`
- Prevents memory leaks
- Exclusive ownership

---

# Runtime Polymorphism

The project demonstrates runtime polymorphism through the `Borrowable` interface.

```cpp
Borrowable* ptr = &book;

ptr->borrowBook();
ptr->returnBook();
```

It also demonstrates polymorphism by storing different derived classes inside

```cpp
std::unique_ptr<User>
```

---

#  Testing

The project contains dedicated testing functions.

```cpp
testBook();
```

Tests

- Constructors
- Copy constructor
- Getters
- Setters
- Borrowing
- Returning

---

```cpp
testUsers();
```

Tests

- Student
- Teacher
- Engineer
- Inheritance
- Overridden functions

---

```cpp
testBorrowable();
```

Tests

- Interface
- Runtime polymorphism

---

```cpp
testLibrary();
```

Tests

- Add books
- Add users
- Smart pointers
- Library display

---

```cpp
printStatistics();
```

Displays

- Book count
- User count
- Student count
- Teacher count
- Engineer count

---

# 🛠 Technologies Used

- C++17
- Object-Oriented Programming
- STL
- Smart Pointers
- g++

---

# ⚙️ Build

Compile using **g++**

```bash
g++ main.cpp LibraryManagementSystem.cpp -o res
```

Run

```bash
./res
```

---

# Learning Objectives

This project was developed to practice

- Modern C++
- Object-Oriented Design
- Class Relationships
- Inheritance
- Runtime Polymorphism
- Abstract Classes
- Interfaces
- Composition
- Memory Management
- Smart Pointers
- STL Containers

---

#  Author

**Sara Saad Mahmoud**

- Electronics & Communication Engineering Student
- Embedded Systems & Robotics Engineer
- Passionate about Modern C++, Embedded Systems, and Robotics

---

#  If you found this project useful

Give it a ⭐ on GitHub.