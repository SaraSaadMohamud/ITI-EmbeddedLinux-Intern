/**
 * @file main.cpp
 * @brief Performs addition, subtraction, and multiplication using bitwise operations.
 *
 * This program reads two unsigned integers from the user and performs:
 * - Addition without using the `+` operator.
 * - Subtraction without using the `-` operator.
 * - Multiplication without using the `*` operator.
 *
 * The arithmetic operations are implemented using bitwise operations
 * such as XOR (`^`), AND (`&`), NOT (`~`), left shift (`<<`),
 * and right shift (`>>`).
 *
 * @author Sara Saad
 * @date 2026-08-03
 */

#include <iostream>
#include <string>

/**
 * @brief Adds two unsigned integers using bitwise operations.
 *
 * The function performs binary addition using XOR to calculate the
 * sum without carry and AND followed by a left shift to calculate
 * the carry.
 *
 * @param num1 First unsigned integer.
 * @param num2 Second unsigned integer.
 *
 * @return The sum of @p num1 and @p num2.
 */
unsigned int adding(unsigned int num1, unsigned int num2);

/**
 * @brief Subtracts one unsigned integer from another using bitwise operations.
 *
 * The function performs binary subtraction using XOR to calculate
 * the difference and bitwise operations to calculate the borrow.
 *
 * @param num1 The minuend.
 * @param num2 The subtrahend.
 *
 * @return The difference between @p num1 and @p num2.
 */
unsigned int Subtract(unsigned int num1, unsigned int num2);

/**
 * @brief Multiplies two unsigned integers using bitwise operations.
 *
 * The function implements multiplication using the binary multiplication
 * algorithm. It uses left shifting to double the first operand and
 * right shifting to process each bit of the second operand.
 *
 * @param num1 Reference to the first unsigned integer.
 * @param num2 Reference to the second unsigned integer.
 *
 * @return The product of @p num1 and @p num2.
 */
unsigned int Multiply(unsigned int &num1, unsigned int &num2);


int main()
{
    unsigned int number1, number2;

    std::cout << "Enter Number1: ";
    std::cin >> number1;

    std::cout << "Enter Number2: ";
    std::cin >> number2;

    std::cout << "Sum: " << adding(number1, number2) << std::endl;
    std::cout << "DIfference: " << Subtract(number1, number2) << std::endl;
    std::cout << "Multiplication: " << Multiply(number1, number2) << std::endl;

    return 0;
}

unsigned int adding(unsigned int num1, unsigned int num2)
{
    while (num2 != 0)
    {
        // Calculate carry bits.
        unsigned int carry = num1 & num2;

        // Calculate sum without carry.
        num1 = num1 ^ num2;

        // Shift carry to the next bit position.
        num2 = carry << 1;
    }

    return num1;
}

unsigned int Subtract(unsigned int num1, unsigned int num2)
{
    while (num2 != 0)
    {
        // Calculate borrow bits.
        unsigned int borrow = (~num1) & num2;

        // Calculate difference without borrow.
        num1 = num1 ^ num2;

        // Shift borrow to the next bit position.
        num2 = borrow << 1;
    }

    return num1;
}

unsigned int Multiply(unsigned int &num1, unsigned int &num2)
{
    unsigned int result = 0;

    while (num2 != 0)
    {
        // Add num1 to result if the current bit of num2 is 1.
        if (num2 & 1)
        {
            result = adding(result, num1);
        }

        // Shift num1 left to multiply by 2.
        num1 <<= 1;

        // Shift num2 right to process the next bit.
        num2 >>= 1;
    }

    return result;
}
