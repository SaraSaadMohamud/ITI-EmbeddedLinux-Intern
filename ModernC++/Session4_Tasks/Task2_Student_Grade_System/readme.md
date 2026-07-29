# Student Grade Calculator

A simple C++ console application that demonstrates **functions**, **pointer parameters**, **input validation**, and **modular programming** by calculating a student's average score and corresponding letter grade.

The program allows users to enter a student's information, generate a report, and perform additional operations such as updating marks or recalculating the average.

---

## Features

- Enter a student's name.
- Input marks for:
  - Mathematics
  - Physics
  - English
- Calculate the average score.
- Determine the student's letter grade.
- Display a formatted student report.
- Update marks using a bonus menu.
- Recalculate the average.
- Input validation with automatic termination after **three invalid attempts**.

---

## Project Structure

```text
.
├── main.cpp          # Program implementation
├── main.hh           # Function declarations
├── CMakeLists.txt
└── README.md
```

---

## Functions

| Function | Description |
|----------|-------------|
| `inputMarks()` | Reads marks for Mathematics, Physics, and English. |
| `calculateAverage()` | Computes the average score of the three subjects. |
| `calculateGrade()` | Determines the letter grade based on the average score. |
| `printReport()` | Displays the student's report. |
| `clearError()` | Clears invalid input from the input stream. |

---

## Grade Scale

| Average | Grade |
|---------:|:-----:|
| 90 – 100 | A |
| 80 – 89 | B |
| 70 – 79 | C |
| 60 – 69 | D |
| Below 60 | F |

---

## Program Workflow

```text
Start
   │
   ▼
Enter Student Name
   │
   ▼
Enter Subject Marks
   │
   ▼
Validate Input
   │
   ├── Invalid?
   │      │
   │      ▼
   │ Clear Input Buffer
   │      │
   │ Attempts < 3 ?
   │      │
   │ Yes ─────────► Enter Again
   │
   ▼
Calculate Average
   │
   ▼
Determine Grade
   │
   ▼
Display Student Report
   │
   ▼
Bonus Menu
   │
   ├── Update Marks
   ├── Recalculate Average
   └── Print Report Again
   │
   ▼
Exit
```

---

## Sample Output

```text
Student Name: Sara

Math: 95
Physics: 88
English: 91

=============================================================

Student Name: Sara
Average: 91.33
Grade: A

================== Bonus Menu ====================
1. Update a Mark
2. Recalculate the Average
3. Print the Report Again
```

---

## Concepts Demonstrated

- Functions
- Modular Programming
- Header Files
- Pointer Parameters
- Input Validation
- User-defined Functions
- Conditional Statements
- Switch Statements
- `std::string`
- `std::getline()`
- Error Handling with `std::cin`
- `std::numeric_limits`

---

## Requirements

- C++17 or later
- CMake 3.20+ (optional)
- Any modern C++ compiler
  - GCC
  - Clang
  - MSVC

---

## Build

### Using CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Using g++

```bash
g++ main.cpp -o StudentGradeCalculator
```

---

## Run

### Linux / macOS

```bash
./StudentGradeCalculator
```

### Windows

```bash
StudentGradeCalculator.exe
```

---

## Learning Objectives

This project is designed for beginners learning C++. It demonstrates how to:

- Organize a project using header and source files.
- Pass variables by pointer.
- Validate numeric user input.
- Calculate averages using functions.
- Determine grades using conditional statements.
- Build a menu-driven console application.
- Produce formatted program output.

---

## Possible Future Improvements

- Display individual subject marks in the report.
- Allow updating a single subject instead of all marks.
- Support any number of subjects using arrays or vectors.
- Store multiple student records.
- Save reports to a text file.
- Replace pointer parameters with C++ references.
- Keep the menu running until the user selects **Exit**.
- Add GPA calculation.

---

## Author

**Sara Saad**

Electronics and Communication Engineering 

---
