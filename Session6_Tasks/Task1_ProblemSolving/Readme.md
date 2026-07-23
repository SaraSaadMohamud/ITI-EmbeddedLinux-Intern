#  C++ Programming Quiz #1

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus">
  <img src="https://img.shields.io/badge/Level-Beginner-green?style=for-the-badge">
  <img src="https://img.shields.io/badge/Problems-4-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge">
</p>

---

#  Overview

This repository contains solutions for **C++ Programming Quiz #2**, which consists of **four vector manipulation and algorithmic programming problems**.

The exercises focus on developing problem-solving skills using the C++ Standard Template Library (STL) and common algorithmic techniques.

The implemented problems cover:

- Vector manipulation
- Searching algorithms
- Sorting
- Frequency counting
- Duplicate removal
- In-place algorithms
- Pointer usage
- Time complexity analysis

---

#  Learning Objectives

After completing this quiz, you will understand:

- Working with `std::vector`
- Passing vectors by reference
- In-place algorithms
- Two-pointer techniques
- Frequency counting
- Sorting using STL
- Pointer parameters
- Removing duplicate values
- Algorithm complexity analysis

---

# 📂 Project Structure

```text
Quiz2/
│
├── Problem1_ReverseVector.cpp
├── Problem2_CountNumberOccurrences.cpp
├── Problem3_SecondLargestElement.cpp
├── Problem4_RemoveDuplicateElements.cpp
│
└── README.md
```

---

# Problems

---

# Problem 1 — Reverse a Vector

## Description

Reverse all elements of a vector **in-place** without creating another vector.

The algorithm uses the **two-pointer technique** by swapping the first and last elements until reaching the center of the vector.

---

### Example

Input

```text
10 20 30 40 50
```

Output

```text
50 40 30 20 10
```

---

### Concepts Used

- std::vector
- Two-pointer technique
- Swapping values
- In-place algorithms

---

### Time Complexity

```
O(n)
```

---

# Problem 2 — Count Number Occurrences

## Description

Determine how many times every number appears inside a vector.

The program:

1. Finds the maximum element.
2. Creates a frequency vector.
3. Counts the occurrences of each value.
4. Prints only the numbers that appear at least once.

---

### Example

Input

```text
1 2 3 1 2 2 4
```

Output

```text
1 : 2
2 : 3
3 : 1
4 : 1
```

---

### Concepts Used

- std::vector
- Frequency arrays
- std::max_element()
- Counting algorithms

---

### Time Complexity

```
O(n)
```

---

# Problem 3 — Second Largest Element

## Description

Find the **second largest element** in a vector.

The algorithm:

1. Sorts the vector.
2. Retrieves the second last element.
3. Stores the result using a pointer.

---

### Example

Input

```text
10 20 100 1 6 9 500 -5
```

Output

```text
Second Largest Element: 100
```

---

### Concepts Used

- std::sort()
- Pointer parameters
- Vector traversal

---

### Time Complexity

Sorting

```
O(n log n)
```

Finding answer

```
O(1)
```

Overall

```
O(n log n)
```

---

# Problem 4 — Remove Duplicate Elements

## Description

Remove duplicate values from a vector **without using** the STL `std::unique()` algorithm.

The algorithm:

1. Sorts the vector.
2. Compares adjacent elements.
3. Shifts remaining elements to the left whenever a duplicate is found.
4. Removes the last duplicated element using `pop_back()`.

---

### Example

Input

```text
10 20 50 10 10 30 20
```

Output

```text
10 20 30 50
```

---

### Concepts Used

- std::sort()
- Manual duplicate removal
- Vector shifting
- pop_back()

---

### Time Complexity

Sorting

```
O(n log n)
```

Duplicate removal

```
O(n²)
```

Overall

```
O(n²)
```

---

# 🛠 Technologies Used

- C++17
- GNU g++
- Standard Template Library (STL)

Libraries used:

```cpp
<iostream>
<vector>
<algorithm>
```

---

# Build Instructions

Compile each problem separately.

### Problem 1

```bash
g++ Problem1_ReverseVector.cpp -o problem1
```

Run

```bash
./problem1
```

---

### Problem 2

```bash
g++ Problem2_CountNumberOccurrences.cpp -o problem2
```

Run

```bash
./problem2
```

---

### Problem 3

```bash
g++ Problem3_SecondLargestElement.cpp -o problem3
```

Run

```bash
./problem3
```

---

### Problem 4

```bash
g++ Problem4_RemoveDuplicateElements.cpp -o problem4
```

Run

```bash
./problem4
```

---

# 💡 Concepts Practiced

- std::vector
- STL Algorithms
- std::sort()
- std::max_element()
- Frequency Counting
- In-place Algorithms
- Swapping
- Pointer Parameters
- Duplicate Removal
- Searching
- Algorithm Design

---

# Possible Improvements

### Problem 1

- Use `std::reverse()` from the STL.
- Accept user input instead of predefined vectors.

---

### Problem 2

- Support negative numbers using `std::unordered_map`.
- Sort the output by frequency.
- Display the most frequent element.

---

### Problem 3

- Find the second largest element without sorting in **O(n)** time.
- Handle duplicate maximum values correctly.
- Validate vectors with fewer than two elements.

---

### Problem 4

- Replace the manual implementation with `std::unique()`.
- Implement an **O(n)** solution using `std::unordered_set`.
- Preserve the original order while removing duplicates.

---

# Sample Topics Covered

- Vector Manipulation
- STL Algorithms
- Sorting
- Searching
- Frequency Counting
- Duplicate Removal
- Swapping Algorithms
- Pointer Usage
- Time Complexity
- Algorithm Optimization

---

# Author

**Sara Saad Mahmoud**

- Electronics and Communication Engineering Student
- Embedded Systems & Robotics Engineer
- C / C++ Developer

---

# Conclusion

This quiz provides practical experience with common vector-based algorithms in C++. Through four independent problems, it reinforces fundamental programming concepts such as in-place manipulation, frequency counting, sorting, searching, and duplicate removal. These exercises serve as an excellent foundation for developing efficient algorithmic thinking and mastering the use of the C++ Standard Template Library (STL).