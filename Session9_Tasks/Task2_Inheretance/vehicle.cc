#include <iostream>
#include "vehicle.hh"

Vehicle::Vehicle()
{
    this->name_ = "SSD";
    this->color_ = "Black";
    this->fuel_type_ = "GAS";
    this->vehicle_id_ = 1234;
    this->vehicle_year_ = 2026;
    std::cout<<"Vehicle Defualt Constructor Called!!\n"<<std::endl;
}

Vehicle::Vehicle(const std::string &name, const std::string &color, const std::string &fuel_type, 
                 const unsigned int vehicle_id,const  unsigned int vehicle_year)
{
    this->name_ = name;
    this->color_ = color;
    this->fuel_type_ = fuel_type;
    this->vehicle_id_ = vehicle_id;
    this->vehicle_year_ = vehicle_year;
    std::cout<<"Vehicle Parameteriez Constructor Called!!\n"<<std::endl;
}

Vehicle::Vehicle(const Vehicle &obj)
{
    this->name_ = obj.name_;
    this->color_ = obj.color_;
    this->fuel_type_ = obj.fuel_type_;
    this->vehicle_id_ = obj.vehicle_id_;
    this->vehicle_year_ = obj.vehicle_year_;
    std::cout<<"Vehicle Copy Constructor Called!!\n"<<std::endl;
}

Vehicle::~Vehicle()
{
    std::cout<<"Vehicle Default Destructor Called\n";
}

const std::string &Vehicle::getVehicleName() const
{
    return (this->name_);
}

const std::string &Vehicle::getVehicleColor() const
{
    return(this->color_);
}

const std::string &Vehicle::getVehicleFuelType() const
{
    return(this->fuel_type_);
}

unsigned int Vehicle::getVehicleID() const
{
    return(this->vehicle_id_);
}

unsigned int Vehicle::getVehicleYear() const
{
    return(this->vehicle_year_);
}

void Vehicle::setVehicleName(const std::string &name)
{
    this->name_ = name;
}

void Vehicle::setVehicleColor(const std::string &color)
{
    this->color_ = color;
}

void Vehicle::setVehicleFuelType(const std::string &fuel_type)
{
    this->fuel_type_ = fuel_type;
}

void Vehicle::setVehicleID(const unsigned int &id)
{
    this->vehicle_id_ = id;
}

void Vehicle::setVehicleYear(const unsigned int &year)
{
    this->vehicle_year_ = year;
}

void Vehicle::printVehicleInfo() const
{
    std::cout<<"=================== Vechicle Information ========================\n\n";
    std::cout<<"Name        : "<<this->name_            <<std::endl;
    std::cout<<"Color       : "<<this->color_           <<std::endl;
    std::cout<<"Fuel Type   : "<<this->fuel_type_       <<std::endl;
    std::cout<<"ID          : "<<this->vehicle_id_      <<std::endl;
    std::cout<<"Year        : "<<this->vehicle_year_    <<std::endl;
}

/*****************************************************************************************************************************************************/

Car::Car()
{
    this->name_         = "Electrical Car";
    this->color_        = "Black";
    this->fuel_type_    = "Electricity";
    this->vehicle_id_   = 5493;
    this->vehicle_year_ = 2026;
    this->door_number_  = 4;
    std::cout<<"Car Defualt Constructor Called!!\n"<<std::endl;
}

Car::Car(const std::string &name, const std::string &color, const std::string &fuel_type, 
         const unsigned int vehicle_id,const  unsigned int vehicle_year, const unsigned int door_number)
{
    this->name_         = name;
    this->color_        = color;
    this->fuel_type_    = fuel_type;
    this->vehicle_id_   = vehicle_id;
    this->vehicle_year_ = vehicle_year;
    this->door_number_  = door_number;
    std::cout<<"Car Parameteriez Constructor Called!!\n"<<std::endl;
}

