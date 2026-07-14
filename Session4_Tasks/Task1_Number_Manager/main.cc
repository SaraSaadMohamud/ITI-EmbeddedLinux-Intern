/**
 * @file main.cpp
 * @brief Implementation of a simple Number Manipulation Program.
 *
 * This program allows the user to enter an integer and perform one of the
 * following operations:
 * - Increment the number
 * - Decrement the number
 * - Reset the number to zero
 * - Display the current number
 *
 * The program also validates user input and terminates after three
 * consecutive invalid attempts.
 *
 * @author Sara Saad
 * @version 1.0
 * @date 2026-07-13
 */

#include "main.hh"

int main()
{
    int number;
    int attempts=0;

    std::cout<<"Enter Number: ";
    while(!(std::cin>>number))
    {
        std::cout<<"Invalid Number!\n";
        clearError();
        attempts++;
        if(attempts == 3)
            return 0;
        std::cout<<"Enter Number: ";
    }

    int choice = 0;
    attempts = 0;
    do{

        std::cout<<"\n\n";
        std::cout<<"1. Increment\n";
        std::cout<<"2. Decrement\n";
        std::cout<<"3. Reset to 0\n";
        std::cout<<"4. Show Number\n";
        std::cout<<"5. Exit\n";
        if(!(std::cin>>choice))
        {
            std::cout<<"Invalid Choice !\n";
            clearError();
        }

        attempts++;
        if(attempts >= 3)
        {
            return(0);
        }
    
    }while((choice <= 0) || (choice > 5 ));

    switch(choice)
    {
        case 1:
            increment(&number);
            printNumber(&number);
            break;
        case 2:
            decrement(&number);
            printNumber(&number);
            break;
        case 3:
            reset(&number);
            printNumber(&number);
            break;
        case 4:
            printNumber(&number);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
    }
    
    
    return(0);
}

void increment(int *num)
{
    (*num)++;
}

void decrement(int *num)
{
    (*num)--;
}

void reset(int *num)
{
    *num = 0;
}

void printNumber(int *num)
{
    std::cout<<"Current Number = "<<*num<<std::endl;
}
void clearError()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}