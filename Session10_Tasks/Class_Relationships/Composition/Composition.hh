
/**
 * @file Composition.hh
 * @author Sara Saad Mahmoud
 * @brief Demonstrates the Composition relationship in Object-Oriented Programming (OOP) using C++.
 * @version 1.0
 * @date 2026-07-23
 *
 * @details
 * This project demonstrates the Composition relationship between two classes:
 * Engin and Car.
 *
 * A Car object owns an Engin object as one of its data members. The Engin
 * object is created and destroyed together with the Car object, meaning its
 * lifetime depends entirely on the Car object.
 *
 * This represents a strong "has-a" relationship known as Composition.
 *
 * @note
 * The Car class owns the Engin object and is responsible for its lifetime.
 * When a Car object is destroyed, its Engin object is automatically destroyed.
 *
 * @copyright
 * Copyright (c) 2026 Sara Saad Mahmoud. All rights reserved.
 */

#ifndef _COMOPSATION_HPP_
#define _COMOPSATION_HPP_

#include <string>

/**
 * @class Engin
 * @brief Represents a car engine.
 *
 * The Engin class stores information about an engine,
 * including its model and horsepower.
 */
class Engin
{
public:

    /**
     * @brief Default constructor.
     */
    Engin();

    /**
     * @brief Parameterized constructor.
     *
     * @param model Engine model.
     * @param hourse_power Engine horsepower.
     */
    Engin(const std::string &model, const double hourse_power);

    /**
     * @brief Copy constructor.
     *
     * @param obj Engine object to copy.
     */
    Engin(const Engin &obj);

    /**
     * @brief Destructor.
     */
    ~Engin();

    /**
     * @brief Returns the engine model.
     *
     * @return Constant reference to the engine model.
     */
    const std::string &getEnginModel() const;

    /**
     * @brief Returns the engine horsepower.
     *
     * @return Engine horsepower.
     */
    double getEnginHoursepower() const;

    /**
     * @brief Sets the engine model.
     *
     * @param model New engine model.
     */
    void setEnginModel(const std::string &model);

    /**
     * @brief Sets the engine horsepower.
     *
     * @param hourse_power New engine horsepower.
     */
    void setEnginHoursepower(const double hourse_power);

    /**
     * @brief Prints all engine information.
     */
    void printEnginInfo() const;

private:

    /** Engine model. */
    std::string model_;

    /** Engine horsepower. */
    double hourse_power_;
};

/**
 * @class Car
 * @brief Represents a car that owns an engine.
 *
 * The Car class demonstrates the Composition relationship
 * by containing an Engin object as one of its private data
 * members.
 *
 * The Engin object cannot exist independently inside the
 * Car class because it is owned by the Car object.
 */
class Car
{
public:

    /**
     * @brief Default constructor.
     */
    Car();

    /**
     * @brief Parameterized constructor.
     *
     * @param brand Car brand.
     * @param model_year Manufacturing year.
     * @param model Engine model.
     * @param hourse_power Engine horsepower.
     */
    Car(const std::string &brand,
        const unsigned int model_year,
        const std::string &model,
        const double hourse_power);

    /**
     * @brief Copy constructor.
     *
     * @param obj Car object to copy.
     */
    Car(const Car &obj);

    /**
     * @brief Destructor.
     */
    ~Car();

    /**
     * @brief Returns the car brand.
     *
     * @return Constant reference to the car brand.
     */
    const std::string &getCarBrand() const;

    /**
     * @brief Returns the model year.
     *
     * @return Car model year.
     */
    unsigned int getModelYear() const;

    /**
     * @brief Returns the engine owned by the car.
     *
     * @return Constant reference to the engine object.
     */
    const Engin &getCarEngin() const;

    /**
     * @brief Sets the car brand.
     *
     * @param brand New car brand.
     */
    void setCarBrand(const std::string &brand);

    /**
     * @brief Sets the car model year.
     *
     * @param model_year New model year.
     */
    void setCarModelYear(const unsigned int model_year);

    /**
     * @brief Replaces the current engine.
     *
     * @param engin Engine object.
     */
    void setCarEngin(const Engin &engin);

    /**
     * @brief Prints all car information, including engine details.
     */
    void printCarInfo() const;

private:

    /** Car brand. */
    std::string brand_;

    /** Manufacturing year. */
    unsigned int model_year_;

    /**
     * @brief Engine owned by the car.
     *
     * This member demonstrates the Composition relationship.
     * The Car object owns this Engin object, and its lifetime
     * is automatically managed by the Car.
     */
    Engin engin_;
};

#endif /* _COMOPSATION_HPP_ */

