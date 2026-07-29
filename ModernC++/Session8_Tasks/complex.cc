/**
 * @file complex.cc
 * @brief Implementation of the Complex class.
 *
 * This file implements the member functions and overloaded operators
 * of the Complex class. It provides support for creating, modifying,
 * printing, and performing arithmetic operations on complex numbers.
 */

#include "complex.hh"
#include <iostream>
#include <cmath>

Complex::Complex()
{
    real = 0;
    imagin = 0;
    std::cout<<"Default Constructor Called!\n";
}

Complex::Complex(const double &x)
{
    real = x;
    imagin = x;
    std::cout<<"One Parameter Concstructor Called!\n";
}

Complex::Complex(const double &real, const double &imagin)
{
    this -> real = real;
    this -> imagin = imagin;
    std::cout<<"Two Parameter Concstructor Called!\n";
}

Complex::Complex(const Complex &obj)
{
    this -> real = obj.real;
    this ->imagin = obj.imagin;
    std::cout<<"Copy Concstructor Called!\n";
}

Complex::~Complex()
{
    std::cout<<"Default Destructor Called!\n";
}

void Complex::setReal(const double &real)
{
    this->real = real;
}

void Complex::setImagin(const double &imagin)
{
    this->imagin = imagin;
}

void Complex::setComplex(const double &real, const double &imagin)
{
    this->real = real;
    this->imagin = imagin;
}

double Complex::getReal() const
{
    return(this->real);
}

double Complex::getImagin() const
{
    return(this->imagin);
}

void Complex::printComplex() const
{
    if(( (this->real) != 0 ) && ((this->imagin) >0))
    {
        std::cout<<this->real<<" +"<<this->imagin<<"i"<<std::endl;
    }
    else if (((this->real == 0)) && ((this->imagin) != 0))
    {
        std::cout<<this->imagin<<"i"<<std::endl;
    }
    else if (((this->real)!= 0) && ((this->imagin) == 0))
    {
        std::cout<<this->real<<std::endl;
    }
    else if (((this->real) != 0) &&((this->imagin) < 0))
    {
        std::cout<<this->real<<" -"<<std::abs(this->imagin)<<"i"<<std::endl;
    }
    else if (((this->real == 0)) && ((this->imagin) == 0))
    {
        std::cout<<this->real<<std::endl;
    }
}

Complex Complex::operator+(const Complex & obj)
{
    Complex temp;
    temp.real = (this->real) + (obj.real);
    temp.imagin = (this->imagin) + (obj.imagin);
    return(temp);
}

Complex Complex::operator-(const Complex & obj)
{
    Complex temp;
    temp.real = (this->real) - (obj.real);
    temp.imagin = (this->imagin) - (obj.imagin);
    return(temp);
}

Complex Complex::operator*(const Complex & obj)
{
    Complex temp;
    temp.real = real * obj.real - this->imagin * obj.imagin;
    temp.imagin = real * obj.imagin + this->imagin * obj.real;
    return(temp);
}

Complex Complex::operator/(const Complex & obj)
{
    Complex temp;
    double den = (obj.real * obj.real) + (obj.imagin * obj.imagin);
    if (den == 0)
    {
        std::cout << "Division by zero!\n";
        return Complex();
    }
    temp.real =((real * obj.real) + (imagin * obj.imagin)) / den;
    temp.imagin =((imagin * obj.real) - (real * obj.imagin)) / den;

    return(temp);
}

void Complex::operator-=(const Complex & obj)
{
   (this->real) -= (obj.real);
   (this->imagin) -= (obj.imagin);
}

void Complex::operator+=(const Complex & obj)
{
    (this->real) += (obj.real);
    (this->imagin) += (obj.imagin);
}

void Complex::operator++()
{
    (this->real) += 1;
}

void Complex::operator--()
{
    (this->real) -= 1;
}

std::ostream& operator<<(std::ostream& os, const Complex& obj)
{
    os << obj.real << " + " << obj.imagin << "i";
    return os;
}

std::istream& operator>>(std::istream& is,Complex& obj)
{
    is >> obj.real >> obj.imagin;
    return is;
}