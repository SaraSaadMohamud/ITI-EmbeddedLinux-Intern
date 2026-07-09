/**
 * @file SimpleCalculator.cc
 * @brief A simple command-line calculator using C++ fundamentals
 * 
 * This program demonstrates:
 * - Namespace usage to avoid name collisions
 * - Switch statement for operator handling (efficient)
 * - Basic input/output operations
 * 
 * @author Sara Saad
 * @date 9th of July 2026
 * @version 1.0
 */

#include <iostream>

/**
 * @namespace Private
 * @brief Namespace to encapsulate calculator functionality and avoid potential name conflicts
 */

namespace Private
{
    /**
     * @brief Performs arithmetic operation based on the given operator
     * 
     * @param num1 First operand
     * @param num2 Second operand
     * @param operator_ The arithmetic operator (+, -, *, /, %)
     */
    void impleCalculator(int num1, int num2, char operator_)
    {
        switch(operator_)
        {
            case '+':
            std::cout<<num1 <<" + "<<num2<<" = "<<num1 + num2 <<std::endl;
            break;
            case '-':
            std::cout<<num1 <<" - "<<num2<<" = "<<num1 - num2 <<std::endl;
            break;
            case '*':
            std::cout<<num1 <<" * "<<num2<<" = "<<num1 * num2 <<std::endl;
            break;
            case '/':
            std::cout<<num1 <<" / "<<num2<<" = "<<num1 / num2 <<std::endl;
            break;
            case '%':
            std::cout<<num1 <<" % "<<num2<<" = "<<num1 % num2 <<std::endl;
            break;
            default:
            std::cout<<"Invalide Operator!!\n";
            break;
        }
    }

}

int main()
{
    int Number1;
    int Number2;
    char Operator_;

    std::cout<<"Enter the First Number: ";
    std::cin>>Number1;
    std::cout<<"Enter the Second Number: ";
    std::cin>>Number2;
    std::cout<<"Enter the Operator: ";
    std::cin>>Operator_;

    Private::impleCalculator(Number1,Number2,Operator_);

    return(0);
}

