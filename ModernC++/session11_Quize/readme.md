#  C++ Problem Solving Quiz #4

<p align="center">

<img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">
<img src="https://img.shields.io/badge/Level-Beginner-blue?style=for-the-badge">
<img src="https://img.shields.io/badge/Problems-4-success?style=for-the-badge">
<img src="https://img.shields.io/badge/OOP-STL-orange?style=for-the-badge">

</p>

---

#  Overview

This repository contains **four beginner-friendly C++ programming problems** that focus on developing problem-solving skills while practicing the Standard Template Library (STL), strings, vectors, loops, searching, sorting, and basic algorithm design.

Each problem is implemented as an independent C++ program with clear logic and documented using **Doxygen** comments.

---

#  Learning Objectives

By completing these problems, you will practice:

- Working with `std::vector`
- Working with `std::string`
- Searching algorithms
- Sorting using `std::sort()`
- Frequency counting
- Nested loops
- Basic algorithm analysis
- Time and Space Complexity
- Passing parameters by reference
- Pointer parameters
- Writing clean and documented C++ code

---

# Repository Structure

```text
Problem-Solving-Quiz-01
│
├── Problem1_TwoSum
│   └── main.cpp
│
├── Problem2_CharacterFrequency
│   └── main.cpp
│
├── Problem3_MoveZeros
│   └── main.cpp
│
├── Problem4_Palindrome
│   └── main.cpp
│
└── README.md
```

---

# Problem 1 — Two Sum

## Description

Given a vector of integers and a target value **K**, find two numbers whose sum equals the target.

The program:

- Sorts the vector.
- Searches for two numbers.
- Prints the matching pair if found.

---

### Example

Input

```text
Vector:
1 3 14 4 9 2 20

K = 11
```

Output

```text
Number1 = 2
Number2 = 9
```

---

### Concepts Used

- std::vector
- std::sort()
- Nested loops
- Searching
- Pointer parameters

---

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(n²) |
| Space | O(1) |

---

# Problem 2 — Character Frequency

## Description

Count the occurrence of every lowercase English character inside a string.

The program creates a frequency table of size **26**, where each index represents one alphabet letter.

---

### Example

Input

```text
banana
```

Output

```text
a : 3
b : 1
n : 2
```

---

### Concepts Used

- std::string
- std::vector
- Frequency Array
- Character Arithmetic

---

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(26) ≈ O(1) |

---

#  Problem 3 — Move All Zeros to the End

## Description

Move every zero element in a vector to the end while preserving the relative order of the remaining elements.

---

### Example

Input

```text
1 0 3 0 5 6
```

Output

```text
1 3 5 6 0 0
```

---

### Concepts Used

- std::vector
- Nested loops
- In-place array manipulation
- Element shifting

---

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(n²) |
| Space | O(1) |

---

#  Problem 4 — Palindrome String

## Description

Determine whether a string is a palindrome.

A palindrome reads the same forward and backward.

---

### Example

Input

```text
madam
```

Output

```text
Palindrome
```

---

Input

```text
sara
```

Output

```text
Not Palindrome
```

---

### Concepts Used

- std::string
- Two-pointer technique
- String traversal

---

### Complexity

| Complexity | Value |
|------------|-------|
| Time | O(n) |
| Space | O(1) |

---

# 🛠 Technologies Used

- C++17
- GNU G++
- STL
- std::vector
- std::string
- std::sort()

---

# ▶ Build Instructions

Compile any problem individually.

Example:

```bash
g++ main.cpp -o app
```

Run:

Linux/macOS

```bash
./app
```

Windows (MinGW)

```bash
app.exe
```

---

# Skills Practiced

- Problem Solving
- Algorithm Design
- STL
- Searching
- Sorting
- String Manipulation
- Arrays & Vectors
- Clean Code
- Doxygen Documentation

---

# Possible Improvements

Some programs can be further optimized.

### Two Sum

Current complexity:

```text
O(n²)
```

Better solution:

- Hash Map
- O(n)

---

### Move Zeros

Current complexity:

```text
O(n²)
```

Better solution:

- Two Pointers
- O(n)

---

### Character Frequency

Can be extended to:

- Uppercase letters
- Digits
- Special characters
- Unicode strings

---

### Palindrome

Can be improved to:

- Ignore spaces
- Ignore punctuation
- Case-insensitive comparison

Example:

```text
A man a plan a canal Panama
```

---

#  Author

**Sara Saad Mahmoud**

Embedded Systems & Robotics Engineer

- C++
- Embedded Systems
- Problem Solving
- STM32
- ROS2
---