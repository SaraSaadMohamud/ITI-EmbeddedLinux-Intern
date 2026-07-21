/**
 * @file main.cpp
 * @brief Demonstrates the functionality of the Stack class.
 *
 * This program demonstrates the usage of the Stack class by creating
 * multiple stack objects and performing various operations such as:
 * - Object construction using different constructors.
 * - Object counting using a static member.
 * - Copy construction.
 * - Copy assignment.
 * - Push and pop operations.
 * - Printing stack contents.
 * - Changing the stack size.
 * - Retrieving stack information.
 *
 * @author Sara Saad Mahmoud
 * @date July 21, 2026
 * @version 1.0
 */

#include <iostream>
#include "stack.hh"

int main()
{
    Stack s1;
    std::cout<<"Number of Stack: "<<Stack::getStackCount()<<std::endl;
    Stack s2(5);
    std::cout<<"Number of Stack: "<<Stack::getStackCount()<<std::endl;
    Stack s3 = s2;
    std::cout<<"Number of Stack: "<<Stack::getStackCount()<<std::endl;
    Stack s4(s2);
    std::cout<<"Number of Stack: "<<Stack::getStackCount()<<std::endl;
    Stack s5;
    std::cout<<"Number of Stack: "<<Stack::getStackCount()<<std::endl;

    s1.printStack();
    std::cout<<"\n=============================================================\n\n";
    s2.printStack();
    std::cout<<"\n=============================================================\n\n";
    s3.printStack();
    std::cout<<"\n=============================================================\n";
    s4.printStack();
    std::cout<<"\n=============================================================\n\n";

    s5 = s4;
    s5.printStack();
    std::cout<<"\n=============================================================\n\n";

    for(int i=0 ; i < s1.getStackSize() ; i++)
    {
        s1.pushToStack(i);
    }
    
    s1.printStack();
    std::cout<<"\n=============================================================\n\n";
    s2.operator=(s1);
    s2.printStack();
    std::cout<<"\n=============================================================\n\n";

    int value = s1.popFromStack();
    s1.printStack();
    std::cout<<"\n=============================================================\n\n";

    s1.pushToStack(500);
    s1.printStack();
    std::cout<<"\n=============================================================\n\n";

    s1.pushToStack(500);
    s1.printStack();
    std::cout<<"\n=============================================================\n\n";

    std::cout<<"Stack Tos: "<<s1.getStackTos()<<std::endl;
    std::cout<<"Stack Size: "<<s1.getStackSize()<<std::endl;
    std::cout<<"Stack Start Adresses: "<<s1.getStackAddress()<<std::endl;
    std::cout<<"\n=============================================================\n\n";

    s1.setStackSize(15);
    for(int i=0 ; i < s1.getStackSize() ; i++)
    {
        s1.pushToStack(i);
    }
    s1.printStack();
    std::cout<<"\n=============================================================\n\n";
    std::cout<<"Stack Tos: "<<s1.getStackTos()<<std::endl;
    std::cout<<"Stack Size: "<<s1.getStackSize()<<std::endl;
    std::cout<<"Stack Start Adresses: "<<s1.getStackAddress()<<std::endl;
    std::cout<<"\n=============================================================\n\n";

    return(0);
}