Car::Car(const Car &obj)
{
    this->name_         = obj.name_;
    this->color_        = obj.color_;
    this->fuel_type_    = obj.fuel_type_;
    this->vehicle_id_   = obj.vehicle_id_;
    this->vehicle_year_ = obj.vehicle_year_;
    this->door_number_  = obj.door_number_;
    std::cout<<"Car Copy Constructor Called!!\n"<<std::endl;
}

Car::~Car()
{
    std::cout<<"Car Default Destructor Called\n";
}

void Car::printVehicleInfo() const 
{
    Vehicle::printVehicleInfo();
    std::cout<<"Door Number : "<<this->door_number_     <<std::endl;
    
}

unsigned int Car::getDoorNumber() const
{
    return (this->door_number_);
}

void Car::setDoorNumber(const unsigned int & num)
{
    this->door_number_ = num;
}

/*****************************************************************************************************************************************************/

Bicycle::Bicycle(): Vehicle("Mountain Bicycle", "White" , "None" , 999, 2025)
{
    this->has_basket_ = true;
    std::cout<<"Bicycle Default Constructor Called!!\n"<<std::endl;
}

Bicycle::Bicycle(const std::string &name, const std::string &color, const std::string &fuel_type, 
                 const unsigned int vehicle_id,const unsigned int vehicle_year, bool has_basket): 
                 Vehicle(name,color,fuel_type,vehicle_id,vehicle_year)
{
    this->has_basket_ = has_basket;
    std::cout<<"Bicycle Parameteriez Constructor Called!!\n"<<std::endl;
}

Bicycle::Bicycle(const Bicycle &obj):Vehicle(obj)
{
    this->has_basket_ = obj.has_basket_;
    std::cout<<"Bicycle Copy Constructor Called!!\n"<<std::endl;
}

Bicycle::~Bicycle()
{
    std::cout<<"Bicycle Default Destructor Called\n";
}

void Bicycle::printVehicleInfo() const 
{
    Vehicle::printVehicleInfo();
    std::cout<<"Is there a Bicycle Basket: "<<std::boolalpha<<this->has_basket_<<std::endl;
    std::cout<<"Copy Constructor Called!!\n"<<std::endl;
}

bool Bicycle::getBasketState() const
{
    return(this->has_basket_);
}

void Bicycle::setBasketState(const bool state)
{
    this->has_basket_ = state;
}

/*********************************************************************************************************************************************************************/

Motorcycle::Motorcycle() :Vehicle("Honda","Pink","Petrol",1000,2025), wheel_number_(2)
{
    std::cout<<"Motorcycle Default Constructor Called!!\n"<<std::endl;
}

Motorcycle::Motorcycle(const std::string &name, const std::string &color, const std::string &fuel_type, 
           const unsigned int vehicle_id,const  unsigned int vehicle_year, const unsigned int wheel_number) : Vehicle(name,color,fuel_type,vehicle_id,vehicle_year),
           wheel_number_(wheel_number)
{
    std::cout<<"Motorcycle Parameteriez Constructor Called!!\n"<<std::endl;
}

Motorcycle::Motorcycle(const Motorcycle &obj) : Vehicle(obj), wheel_number_(obj.wheel_number_)
{
    std::cout<<"Motorcycle Copy Constructor Called!!\n"<<std::endl;
}

Motorcycle::~Motorcycle()
{
    std::cout<<"Motorcycle Default Destructor Called\n";
}

void Motorcycle::printVehicleInfo() const
{
    Vehicle::printVehicleInfo();
    std::cout<<"Wheel Number: "<<this->wheel_number_<<std::endl;
}

unsigned int Motorcycle::getWheelNumber() const
{
    return(this->wheel_number_);
}
void Motorcycle::setWheelNumber(const unsigned int num)
{
    this->wheel_number_ = num;
}

/*********************************************************************************************************************************************************************/

