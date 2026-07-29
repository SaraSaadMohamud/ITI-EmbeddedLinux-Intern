/**
 * @file stack.cpp
 * @brief Implementation of the Stack class.
 *
 * This file implements the Stack class member functions, including
 * constructors, destructor, stack operations, memory management,
 * deep copy functionality, and object counting.
 * @author Sara Saad Mahmoud
 * @date July 21, 2026
 * @version 1.0
 */

#include <iostream>
#include "stack.hh"

int Stack::stack_cout = 0;

Stack::Stack()
{
    this->stack_size_ = 10;
    this->stk_ = new int[this->stack_size_];
    this->Tos_ = -1;
    std::cout<<"Default Constructor Called!\n";
    stack_cout++;
}

Stack::Stack(const unsigned int &size)
{
    this->stack_size_ = size;
    this->stk_ = new int[this->stack_size_];
    this->Tos_ = -1;
    std::cout<<"Parametrize Constructor Called!\n";
    stack_cout++;
}

Stack::Stack(const Stack &obj)
{
    this->stack_size_ = obj.stack_size_;
    this->Tos_ = obj.Tos_;
    this->stk_ = new int[obj.stack_size_];
    this->Tos_ = obj.Tos_;

    for(auto i=0 ; i<= obj.Tos_ ; i++)
    {
        this->stk_[i] = obj.stk_[i];
    } 

    std::cout<<"Copy Constructor Called!\n";
    stack_cout++;
}

Stack::~Stack()
{
    delete[] this->stk_;
    std::cout<<"Default Destructor Called!\n";
    stack_cout--;
    std::cout<<"Number of Stack: "<<Stack::getStackCount()<<std::endl;
}

int Stack::popFromStack()
{
    if((this->Tos_ ) == -1)
    {
        std::cout<<"Stack is Empty!!\n";
        return -1;
    }
    return(this->stk_[Tos_--]);
}

void Stack::pushToStack(int value)
{
    if((this->Tos_) == (static_cast<int>(this->stack_size_)) -1)
    {
        std::cout<<"Stack is Full!!\n";
    }
    else
    {
        this->stk_[++Tos_] = value;
    }
}

void Stack::printStack() const
{
    if((this->Tos_) == -1)
    {
        std::cout<<"Stack is Empety!\n"<<std::endl;
    }
    else 
    {
        for(int i=0 ; i<= (this->Tos_) ; i++)
        {
            std::cout<<"Stack Element["<<i<<"]: "<<this->stk_[i]<<std::endl;
        }
        std::cout<<std::endl;
    }
}

unsigned int Stack::getStackSize() const
{
    return(this->stack_size_);
}

const int* Stack::getStackAddress() const
{
    return(this->stk_);
}

int Stack::getStackTos() const
{
    if(this->Tos_ == -1)
    {
        std::cout<<"Stack is Empty!\n";
        return -1;
    }

    return(this->Tos_);
}

void Stack::setStackSize(const unsigned int &size)
{
    this->stack_size_ = size;
    delete[] this->stk_;
    this->stk_ = new int[this->stack_size_];
    this->Tos_ = -1;
}

Stack& Stack::operator=(const Stack&obj)
{

    if(this == &obj)
    {
        return(*this);
    }

    this->stack_size_ = obj.stack_size_;
    delete[] stk_;
    this->stk_ = new int[obj.stack_size_];

    for(int i=0 ; i<= obj.Tos_ ; i++)
    {
        this->stk_[i] = obj.stk_[i];
    }

    this->Tos_ = obj.Tos_;

    return(*this);
}

int Stack::getStackCount()
{
    return(stack_cout);
}