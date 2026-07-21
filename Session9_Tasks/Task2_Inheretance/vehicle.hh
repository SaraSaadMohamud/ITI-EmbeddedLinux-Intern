#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include <string>

class Vehicle
{
    public:
    Vehicle();
    Vehicle(const std::string &name);
    virtual ~Vehicle();

    std::string getVehicleName() const;
    std::string getVehicleColor() const;
    std::string getVehicleFuelType() const;
    unsigned int getVehicleID() const;
    unsigned int getVehicleYear() const;

    void setVehicleName(const std::string &name);
    void setVehicleColor(const std::string &color);
    void setVehicleFuelType(const std::string &fuel_type);
    void setVehicleID(const unsigned int &id);
    void setVehicleYear(const unsigned int &year);

    virtual void printVehicleInfo() const;

    protected:
    std::string name_;
    std::string color_;
    std::string fuel_type_;
    unsigned int vehicle_id_;
    unsigned int vehicle_year_;

};

class Car : public Vehicle
{
    public:
    Car();
    Car(const std::string &name);
    virtual void printVehicleInfo() const override;

    unsigned int getDoorNumber() const;
    void setDoorNumber(const unsigned int & num);

    protected:
    unsigned int door_number_;
};

class Bicycle : public Vehicle
{
    public:
    Bicycle();
    Bicycle(const std::string &name);
    virtual void printVehicleInfo() const override;

    bool getBasketState() const;
    void setBasketState(const bool &state);

    protected:
    bool has_basket_;
};

class Motorcycle : public Vehicle
{
    public:
    Motorcycle();
    Motorcycle(const std::string &name);
    virtual void printVehicleInfo() const override;

    unsigned int getWheelNumber() const;
    void setWheelNumber(const unsigned int &num);

    protected:
    unsigned int wheel_number_;
};

class Plane : public Vehicle
{
    public:
    Plane();
    Plane(const std::string &name);
    virtual void printVehicleInfo() const override;

    double getMaxAltitude() const;
    void setMaxAltitude(const double &max);

    protected:
    double max_altitude_;
};

class Truck: public Vehicle
{
    public:
    Truck();
    Truck(const std::string &name);
    virtual void printVehicleInfo() const override;

    double getLoadingCapacity() const;
    void setLoadingCapacity(const double &capcity);

    protected:
    double load_capacity_;
};


class BMW : public Car
{
    public:
    BMW();
    BMW(const std::string &name);
    void printVehicleInfo() const override;

    private:
};

class Toyota : public Car
{
    public:
    Toyota();
    Toyota(const std::string &name);
    void printVehicleInfo() const override;

    private:
};

class Boeing : public Plane
{
    public:
    Boeing();
    Boeing(const std::string &name);
    void printVehicleInfo() const override;
    
    private:
};

class MercedesTruck : public Truck
{
    public:
    MercedesTruck();
    MercedesTruck(const std::string &name);
    void printVehicleInfo() const override;
    
    private:
};

class VolvoTruck : public Truck
{
    public:
    VolvoTruck();
    VolvoTruck(const std::string &name);
    void printVehicleInfo() const override;
    
    private:
};

class HondaMotorcycle : public Motorcycle
{
    public:
    HondaMotorcycle();
    HondaMotorcycle(const std::string &name);
    void printVehicleInfo() const override;
    
    private:
};



#endif /* _VEHICLE_HPP_ */