Plane::Plane():Vehicle("Boeing",
                       "Gray",
                        "Petrol",
                        1987,
                        2025),
                        max_altitude_(1250)
{
    std::cout<<"Plane Defualt Constructor Called!!\n"<<std::endl;
}

Plane::Plane(const std::string &name, const std::string &color, const std::string &fuel_type, 
      const unsigned int vehicle_id,const  unsigned int vehicle_year, const double max_altitude): Vehicle(name,
                                                                               color,
                                                                               fuel_type,
                                                                               vehicle_id,
                                                                               vehicle_year),
                                                                               max_altitude_(max_altitude)
{
    std::cout<<"Plane Parameteriez Constructor Called!!\n"<<std::endl;
}

Plane::Plane(const Plane &obj) : Vehicle(obj), max_altitude_(obj.max_altitude_)
{
    std::cout<<"Plane Copy Constructor Called!!\n"<<std::endl;
}

Plane::~Plane()
{
    std::cout<<"Plane Default Destructor Called\n";
}

void Plane::printVehicleInfo() const{
    Vehicle::printVehicleInfo();
    std::cout<<"Max Altitude: "<<this->max_altitude_<<std::endl;
}

double Plane::getMaxAltitude() const{
    return(this->max_altitude_);
}

void Plane::setMaxAltitude(const double &max){
    this->max_altitude_ = max;
}

/*********************************************************************************************************************************************************************/

Truck::Truck(): Vehicle("Volvo",
                        "Blue",
                        "Petrol",
                        5213,
                        2026), load_capacity_(2000.00)
{
    std::cout<<"Truck Default Constructor Called!!\n"<<std::endl;
}

Truck::Truck(const std::string &name, const std::string &color, const std::string &fuel_type, 
             const unsigned int vehicle_id,const  unsigned int vehicle_year, const double load_capacity):
             Vehicle(name,
                     color,
                     fuel_type,
                     vehicle_id,
                     vehicle_year),
                     load_capacity_(load_capacity)
{
    std::cout<<"Truck Parameteriez Constructor Called!!\n"<<std::endl;
}

Truck::Truck(const Truck &obj): Vehicle(obj), load_capacity_(obj.load_capacity_)
{
    std::cout<<"Truck Copy Constructor Called!!\n"<<std::endl;
}

Truck::~Truck()
{
    std::cout<<"Truck Default Destructor Called\n";
}

void Truck::printVehicleInfo() const 
{
    Vehicle::printVehicleInfo();
    std::cout<<"Loading Capacity: "<<this->load_capacity_<<std::endl;
}

double Truck::getLoadingCapacity() const
{
    return(this->load_capacity_);
}

void Truck::setLoadingCapacity(const double &capacity)
{
    this->load_capacity_ = capacity;
}

/*********************************************************************************************************************************************************************/
BMW::BMW() : Car("BMW",
                 "Black",
                 "Petrol",
                 1234,
                 2026,
                 4), series_("7 Series")
{
    std::cout<<"BMW Default Constructor Called!!\n"<<std::endl;
}

BMW::BMW(const std::string &name, const std::string &color, const std::string &fuel_type, 
    const unsigned int vehicle_id,const  unsigned int vehicle_year,const unsigned int door_number, const std::string &series) : 
    Car(name,
    color,
    fuel_type,
    vehicle_id,
    vehicle_year,
    door_number),
    series_(series)
{
    std::cout<<"BMW Parameteriez Constructor Called!!\n"<<std::endl;
}

BMW::BMW(const BMW &obj): Car(obj), series_(obj.series_)
{
    std::cout<<"BMW Copy Constructor Called!!\n"<<std::endl;
}

BMW::~BMW()
{
    std::cout<<"BMW Default Destructor Called\n";
}

void BMW::printVehicleInfo() const
{
    Car::printVehicleInfo();
    std::cout<<"Series: "<<this->series_<<std::endl;
}

const std::string &BMW::getSeries() const
{
    return(this->series_);
}
void BMW::setSeries(const std::string &series)
{
    this->series_ = series;
}

