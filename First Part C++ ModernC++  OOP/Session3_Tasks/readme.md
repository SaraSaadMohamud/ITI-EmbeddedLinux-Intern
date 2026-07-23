# Payroll Management System

A simple **C++ console-based Payroll Management System** that calculates employee salaries based on working hours, overtime, bonuses, and tax deductions. The project demonstrates modular programming, input validation, and clean code organization using multiple source and header files.

---

##  Features

- Employee information management
- Gross salary calculation
- Overtime payment calculation (1.5× hourly rate)
- Position-based bonus system
  - **Manager:** 10% bonus
  - **Employee:** 5% bonus
- 10% tax deduction
- Payroll report generation
- Robust input validation
- Modular project structure

---

##  Project Structure

```
Payroll_System/
│
├── main.cpp                # Program entry point
├── payroll_system.cpp      # Function implementations
├── payroll_system.hpp      # Function declarations
└── README.md
```

---

##  How It Works

The program follows the workflow below:

```
Start
   │
   ▼
Read Employee Information
   │
   ▼
Calculate Gross Salary
   │
   ▼
Apply Optional Bonus
   │
   ▼
Calculate Tax
   │
   ▼
Calculate Net Salary
   │
   ▼
Display Payroll Report
   │
   ▼
End
```

---

##  Salary Calculation

### 1. Gross Salary

```
Gross Salary =
(Working Hours × Hourly Rate)
+
(Overtime Hours × Hourly Rate × 1.5)
```

---

### 2. Bonus

Managers receive:

```
10% of Gross Salary
```

Employees receive:

```
5% of Gross Salary
```

The user can choose whether to apply the bonus.

---

### 3. Tax

```
Tax = Salary × 10%
```

---

### 4. Net Salary

```
Net Salary = Salary − Tax
```

---

##  User Input

The program requests the following information:

- Employee Name
- Employee ID
- Working Hours
- Hourly Rate
- Position
  - Manager (`m`)
  - Employee (`e`)
- Overtime Hours
- Apply Bonus? (`y / n`)

---

##  Sample Output

```text
Employee Name: Sara Saad
Employee ID: 1001
Working Hours: 250
Hourly Rate: 5
Position [m = manager , e = employee]: m
OverTime Hours: 30

Salary before TAX: 1475.00 $

Adding [10%] Bonus ? (y / n): y

Bonus added.
Current Salary before TAX: 1622.50 $

========================= Payroll =========================

Employee : Sara Saad
ID: 1001
Salary: 1622.50 $
TAX[10%]: 162.25 $
Net Salary: 1460.25 $
```

---

##  Input Validation

The program validates all numeric inputs.

If invalid input is entered:

- The input stream is cleared.
- The user is prompted again.
- After **three consecutive invalid attempts**, the program terminates safely.

---

##  Functions Overview

| Function | Description |
|----------|-------------|
| `calculateSalaryBeforeTax()` | Reads employee data and calculates gross salary |
| `addBonus()` | Applies the appropriate bonus based on employee position |
| `calculateSalaryAfterTax()` | Calculates tax and net salary |
| `payRoll()` | Displays the payroll report |
| `clearError()` | Clears invalid input from the input stream |

---

##  Technologies Used

- C++17
- Standard Template Library (STL)
- Modular Programming
- Doxygen Documentation

---

##  Build

Compile using **g++**

```bash
g++ main.cpp payroll_system.cpp -o payroll
```

Run

```bash
./payroll
```

---

##  Concepts Demonstrated

- Functions
- Header Files
- Separate Compilation
- Global Variables
- Constants (`constexpr`)
- Input Validation
- Conditional Statements
- Loops
- Console I/O
- Modular Design

---

##  Future Improvements

Possible enhancements include:

- Convert the project to an Object-Oriented Design (OOP)
- Replace global variables with classes
- Store employee records in files
- Add monthly and yearly payroll reports
- Support multiple employees
- Calculate additional deductions (insurance, retirement, etc.)
- Generate payroll reports as PDF or CSV

---

##  Author

**Sara Saad**

Electronics and Communication Engineering 
Al-Azhar University

---
