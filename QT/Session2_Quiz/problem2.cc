/**
 * @file main.cpp
 * @brief Swaps two unsigned integers using bitwise XOR operations.
 *
 * This program reads two unsigned integers from the user, displays
 * their values before swapping, swaps their values without using a
 * temporary variable, and then displays their values after swapping.
 *
 * The swapping operation is implemented using the bitwise XOR (`^`)
 * operator.
 *
 * @author Sara Saad
 * @date 2026-08-03
 */

#include <iostream>
#include <string>

/**
 * @brief Swaps two unsigned integers using XOR operations.
 *
 * The function swaps the values of two unsigned integers without
 * using an additional temporary variable.
 *
 * The XOR swap algorithm is performed using three XOR operations:
 *
 * 1. `num1 ^= num2`
 * 2. `num2 ^= num1`
 * 3. `num1 ^= num2`
 *
 * @param num1 Reference to the first unsigned integer.
 * @param num2 Reference to the second unsigned integer.
 *
 * @note The function modifies both input variables directly because
 *       they are passed by reference.
 */
void SwapTwoNumbers(unsigned int &num1, unsigned int &num2);

int main()
{
    unsigned int number1, number2;

    std::cout << "Enter Number1: ";
    std::cin >> number1;

    std::cout << "Enter Number2: ";
    std::cin >> number2;

    std::cout << "Numbers Before Swaping" << std::endl;
    std::cout << "Number1: " << number1 << std::endl;
    std::cout << "Number2: " << number2 << std::endl;
    std::cout << std::endl;

    SwapTwoNumbers(number1, number2);

    std::cout << "Numbers After Swaping" << std::endl;
    std::cout << "Number1: " << number1 << std::endl;
    std::cout << "Number2: " << number2 << std::endl;
    std::cout << std::endl;

    return 0;
}

void SwapTwoNumbers(unsigned int &num1, unsigned int &num2)
{
    num1 ^= num2;
    num2 ^= num1;
    num1 ^= num2;
}
