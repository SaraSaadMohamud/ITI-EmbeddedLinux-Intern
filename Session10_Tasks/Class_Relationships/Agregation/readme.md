# Aggregation Relationship in Object-Oriented Programming (OOP) using C++

## Overview

This project demonstrates the **Aggregation** relationship in **Object-Oriented Programming (OOP)** using C++.

The project consists of two independent classes:

- **Employee**
- **Department**

The `Department` class stores pointers to `Employee` objects without owning or managing their lifetime. This design represents an **Aggregation** relationship, where one object contains references to other independent objects.

---

# Learning Objectives

After completing this project, you will understand:

- Object-Oriented Programming (OOP) fundamentals.
- The Aggregation relationship.
- Difference between Association, Aggregation, and Composition.
- Constructors and Destructors.
- Copy Constructors.
- Getter and Setter methods.
- Using `std::vector`.
- Working with pointers.
- Passing objects by reference.
- Encapsulation.

---

# What is Aggregation?

Aggregation is a **"has-a"** relationship between two classes where one class contains objects of another class **without owning them**.

The contained objects exist independently of the container object.

If the container object is destroyed, the contained objects continue to exist.

---

# Characteristics of Aggregation

- Weak ownership.
- Independent object lifetime.
- Objects can exist separately.
- One class stores references or pointers to another class.
- Destruction of the container does not destroy the contained objects.

---

# Project Scenario

This project simulates a simple company management system.

A company department contains multiple employees.

The department can display employee information, but it is **not responsible** for creating or destroying employee objects.

---

# Classes

## Employee

Represents an employee in the company.

### Data Members

| Variable | Description |
|----------|-------------|
| `name_` | Employee name |
| `id_` | Employee ID |
| `salary_` | Employee salary |

### Member Functions

- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor
- Getters
- Setters
- `printEmployeeInfo()`

---

## Department

Represents a department inside a company.

### Data Members

| Variable | Description |
|----------|-------------|
| `name_` | Department name |
| `id_` | Department ID |
| `employee_` | Vector of pointers to Employee objects |

```cpp
std::vector<Employee*> employee_;
```

### Member Functions

- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Destructor
- Getters
- Setters
- `printDepartmentInfo()`

---

# Project Structure

```text
.
├── main.cpp
├── Agregation.hh
├── Agregation.cpp
└── README.md
```

---

# UML Class Diagram

```text
                 +----------------------+
                 |      Employee        |
                 +----------------------+
                 | - name_              |
                 | - id_                |
                 | - salary_            |
                 +----------------------+
                 | + printEmployeeInfo()|
                 | + Getters            |
                 | + Setters            |
                 +----------------------+

                          ▲
                          │
                          │ Aggregation
                          │
+------------------------------------------------+
|                  Department                    |
+------------------------------------------------+
| - name_                                        |
| - id_                                          |
| - employee_ : vector<Employee*>                |
+------------------------------------------------+
| + printDepartmentInfo()                        |
| + Getters                                      |
| + Setters                                      |
+------------------------------------------------+
```

---

# Demonstrating Aggregation

The aggregation relationship is implemented using:

```cpp
std::vector<Employee*> employee_;
```

The department stores pointers to employee objects.

The employees are created outside the department and passed to it.

```cpp
Employee e1("Sara",50,15000);
Employee e2("Ahmed",55,11000);

std::vector<Employee*> employees =
{
    &e1,
    &e2
};

Department d1("Valeo",1050,employees);
```

Notice that the department does **not** create the employees.

Likewise, it does **not** destroy them.

---

# Why is this Aggregation?

Because:

- Employee objects are created outside the Department.
- Department only stores pointers.
- Department does not allocate memory for employees.
- Department does not delete employee objects.
- Employees continue to exist independently.

---

# Main Function

```cpp
int main()
{
    Employee e1("Sara",50,15000.0);
    Employee e2("Ahmed",55,11000.0);
    Employee e3("Adel",60,10000.0);

    std::vector<Employee*> vec1 =
    {
        &e1,
        &e2,
        &e3
    };

    Department d1("Valeo",1050,vec1);

    d1.printDepartmentInfo();

    return 0;
}
```

---

# Execution Flow

1. Create three Employee objects.
2. Store their addresses inside a vector.
3. Create one Department object.
4. Pass the vector to the Department.
5. Department stores the pointers.
6. Department prints all employee information.
7. Employee objects remain alive independently.
8. Department is destroyed.
9. Employee objects are destroyed automatically when `main()` ends.

---

# Sample Output

```text
Parameterized Constructor Called!
Parameterized Constructor Called!
Parameterized Constructor Called!

Parameterized Constructor Called!

Department Name: Valeo
Department ID: 1050

=============== Employee Data ===============
Name    : Sara
ID      : 50
Salary  : 15000
=============================================

-----------------------------------------------------------

=============== Employee Data ===============
Name    : Ahmed
ID      : 55
Salary  : 11000
=============================================

-----------------------------------------------------------

=============== Employee Data ===============
Name    : Adel
ID      : 60
Salary  : 10000
=============================================

Default Destructor Called!
Default Destructor Called!
Default Destructor Called!
Default Destructor Called!
```

---

# Why This Is NOT Association

Association means objects simply interact with one another.

Example:

```cpp
void Department::showEmployee(Employee& emp);
```

The department does not keep any reference to the employee.

In this project, the department stores employee pointers inside a vector.

Therefore, this is **Aggregation**, not Association.

---

# Why This Is NOT Composition

Composition represents **strong ownership**.

Example:

```cpp
class Department
{
private:
    Employee employee;
};
```

or

```cpp
std::vector<Employee> employees;
```

In Composition:

- Department owns Employee objects.
- Destroying the Department also destroys its employees.

This project does not do that.

Instead, it stores pointers to independently existing employees.

---

# OOP Concepts Used

- Encapsulation
- Aggregation
- Constructors
- Copy Constructors
- Destructors
- Getter Functions
- Setter Functions
- Const Member Functions
- Pointer Management
- Vector Container
- Object Interaction

---

# Advantages of Aggregation

- Loose coupling between classes.
- Better flexibility.
- Independent object lifetime.
- Easy object sharing.
- Improved code reusability.
- Better modular design.

---

# Build Instructions

## Linux / macOS

```bash
g++ main.cpp Agregation.cpp -o aggregation
./aggregation
```

## Windows (MinGW)

```bash
g++ main.cpp Agregation.cpp -o aggregation.exe
aggregation.exe
```

---

---

# Difference Between Association, Aggregation, and Composition

| Feature | Association | Aggregation | Composition |
|---------|-------------|-------------|-------------|
| Relationship | Uses | Has-a | Owns |
| Ownership | No | Weak | Strong |
| Lifetime Dependency | Independent | Independent | Dependent |
| Object Storage | Usually temporary | Stores pointers/references | Stores objects directly |
| Destroy Container | No effect | No effect | Destroys contained objects |

---

# Conclusion

This project provides a clear implementation of the **Aggregation** relationship in C++.

The `Department` class aggregates multiple `Employee` objects by storing pointers to them inside a `std::vector`. Since the employees are created and destroyed independently of the department, the relationship accurately models **Aggregation**.

This project is an excellent example for beginners learning object-oriented design and understanding object relationships in C++.