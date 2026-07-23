/**
 * @file main.cpp
 * @author Sara Saad Mahmoud
 * @brief Demonstrates the Composition relationship in Object-Oriented Programming (OOP).
 * @version 1.0
 * @date 2026-07-23
 *
 * @details
 * This program demonstrates the Composition relationship between the
 * Car and Engin classes.
 *
 * A Car object is created by providing the car's information along with
 * the engine specifications. The Car object internally creates and owns
 * its Engin object, illustrating a strong "has-a" relationship.
 *
 * Since the Engin object is a member of the Car class, its lifetime is
 * completely dependent on the Car object. When the Car object is destroyed,
 * the Engin object is automatically destroyed as well.
 */

#include "Composition.hh"

int main()
{

    Car c1("BMW", 2025, "V8 Twin Turbo", 550);

    c1.printCarInfo();

    return 0;
}

