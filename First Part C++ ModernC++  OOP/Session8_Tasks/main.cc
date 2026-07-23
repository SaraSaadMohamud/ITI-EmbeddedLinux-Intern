/**
 * @file main.cc
 * @brief Demonstrates the functionality of the Complex class.
 *
 * This program demonstrates the use of the Complex class by:
 * - Creating objects using different constructors.
 * - Displaying complex numbers.
 * - Performing arithmetic operations.
 * - Performing compound assignment operations.
 * - Demonstrating prefix increment and decrement operators.
 * - Reading complex numbers from the user using the extraction operator.
 * - Printing complex numbers using the insertion operator.
 */

#include "complex.hh"
#include <iostream>

int main()
{
    Complex number1;
    double x = 10, y = 20;
    Complex number2(x);
    Complex number3(x, y);
    Complex number4(number2);

    number1.printComplex();
    number2.printComplex();
    number3.printComplex();
    number4.printComplex();

    
    std::cout<<"\n============================ Arthimetic Operator ============================\n\n";
    Complex obj1 = number1.operator+(number2);
    obj1.printComplex();

    Complex obj2 = number1.operator-(number2);
    obj1.printComplex();

    Complex obj3 = number1.operator*(number2);
    obj3.printComplex();

    Complex obj4 = number1.operator/(number2);
    obj4.printComplex();

    number1.operator++();
    number1.printComplex();

    number2.operator--();
    number2.printComplex();

    std::cout<<"\n=========================== Assignment Operator =============================\n\n";
    number1.operator+=(number3);
    number1.printComplex();

    number1.operator-=(number2);
    number1.printComplex();

    std::cout<<"\n==============================================================================\n\n";

    Complex c1, c2;

    std::cout << "Enter first complex number (real imag): ";
    std::cin >> c1;

    std::cout << "Enter second complex number (real imag): ";
    std::cin >> c2;

    std::cout << "\nFirst Complex Number: " << c1 << std::endl;
    std::cout << "Second Complex Number: " << c2 << std::endl;


    return(0);
}