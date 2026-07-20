/**
 * @file complex.hh
 * @brief Declaration of the Complex class.
 *
 * This file declares the Complex class, which represents a complex
 * number in the form:
 *
 *      a + bi
 *
 * The class provides constructors, setters, getters, arithmetic
 * operator overloading, stream insertion/extraction operators,
 * and increment/decrement operators.
 */

#ifndef _COMPLEC_HPP_
#define _COMPLEC_HPP_

#include <iostream>

/**
 * @class Complex
 * @brief Represents a complex number.
 *
 * The Complex class stores the real and imaginary parts of a
 * complex number and provides various arithmetic and utility
 * operations through operator overloading.
 */
class Complex
{
    public:
    /**
     * @brief Default constructor.
     *
     * Initializes the real and imaginary parts to zero.
     */
    Complex();

    /**
     * @brief Constructs a complex number with identical real and imaginary parts.
     *
     * @param x Value assigned to both the real and imaginary parts.
     */
    Complex(const double &x);

    /**
     * @brief Constructs a complex number.
     *
     * @param real Real part.
     * @param imagin Imaginary part.
     */
    Complex(const double &real, const double &imagin);
    /**
     * @brief Copy constructor.
     *
     * @param obj Complex object to copy.
     */
    Complex(const Complex &obj);

     /**
     * @brief Destructor.
     */
    ~Complex();

    /**
     * @brief Sets the real part.
     *
     * @param real Real value.
     */
    void setReal(const double &real);

    /**
     * @brief Sets the imaginary part.
     *
     * @param imagin Imaginary value.
     */
    void setImagin(const double &imagin);

    /**
     * @brief Sets both real and imaginary parts.
     *
     * @param real Real value.
     * @param imagin Imaginary value.
     */
    void setComplex(const double &real, const double &imagin);

    /**
     * @brief Returns the real part.
     *
     * @return Real part.
     */
    double getReal() const;

    /**
     * @brief Returns the imaginary part.
     *
     * @return Imaginary part.
     */
    double getImagin() const;

    /**
     * @brief Prints the complex number.
     *
     * Displays the complex number in standard mathematical form.
     */
    void printComplex() const;

     /**
     * @brief Adds two complex numbers.
     *
     * @param obj Complex number to add.
     * @return Sum of the two complex numbers.
     */
    Complex operator+(const Complex & obj);

    /**
     * @brief Subtracts two complex numbers.
     *
     * @param obj Complex number to subtract.
     * @return Difference of the two complex numbers.
     */
    Complex operator-(const Complex & obj);

    /**
     * @brief Multiplies two complex numbers.
     *
     * @param obj Complex number to multiply.
     * @return Product of the two complex numbers.
     */
    Complex operator*(const Complex & obj);

    /**
     * @brief Divides two complex numbers.
     *
     * @param obj Complex number to divide by.
     * @return Quotient of the two complex numbers.
     */
    Complex operator/(const Complex & obj);

     /**
     * @brief Outputs a complex number to a stream.
     *
     * @param os Output stream.
     * @param obj Complex object to print.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Complex& obj);

    /**
     * @brief Reads a complex number from a stream.
     *
     * @param is Input stream.
     * @param obj Complex object to receive the input.
     * @return Reference to the input stream.
     */
    friend std::istream& operator>>(std::istream& is,Complex& obj);

    /**
     * @brief Adds another complex number to this object.
     *
     * @param obj Complex number to add.
     */
    void operator-=(const Complex & obj);

    /**
     * @brief Subtracts another complex number from this object.
     *
     * @param obj Complex number to subtract.
     */
    void operator+=(const Complex & obj);

    
    /**
     * @brief Prefix increment operator.
     *
     * Increments the real part by one.
     */
    void operator++();

    /**
     * @brief Prefix decrement operator.
     *
     * Decrements the real part by one.
     */
    void operator--();

    private:
    double real;
    double imagin;
};

#endif /* _COMPLEC_HPP_ */