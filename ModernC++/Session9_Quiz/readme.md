#  C++ Programming Quiz #3

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus">
  <img src="https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/Problems-4-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge">
</p>

---

# Overview

This repository contains solutions for **C++ Programming Quiz #1**, which consists of **four algorithmic and string manipulation problems**.

The project is designed to strengthen fundamental C++ programming skills, including:

- String manipulation
- Character processing
- Arrays
- Sorting algorithms
- Standard Template Library (STL)
- Loops and conditional statements
- Basic algorithm design

Each problem is implemented as a separate source file and demonstrates a different programming concept.

---

# Learning Objectives

After completing these problems, you will understand:

- Working with strings in C++
- Using the STL (`std::sort`)
- Working with arrays
- Searching algorithms
- Character processing
- Looping techniques
- Algorithm implementation
- Time complexity analysis
- Writing modular functions
- Basic debugging techniques

---

# Project Structure

```text
Quiz1/
│
├── Problem1_FirstNonRepeatedCharacter.cpp
├── Problem2_ReverseWords.cpp
├── Problem3_InfiniteHelloWorld.cpp
├── Problem4_FindMissingNumber.cpp
│
└── README.md
```

---

# Problems

---

# Problem 1 — First Non-Repeated Character

## Description

Given a string, find the **first character that appears exactly once**.

The solution:

- Reads a string.
- Sorts the characters.
- Searches for the first unique character.
- Prints the result.

---

### Example

Input

```text
aabbcddee
```

Output

```text
First unrepeated character: c
```

---

### Concepts Used

- std::string
- std::sort()
- Character comparison
- Loops

---

### Time Complexity

Sorting:

```
O(n log n)
```

Searching:

```
O(n)
```

Overall:

```
O(n log n)
```

---

# Problem 2 — Reverse Two Words

## Description

Reverse the order of two words inside a string without reversing the characters.

Example

Input

```text
Hello World
```

Output

```text
World Hello
```

The program:

- Finds the space.
- Prints the second word.
- Prints the first word.

---

### Concepts Used

- String manipulation
- Character indexing
- Loops

---

### Time Complexity

```
O(n)
```

---

# Problem 3 — Infinite Hello World

## Description

Demonstrates an infinite loop by continuously printing

```text
Hello World
```

every second.

The program uses

```cpp
sleep(1);
```

from

```cpp
<unistd.h>
```

---

### Example Output

```text
Hello World
Hello World
Hello World
Hello World
...
```

---

### Concepts Used

- Infinite loops
- sleep()
- Console output

---

### Time Complexity

Runs indefinitely.

---

# Problem 4 — Find Missing Number

## Description

Reads ten integers from the user and finds the missing value in the sequence.

The algorithm:

1. Reads the numbers.
2. Sorts the array.
3. Searches for the first gap.
4. Prints the missing number.

---

### Example

Input

```text
1 2 3 4 5 7 8 9 10 11
```

Output

```text
Missing Number: 6
```

---

### Concepts Used

- std::array
- std::sort()
- Searching
- Loops

---

### Time Complexity

Sorting

```
O(n log n)
```

Searching

```
O(n)
```

Overall

```
O(n log n)
```

---

# 🛠 Technologies Used

- C++17
- GNU g++
- Standard Template Library (STL)

Libraries used:

```cpp
<iostream>
<string>
<algorithm>
<array>
<unistd.h>
```

---

# Build Instructions

Compile each problem separately.

### Problem 1

```bash
g++ Problem1_FirstNonRepeatedCharacter.cpp -o problem1
```

Run

```bash
./problem1
```

---

### Problem 2

```bash
g++ Problem2_ReverseWords.cpp -o problem2
```

Run

```bash
./problem2
```

---

### Problem 3

```bash
g++ Problem3_InfiniteHelloWorld.cpp -o problem3
```

Run

```bash
./problem3
```

Stop execution using:

```text
Ctrl + C
```

---

### Problem 4

```bash
g++ Problem4_FindMissingNumber.cpp -o problem4
```

Run

```bash
./problem4
```

---

# Concepts Practiced

- Variables
- Arrays
- Strings
- Loops
- Functions
- Sorting
- Character processing
- STL algorithms
- Searching
- Console I/O

---

# 🔍 Possible Improvements

### Problem 1

- Preserve the original order instead of sorting.
- Use `std::unordered_map` for **O(n)** complexity.

---

### Problem 2

- Support multiple words.
- Reverse words in-place.
- Ignore extra spaces.

---

### Problem 3

- Allow the user to specify the number of iterations.
- Use `std::this_thread::sleep_for()` instead of `sleep()`.

---

### Problem 4

- Use the mathematical sum formula.
- Use XOR for **O(n)** time.
- Validate user input.

---

# Sample Topics Covered

- STL Algorithms
- String Manipulation
- Arrays
- Sorting
- Searching
- Character Frequency
- Time Complexity
- Console Applications

---

# Author

**Sara Saad Mahmoud**

- Electronics and Communication Engineering Student
- Embedded Systems & Robotics Engineer
- C / C++ Developer
---

---

# ⭐ Conclusion

This quiz provides hands-on practice with fundamental C++ programming concepts through four independent problems. It covers string manipulation, sorting, searching, arrays, and control structures, making it an excellent exercise for beginners who want to strengthen their problem-solving and algorithmic thinking skills.