/*********************************************************************************************************************************************************************/
Toyota::Toyota(): Car("Toyota",
                 "Black",
                 "Petrol",
                 1234,
                 2026,
                 4), model_("Corolla")
{
    std::cout<<"Toyota Default Constructor Called!!\n"<<std::endl;
}

Toyota::Toyota(const std::string &name, const std::string &color, const std::string &fuel_type, 
             const unsigned int vehicle_id,const  unsigned int vehicle_year, const unsigned int door_number, const std::string &model) : 
             Car(name,
                color,
                fuel_type,
                vehicle_id,
                vehicle_year,
                door_number),
                model_(model)
{
    std::cout<<"Toyota Parameteriez Constructor Called!!\n"<<std::endl;
}

Toyota::Toyota(const Toyota &obj) : Car(obj), model_(obj.model_)
{
    std::cout<<"Toyota Copy Constructor Called!!\n"<<std::endl;
}

Toyota::~Toyota()
{
    std::cout<<"Toyota Default Destructor Called\n";
}

void Toyota::printVehicleInfo() const
{
    Car::printVehicleInfo();
    std::cout<<"Model: "<<this->model_<<std::endl;
}

const std::string &Toyota::getModel() const
{
    return(this->model_);
}
void Toyota::setModel(const std::string &model)
{
    this->model_ = model;
}

/*********************************************************************************************************************************************************************/
Boeing::Boeing(): Plane("Boeing",
                        "White",
                        "Petrol",
                         1505,
                         2025,
                         2500), passenger_capacity_(250)
{
    std::cout<<"Boeing Default Constructor Called!!\n"<<std::endl;
}

Boeing::Boeing(const std::string &name, const std::string &color, const std::string &fuel_type, 
       const unsigned int vehicle_id,const  unsigned int vehicle_year, double max_altitude, unsigned int passenger_capacity): 
       Plane(name,
        color,
        fuel_type,
        vehicle_id,
        vehicle_year,
        max_altitude),
        passenger_capacity_(passenger_capacity)
{
    std::cout<<"Boeing Parameteriez Constructor Called!!\n"<<std::endl;
}

Boeing::Boeing(const Boeing &obj) : Plane(obj), passenger_capacity_(obj.passenger_capacity_)
{
    std::cout<<"Boeing Copy Constructor Called!!\n"<<std::endl;
}

Boeing::~Boeing()
{
    std::cout<<"Car Default Destructor Called\n";
}

void Boeing::printVehicleInfo() const
{
    Plane::printVehicleInfo();
    std::cout<<"Passenger Capacity: "<<this->passenger_capacity_<<std::endl;
}

unsigned int Boeing::getPassengerCapacity() const
{
    return(this->passenger_capacity_);
}

void Boeing::setPassengerCapacity(const unsigned int &capacity)
{
    this->passenger_capacity_ = capacity;
}

/*********************************************************************************************************************************************************************/

VolvoTruck::VolvoTruck(): Truck("Volvo",
                                "Black",
                                "Petrol",
                                101,
                                2024,
                                2500), 
                                refrigerated_(true)
{
    std::cout<<"VolvoTruck Default Constructor Called!!\n"<<std::endl;
}

VolvoTruck::VolvoTruck(const std::string &name, const std::string &color, const std::string &fuel_type, 
           const unsigned int vehicle_id,const  unsigned int vehicle_year, double load_capacity, bool refrigerated):
           Truck(name,
                 color,
                 fuel_type,
                 vehicle_id,
                 vehicle_year,
                 load_capacity),
                 refrigerated_(refrigerated)
{
    std::cout<<"VolvoTruck Parameteriez Constructor Called!!\n"<<std::endl;
}

VolvoTruck::VolvoTruck(const VolvoTruck&obj):Truck(obj), refrigerated_(obj.refrigerated_)
{
    std::cout<<"VolvoTruck Copy Constructor Called!!\n"<<std::endl;
}

