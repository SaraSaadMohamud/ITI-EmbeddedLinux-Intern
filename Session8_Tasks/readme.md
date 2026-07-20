# Complex Number Class in C++

## Project Overview

The **Complex Number Class** project is an object-oriented C++ application that implements the mathematical concept of **complex numbers** using classes and operator overloading. The project demonstrates fundamental Object-Oriented Programming (OOP) principles such as encapsulation, constructors, copy construction, friend functions, and operator overloading.

The `Complex` class allows users to create, manipulate, and perform arithmetic operations on complex numbers in the form:

\[
a + bi
\]

where:

- **a** represents the real part.
- **b** represents the imaginary part.

---

# Objectives

The primary objectives of this project are to:

- Practice Object-Oriented Programming (OOP).
- Implement constructors and destructors.
- Implement getter and setter functions.
- Perform arithmetic operations on complex numbers.
- Overload arithmetic operators.
- Overload stream insertion (`<<`) and extraction (`>>`) operators.
- Demonstrate prefix increment and decrement operators.
- Provide user-friendly input and output.

---

# Project Structure

```
.
├── complex.hh      # Class declaration
├── complex.cc      # Class implementation
├── main.cc         # Program demonstration
└── README.md
```

---

# Class Description

The project contains a single class named **Complex**.

## Private Data Members

| Variable | Description |
|----------|-------------|
| `real` | Stores the real part of the complex number |
| `imagin` | Stores the imaginary part |

---

# Constructors

The project implements four constructors.

## Default Constructor

Creates a complex number initialized to

```
0 + 0i
```

---

## One-Parameter Constructor

Assigns the same value to both the real and imaginary parts.

Example

```cpp
Complex c(5);
```

Result

```
5 + 5i
```

---

## Two-Parameter Constructor

Initializes the real and imaginary parts independently.

Example

```cpp
Complex c(10,20);
```

Result

```
10 + 20i
```

---

## Copy Constructor

Creates a copy of an existing object.

Example

```cpp
Complex copy(original);
```

---

# Member Functions

| Function | Description |
|----------|-------------|
| `setReal()` | Sets the real part |
| `setImagin()` | Sets the imaginary part |
| `setComplex()` | Sets both values |
| `getReal()` | Returns the real part |
| `getImagin()` | Returns the imaginary part |
| `printComplex()` | Displays the complex number |

---

# Operator Overloading

## Arithmetic Operators

### Addition

```cpp
Complex result = c1 + c2;
```

Performs

```
(a+bi) + (c+di)
```

---

### Subtraction

```cpp
Complex result = c1 - c2;
```

Performs

```
(a+bi) - (c+di)
```

---

### Multiplication

```cpp
Complex result = c1 * c2;
```

Formula

```
(a+bi)(c+di)

= (ac − bd)

+ (ad + bc)i
```

---

### Division

```cpp
Complex result = c1 / c2;
```

Formula

```
(a+bi)/(c+di)

=((ac+bd)/(c²+d²))

+((bc−ad)/(c²+d²))i
```

The implementation checks for division by zero before performing the calculation.

---

# Compound Assignment Operators

The project overloads

```cpp
+=
```

and

```cpp
-=
```

Example

```cpp
c1 += c2;

c1 -= c2;
```

---

# Prefix Operators

Supported operators

```cpp
++c1;

--c1;
```

Current behavior

- `++` increases the real part by one.
- `--` decreases the real part by one.

---

# Stream Operators

## Output Operator

The insertion operator (`<<`) allows printing objects directly.

```cpp
std::cout << complexNumber;
```

instead of

```cpp
complexNumber.printComplex();
```

---

## Input Operator

The extraction operator (`>>`) allows reading objects directly.

```cpp
std::cin >> complexNumber;
```

Expected input

```
5 7
```

which represents

```
5 + 7i
```

---

# Demonstration

The `main.cc` file demonstrates

- Object creation using all constructors
- Copy construction
- Printing complex numbers
- Arithmetic operations
- Prefix increment and decrement
- Compound assignment operators
- User input using `>>`
- User output using `<<`

---

# Example Execution

```
Default Constructor Called!
One Parameter Constructor Called!
Two Parameter Constructor Called!
Copy Constructor Called!

0
10 +10i
10 +20i
10 +10i

============================ Arithmetic Operator ============================

10 +10i
-10 -10i
0
0

=========================== Assignment Operator ============================

10 +20i
0 +10i

Enter first complex number (real imag):
3 4

Enter second complex number (real imag):
1 2

First Complex Number: 3 + 4i
Second Complex Number: 1 + 2i
```

---

# Concepts Demonstrated

This project demonstrates the following C++ concepts:

- Classes and Objects
- Constructors
- Copy Constructor
- Destructor
- Encapsulation
- Friend Functions
- Getter and Setter Functions
- Operator Overloading
- Stream Manipulation
- Object-Oriented Programming (OOP)
- Arithmetic Operations
- Prefix Operators
- Compound Assignment Operators

---

# Build Instructions

Compile the project using **g++**

```bash
g++ main.cc complex.cc -o complex
```

Run the executable

```bash
./complex
```

---

# Requirements

- C++11 or later
- GNU g++
- Linux, macOS, or Windows (MinGW/MSYS2)

---

# Author

**Sara Saad Mahmoud**

Electronics and Communication Engineering Student

Faculty of Engineering, Al-Azhar University

Embedded Systems & C++ Developer