#  Simple ATM Banking System

A simple console-based ATM Banking System developed in **C++** as part of learning C++ Fundamentals.

The project demonstrates the use of:
- Functions
- Header files
- Source file separation
- References
- Constant expressions (`constexpr`)
- Input validation
- Basic documentation using Doxygen

---

##  Features

-  Secure login with a 4-digit password
-  Maximum 3 login attempts
-  Deposit money
-  Withdraw money
-  Check current balance
-  Transaction limits
-  Input validation for invalid user input
-  Modular project structure

---

##  Project Structure

```
ATM/
│
├── main.cpp        # Program entry point
├── Atm.cpp         # Function implementations
├── Atm.hpp         # Function declarations & constants
└── README.md
```

---

##  Transaction Rules

| Rule | Value |
|------|------:|
| Maximum Deposit | 10000 EGP |
| Maximum Withdrawal | 10000 EGP |
| Minimum Transaction | 5 EGP |
| Password Attempts | 3 |

---

##  Login

The demo uses a predefined password:

```text
1234
```

If the user enters an incorrect password three times, the application terminates.

---

##  Main Menu

```text
1. Withdraw
2. Deposit
3. Check Balance
4. Exit
```

---

##  Technologies Used

- C++17
- Standard Library
- Console Application
- Doxygen Documentation

---

## ▶ Build & Run

Using g++:

```bash
g++ main.cpp Atm.cpp -o res.exe
./res.exe
```

---

##  Example

```text
Enter the 4-digit password: 1234

Welcome Again!!, Select a service:

1. Withdraw
2. Deposit
3. Check Balance
4. Exit

Enter Number of Service: 2

Enter the deposit amount: 500

The Deposit was successful!

--------------------------------------------------

Available balance: [ 500 EGP ]
```

---

##  Concepts Practiced

- Functions
- References
- Header Files
- Modular Programming
- Constants (`constexpr`)
- Input Validation
- Switch Statements
- Loops
- Basic Error Handling

---

##  Future Improvements

- Multiple user accounts
- PIN encryption
- File-based account storage
- Transaction history
- Account creation
- Change password feature
- Object-Oriented Programming (OOP) version

---

##  Author

**Sara Saad**

Electronics and Communication Engineering

GitHub: https://github.com/SaraSaadMohamud