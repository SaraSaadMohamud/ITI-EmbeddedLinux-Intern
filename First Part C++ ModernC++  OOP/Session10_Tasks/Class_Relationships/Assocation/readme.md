# Association Relationship in Object-Oriented Programming (OOP) using C++

## Overview

This project demonstrates the **Association** relationship in **Object-Oriented Programming (OOP)** using C++.

The project contains two independent classes:

- **Student**
- **Course**

The `Course` class interacts with a `Student` object through a member function without owning or managing the lifetime of the `Student` object. This design represents the **Association** relationship, where two objects communicate while remaining completely independent.

---

# Learning Objectives

After completing this project, you will understand:

- Object-Oriented Programming (OOP) principles.
- The concept of **Association** between classes.
- Creating and using multiple classes.
- Constructors and destructors.
- Copy constructors.
- Getter and Setter methods.
- Passing objects by reference.
- Const member functions.
- Class encapsulation.

---

# What is Association?

Association is an OOP relationship where **two independent objects collaborate or communicate without owning each other**.

Neither object controls the lifetime of the other.

If one object is destroyed, the other object continues to exist.

### Characteristics

- Objects are independent.
- One object uses another object.
- No ownership exists.
- Lifetime of each object is managed separately.
- Can be implemented using pointers, references, or function parameters.

---

# Project Scenario

This project simulates a simple educational system.

There are two classes:

## Student

Represents a student containing:

- Student Name
- Student ID
- Student Age

The class can:

- Store student information.
- Print student information.
- Modify student data using setters.
- Retrieve data using getters.

---

## Course

Represents a course containing:

- Course Name
- Course Price
- Course Code

The class can:

- Store course information.
- Print course information.
- Display information about a student enrolled in the course.

Notice that the course **does not own** a student object.

Instead, it simply receives a `Student` object as a reference.

```cpp
void showCourseStudent(Student &student) const;
```

This function demonstrates the Association relationship.

---

# Project Structure

```text
.
├── main.cpp
├── Assocation.hh
├── Assocation.cpp
└── README.md
```

---

# UML Class Diagram

```text
+---------------------+
|      Student        |
+---------------------+
| - name_             |
| - id_               |
| - age_              |
+---------------------+
| + printStudentInfo()|
| + getters           |
| + setters           |
+---------------------+

          ▲
          │
          │ Association
          │

+---------------------------+
|          Course           |
+---------------------------+
| - name_                   |
| - course_price_           |
| - course_code_            |
+---------------------------+
| + printCourseInfo()       |
| + showCourseStudent()     |
+---------------------------+
```

---

# Class Description

## Student Class

### Private Data Members

| Variable | Description |
|----------|-------------|
| `name_` | Student name |
| `id_` | Student ID |
| `age_` | Student age |

### Public Member Functions

- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor
- Getters
- Setters
- `printStudentInfo()`

---

## Course Class

### Private Data Members

| Variable | Description |
|----------|-------------|
| `name_` | Course name |
| `course_price_` | Course price |
| `course_code_` | Course code |

### Public Member Functions

- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor
- Getters
- Setters
- `printCourseInfo()`
- `showCourseStudent(Student&)`

---

# Demonstrating Association

The following function creates the association:

```cpp
void Course::showCourseStudent(Student &student) const
{
    student.printStudentInfo();
}
```

### Why is this Association?

Because:

- `Course` does not contain a `Student` object.
- `Course` does not allocate memory for a `Student`.
- `Course` does not destroy a `Student`.
- The student object already exists before being passed to the function.
- Both classes are completely independent.

---

# Main Function

```cpp
int main()
{
    Student s1("Sara", 100, 23.0);

    Course c1("Linux", 5000.0, 100);

    c1.showCourseStudent(s1);

    c1.printCourseInfo();

    return 0;
}
```

### Execution Flow

1. Create a `Student` object.
2. Create a `Course` object.
3. Pass the `Student` object to the `Course`.
4. Display the student's information.
5. Display the course's information.
6. Destroy both objects independently.

---

# Sample Output

```text
Parametrize Constructor Called!
Parametrize Constructor Called!

============== Student Information ==================
Name    : Sara
ID      : 100
Age     : 23
=====================================================

============== Course Information ===================
Name    : Linux
Price   : 5000
Code    : 100
=====================================================

Default Destructor Called!
Default Destructor Called!
```

---

# Why This Is NOT Aggregation

Aggregation usually means one class stores references or pointers to other objects as part of its internal state.

Example:

```cpp
class Course
{
private:
    Student* student;
};
```

In this project, the `Course` class does **not** store a `Student` object or pointer.

Instead, the student object is only passed temporarily to a member function.

---

# Why This Is NOT Composition

Composition means one object owns another object.

Example:

```cpp
class Course
{
private:
    Student student;
};
```

If the `Course` object is destroyed, the owned `Student` object is also destroyed.

This project does **not** implement Composition because the `Student` object is created independently and is not owned by the `Course`.

---

# OOP Concepts Used

- Encapsulation
- Association
- Constructors
- Copy Constructors
- Destructors
- Getter and Setter Methods
- Const Member Functions
- Object Interaction
- Passing Objects by Reference

---

# Advantages of Association

- Loose coupling between classes.
- Better code reusability.
- Independent object lifetimes.
- Easier maintenance.
- Improved modularity.

---

# Build Instructions

### Linux / macOS

```bash
g++ main.cpp Assocation.cpp -o association
./association
```

### Windows (MinGW)

```bash
g++ main.cpp Assocation.cpp -o association.exe
association.exe
```

---

# Conclusion

This project provides a simple yet effective demonstration of the **Association** relationship in C++.

The `Student` and `Course` classes remain completely independent while interacting through function parameters. Since neither class owns or manages the lifetime of the other, the relationship accurately represents **Association**.

This project is suitable for beginners learning object-oriented programming and serves as a practical example of implementing relationships between classes in C++.