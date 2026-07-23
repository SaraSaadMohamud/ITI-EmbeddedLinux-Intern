#  C++ Problem Solving Quiz #2

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus">
  <img src="https://img.shields.io/badge/Level-Beginner-success?style=for-the-badge">
  <img src="https://img.shields.io/badge/Problems-5-orange?style=for-the-badge">
</p>

##  Overview

This repository contains solutions to **5 beginner-level C++ programming problems** focused on practicing fundamental programming concepts such as:

- Vector manipulation
- String processing
- Looping techniques
- Function design
- Basic algorithms
- In-place data modification

Each problem is implemented in a separate source file with complete **Doxygen documentation** for easier understanding and maintenance.

---

# 📂 Problems

## 1️⃣ Merge Two Vectors

###  Objective
Merge two integer vectors into a third vector.

### 💡 Concepts Used
- `std::vector`
- Dynamic resizing
- Copying vector elements
- Loops

### Example

Input

```text
Vector1: 1 2 3 4 5
Vector2: 6 7 8 9 10
```

Output

```text
Vector3:
1 2 3 4 5 6 7 8 9 10
```

---

## 2️⃣ Compare Vector Sums

###  Objective

Calculate the sum of elements in multiple vectors and compare their totals.

### 💡 Concepts Used

- Iterating over vectors
- Passing pointers to functions
- Arithmetic operations
- Conditional statements

### Example

```text
Vector1 Sum = 330
Vector2 Sum = 330
Vector3 Sum = 15
```

Output

```text
Vector1 & Vector2 have the Same Sum Element!
Vector1 & Vector3 Don't have the Same Sum Element!
Vector2 & Vector3 Don't have the Same Sum Element!
```

---

## 3️⃣ Count Vowels in a String

###  Objective

Count the total number of English vowels in a string.

### 💡 Concepts Used

- String traversal
- Character comparison
- Uppercase and lowercase handling
- Functions

### Supported Vowels

```text
A E I O U
a e i o u
```

### Example

Input

```text
AWoeiaaauuQlmn
```

Output

```text
Number of Vowels = 10
```

---

## 4️⃣ Reverse a String

###  Objective

Reverse all characters of a string in place.

### 💡 Concepts Used

- Two-pointer technique
- Character swapping
- String manipulation

### Example

Input

```text
sara saad
```

Output

```text
daas aras
```

---

## 5️⃣ Remove Negative Numbers from a Vector

###  Objective

Remove all negative values from a vector.

### 💡 Concepts Used

- Vector traversal
- Element removal
- `pop_back()`
- In-place modification

### Example

Before

```text
1 2 -5 10 20 -30 40
```

After

```text
1 2 40 10 20
```

---

# 🛠 Skills Practiced

- Functions
- Passing by Reference
- Passing by Pointer
- Strings
- Vectors
- Loops
- Conditional Statements
- In-place Algorithms
- Dynamic Containers
- Basic Problem Solving
- Doxygen Documentation

---

# Technologies

- C++
- STL
  - `std::vector`
  - `std::string`

---

# ▶️ Build

Compile using **g++**

```bash
g++ main.cpp -o app
```

Run

```bash
./app
```

---

# Learning Outcomes

After completing this quiz, you will understand how to:

- Merge vectors manually
- Compare sums of containers
- Count vowels in strings
- Reverse strings efficiently
- Remove elements from vectors
- Work with pointers and references
- Design reusable functions
- Document C++ code using Doxygen

---

# Author

**Sara Saad Mahmoud**

- Embedded Systems Engineer
- Electronics & Communication Engineering Student
- C / C++ Developer

---

# ⭐ Repository Purpose

This repository is part of my C++ practice series, where I solve programming exercises while applying clean coding practices and professional documentation using **Doxygen**.