VolvoTruck::~VolvoTruck()
{
    std::cout<<"VolvoTruck Default Destructor Called\n";
}

void VolvoTruck::printVehicleInfo() const
{
    Truck::printVehicleInfo();
    std::cout<<"Is The Truck has Refrigerated: "<<std::boolalpha<<this->refrigerated_<<std::endl;
}

bool VolvoTruck::getRefrigeratedStatus() const
{
    return(this->refrigerated_);
}

void VolvoTruck::setRefrigeratedStatus(const bool state)
{
    this->refrigerated_ = state;
}

/*********************************************************************************************************************************************************************/

HondaMotorcycle::HondaMotorcycle() :Motorcycle("Honda",
                                                "Black",
                                                "Petrol",
                                                195,
                                                2023,
                                                2), abs_system_(true)
{
    std::cout<<"HondaMotorcycle Default Constructor Called!!\n"<<std::endl;
}

HondaMotorcycle::HondaMotorcycle(const std::string &name, const std::string &color, const std::string &fuel_type, 
                    const unsigned int vehicle_id,const  unsigned int vehicle_year, const unsigned int wheel_number, const bool abs_system):
                    Motorcycle(name,
                               color,
                               fuel_type,
                               vehicle_id,
                               vehicle_year,
                               wheel_number),
                               abs_system_(abs_system)
{
    std::cout<<"HondaMotorcycle Parameteriez Constructor Called!!\n"<<std::endl;
}


HondaMotorcycle::HondaMotorcycle(const HondaMotorcycle&obj): Motorcycle(obj), abs_system_(obj.abs_system_)
{
    std::cout<<"HondaMotorcycle Copy Constructor Called!!\n"<<std::endl;
}

HondaMotorcycle::~HondaMotorcycle()
{
    std::cout<<"HondaMotorcycle Default Destructor Called\n";
}

void HondaMotorcycle::printVehicleInfo() const
{
    Motorcycle :: printVehicleInfo();
    std::cout<<"Is the Motorcycle has ABS System: "<<std::boolalpha<<std::endl;
}

bool HondaMotorcycle::getABSSystemState() const
{
    return(this->abs_system_);
}
void HondaMotorcycle::setABSSystemState(const bool &state)
{
    this->abs_system_ = state;
}

/*********************************************************************************************************************************************************************/
MountainBike::MountainBike(): Bicycle("Mountain",
                                      "Pink",
                                      "None",
                                      20,
                                      2026,
                                    true), bike_type_("Mountain Bike")
{
    std::cout<<"MountainBike Default Constructor Called!!\n"<<std::endl;
}

MountainBike::MountainBike(const std::string &name, const std::string &color, const std::string &fuel_type, 
             const unsigned int vehicle_id,const  unsigned int vehicle_year, const bool has_basket, const std::string &bike_type):
             Bicycle(name,
                     color,
                     fuel_type,
                     vehicle_id,
                     vehicle_year,
                     has_basket),
                     bike_type_(bike_type)
{
    std::cout<<"MountainBike Parameteriez Constructor Called!!\n"<<std::endl;
}

MountainBike::MountainBike(const MountainBike &obj) : Bicycle(obj), bike_type_(obj.bike_type_)
{
    std::cout<<"MountainBike Copy Constructor Called!!\n"<<std::endl;
}


MountainBike::~MountainBike()
{
    std::cout<<"MountainBike Default Destructor Called\n";
}
void MountainBike::printVehicleInfo() const
{
    Bicycle::printVehicleInfo();
    std::cout<<"Bike Type: "<<this->bike_type_<<std::endl;
}

const std::string &MountainBike::getBikeType() const
{
    return(this->bike_type_);
}

void MountainBike::setBikeType(const std::string &bike_type)
{
    this->bike_type_ = bike_type;
}

/*********************************************************************************************************************************************************************/