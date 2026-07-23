# Number Manipulation Program

A simple C++ console application that demonstrates **pointer manipulation**, **function decomposition**, and **input validation** through a menu-driven interface.

The user enters an integer and can perform several operations on it, including incrementing, decrementing, resetting, and displaying the current value.

---

## Features

- Enter an integer from the keyboard.
- Increment the number.
- Decrement the number.
- Reset the number to zero.
- Display the current number.
- Input validation for both the entered number and menu selection.
- Automatically exits after **three consecutive invalid input attempts**.

---

## Project Structure

```
.
├── main.cpp      # Program implementation
├── main.hh       # Function declarations
├── CMakeLists.txt
└── README.md
```

---

## Functions

| Function | Description |
|----------|-------------|
| `clearError()` | Clears the input stream and removes invalid input. |
| `increment(int *num)` | Increases the number by one. |
| `decrement(int *num)` | Decreases the number by one. |
| `reset(int *num)` | Resets the number to zero. |
| `printNumber(int *num)` | Displays the current value of the number. |

---

## Program Workflow

```text
Start
   │
   ▼
Enter an Integer
   │
   ▼
Validate Input
   │
   ├── Invalid?
   │      │
   │      ▼
   │  Clear Error
   │      │
   │  Attempts < 3 ?
   │      │
   │  Yes ───────────► Ask Again
   │
   ▼
Display Menu
   │
   ▼
Select Operation
   │
   ├── 1 → Increment
   ├── 2 → Decrement
   ├── 3 → Reset
   ├── 4 → Show Number
   └── 5 → Exit
```

---

## Sample Output

```text
Enter Number: 10

1. Increment
2. Decrement
3. Reset to 0
4. Show Number
5. Exit

Choice: 1

Current Number = 11
```

---

## Concepts Demonstrated

- Functions
- Header files
- Pointer parameters
- Input validation
- `std::cin` error handling
- `std::numeric_limits`
- Switch statements
- Menu-driven console applications
- Modular programming

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
g++ main.cpp -o NumberManipulator
```

---

## Run

Linux/macOS

```bash
./NumberManipulator
```

Windows

```bash
NumberManipulator.exe
```

---

## Learning Objectives

This project is intended for beginners learning C++. It demonstrates how to:

- Organize code using header and source files.
- Pass variables by pointer.
- Validate user input.
- Separate functionality into reusable functions.
- Build simple interactive console applications.

---

## Future Improvements

- Allow multiple operations until the user chooses Exit.
- Replace pointers with C++ references.
- Add arithmetic operations (addition, subtraction, multiplication, division).
- Support floating-point numbers.
- Add unit tests.
- Improve the user interface.

---

## Author

**Sara Saad**

Electronics and Communication Engineering 

---
