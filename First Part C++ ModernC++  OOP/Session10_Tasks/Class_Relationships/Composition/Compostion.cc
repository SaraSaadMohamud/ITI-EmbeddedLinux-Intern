/**  
 * @file Composition.cpp 
 * @author Sara Saad Mahmoud 
 * @brief Implementation of the Engin and Car classes demonstrating the 
 * Composition relationship in C++. 
 * @version 1.0 
 * @date 2026-07-23 
 * @details 
 * This source file implements the member functions of the Engin and Car 
 * classes. It demonstrates the Composition relationship, where a Car object 
 * owns an Engin object as one of its data members. 
 * Unlike Aggregation or Association, the Engin object cannot exist as part 
 * of the Car independently. The Car object is responsible for constructing 
 * and destroying its Engin object automatically. 
 * @note 
 * The Engin object is stored directly inside the Car object (not as a pointer), 
 * making this a strong "has-a" relationship (Composition). 
 * 
 */

#include "Composition.hh"
#include <iostream>

Engin::Engin()
{
    std::cout<<"Default Constructor Called!\n";
}

Engin::Engin(const std::string &model, const double hourse_power)
{
    model_          = model;
    hourse_power_   = hourse_power;
    std::cout<<"Parametrize Constructor Called!\n";
}

Engin::Engin(const Engin &obj)
{
    model_          = obj.model_;
    hourse_power_   = obj.hourse_power_;
    std::cout<<"Copy Constructor Called!\n";
}

Engin::~Engin()
{
    std::cout<<"Default Destructor Called!\n";
}

const std::string &Engin::getEnginModel() const
{
    return(this->model_);
}

double Engin::getEnginHoursepower() const
{
    return(this->hourse_power_);
}

void Engin::setEnginModel(const std::string &model)
{
    model_ = model;
}

void Engin::setEnginHoursepower(const double hourse_power)
{
    hourse_power_ = hourse_power;
}

void Engin::printEnginInfo() const
{
    std::cout<<"Engin Model         : "<<model_         <<std::endl;
    std::cout<<"Engin Hourse_power  : "<<hourse_power_  <<std::endl;
}

Car::Car()
{
    std::cout<<"Default Constructor Called!\n";
}

Car::Car(const std::string &brand,const unsigned int model_year, const std::string &model, const double hourse_power)
{
    brand_          = brand;
    model_year_     = model_year;
    engin_ .setEnginModel(model);
    engin_.setEnginHoursepower(hourse_power);
    std::cout<<"Parametrize Constructor Called!\n";
}

Car::Car(const Car &obj)
{
    brand_          = obj.brand_;
    model_year_     = obj.model_year_;
    engin_ .setEnginModel(obj.engin_.getEnginModel());
    engin_.setEnginHoursepower(obj.engin_.getEnginHoursepower());
    std::cout<<"Copy Constructor Called!\n";
}

Car::~Car()
{
    std::cout<<"Default Destructor Called!\n";
}

const std::string &Car::getCarBrand() const
{
    return(this->brand_);
}

unsigned int Car::getModelYear() const
{
    return(this->model_year_);
}

const Engin &Car::getCarEngin() const
{
    return(this->engin_);
}

void Car::setCarBrand(const std::string &brand)
{
    brand_ = brand;
}

void Car::setCarModelYear(const unsigned int model_year)
{
    model_year_ = model_year;
}

void Car::setCarEnginModel(const std::string &model)
{
    engin_.setEnginModel(model);
}

void Car::setCarEnginHoursePower(const double hourse_power)
{
    engin_.setEnginHoursepower(hourse_power);
}

void Car::printCarInfo() const
{
    std::cout<<"Car Brand           : "<<brand_         <<std::endl;
    std::cout<<"Car Model_year      : "<<model_year_    <<std::endl;
    engin_.printEnginInfo();
}