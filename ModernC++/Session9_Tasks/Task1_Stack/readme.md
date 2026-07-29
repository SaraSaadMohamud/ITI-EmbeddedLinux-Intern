# Dynamic Stack Implementation in C++

A complete implementation of the **Stack** data structure using **C++** and **dynamic memory allocation**. The project follows the **Last-In, First-Out (LIFO)** principle and demonstrates proper resource management through the **Rule of Three**.

---

## Overview

This project was developed as an educational exercise to practice fundamental and intermediate Object-Oriented Programming (OOP) concepts in C++.

The implementation demonstrates:

- Dynamic memory allocation using `new[]` and `delete[]`
- Deep copy implementation
- Copy constructor
- Copy assignment operator
- Destructor
- Static data members
- Encapsulation
- Const member functions
- Operator overloading
- Rule of Three

---

##  Features

- Dynamic stack allocation
- Default constructor
- Parameterized constructor
- Copy constructor
- Destructor
- Copy assignment operator (`operator=`)
- Push operation
- Pop operation
- Stack printing
- Runtime stack resizing
- Static object counter
- Overflow detection
- Underflow detection

---

##  Project Structure

```text
.
├── stack.hh      # Stack class declaration
├── stack.cpp     # Stack class implementation
├── main.cpp      # Demonstration program
└── README.md
```

---

## Class Design

### Private Data Members

| Member | Description |
|---------|-------------|
| `stack_size_` | Maximum number of elements the stack can store. |
| `stk_` | Pointer to the dynamically allocated integer array. |
| `Tos_` | Top Of Stack index (`-1` indicates an empty stack). |
| `stack_cout` | Static member used to count existing `Stack` objects. |

---

##  Public Member Functions

### Constructors

| Function | Description |
|----------|-------------|
| `Stack()` | Creates a stack with the default size (10 elements). |
| `Stack(size)` | Creates a stack with a user-defined capacity. |
| `Stack(const Stack&)` | Creates a deep copy of another stack object. |

### Destructor

| Function | Description |
|----------|-------------|
| `~Stack()` | Releases the dynamically allocated memory. |

### Stack Operations

| Function | Description |
|----------|-------------|
| `pushToStack(int)` | Inserts a new element onto the stack. |
| `popFromStack()` | Removes and returns the top element. |
| `printStack()` | Prints all stack elements. |

### Getters

| Function | Description |
|----------|-------------|
| `getStackSize()` | Returns the stack capacity. |
| `getStackAddress()` | Returns the address of the internal array. |
| `getStackTos()` | Returns the current top index. |
| `getStackCount()` | Returns the number of existing `Stack` objects. |

### Setters

| Function | Description |
|----------|-------------|
| `setStackSize()` | Allocates a new stack with a different capacity. |

### Operator Overloading

| Operator | Description |
|----------|-------------|
| `operator=` | Performs deep copy assignment between two Stack objects. |

---

##  Object Lifetime

The project keeps track of the number of active `Stack` objects.

- Every constructor increments the object counter.
- The destructor decrements the object counter.
- `getStackCount()` returns the current number of active objects.

---

##  Concepts Demonstrated

- Object-Oriented Programming (OOP)
- Classes and Objects
- Constructors
- Destructor
- Dynamic Memory Allocation
- Rule of Three
- Deep Copy
- Shallow Copy Prevention
- Operator Overloading
- Static Data Members
- Const Member Functions
- Encapsulation
- Pointer Management
- LIFO Data Structure

---

##  Time Complexity

| Operation | Complexity |
|-----------|------------|
| Push | **O(1)** |
| Pop | **O(1)** |
| Top Access | **O(1)** |
| Print | **O(n)** |
| Copy Constructor | **O(n)** |
| Assignment Operator | **O(n)** |

---

##  Space Complexity

| Resource | Complexity |
|----------|------------|
| Stack Storage | **O(n)** |

where **n** is the stack capacity.

---

##  Building the Project

### Compile

```bash
g++ main.cpp stack.cpp -o stack
```

### Run

```bash
./stack
```

---

##  Demonstration

The demonstration program showcases the following operations:

- Creating stack objects using different constructors
- Counting active stack objects
- Copy construction
- Copy assignment
- Push operation
- Pop operation
- Printing stack contents
- Resizing the stack
- Retrieving stack information
- Automatic memory deallocation

---

## Author

**Sara Saad Mahmoud**

Electronics and Communication Engineering Student  
Al-Azhar University

---

## Project Information

| Item | Value |
|------|-------|
| Version | **1.0** |
| Language | **C++** |
| Compiler | **g++** |
| Standard | **C++11 or later** |
| Date | **July 21, 2026** |

---