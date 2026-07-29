/**
 * @file vehicle.hh
 * @author Sara Saad Mahmoud
 * @brief Vehicle Management System using Object-Oriented Programming.
 * @version 1.0
 * @date July 2026
 *
 * @details
 * This project demonstrates the implementation of Object-Oriented Programming
 * concepts in C++ through a Vehicle Management System.
 *
 * The project models different categories of vehicles using inheritance,
 * allowing common vehicle properties to be shared while enabling each derived
 * class to define its own specialized characteristics.
 *
 * The hierarchy consists of three inheritance levels:
 *
 * Level 1:
 *      Vehicle
 *
 * Level 2:
 *      - Car
 *      - Bicycle
 *      - Motorcycle
 *      - Plane
 *      - Truck
 *
 * Level 3:
 *      - BMW              (inherits from Car)
 *      - Toyota           (inherits from Car)
 *      - Boeing           (inherits from Plane)
 *      - VolvoTruck       (inherits from Truck)
 *      - HondaMotorcycle  (inherits from Motorcycle)
 *      - MountainBike     (inherits from Bicycle)
 *
 * The implementation demonstrates:
 *      - Constructors
 *      - Parameterized Constructors
 *      - Copy Constructors
 *      - Virtual Destructors
 *      - Single and Multilevel Inheritance
 *      - Function Overriding
 *      - Runtime Polymorphism
 *      - Encapsulation
 *      - Getter and Setter Functions
 *      - Dynamic Binding
 *
 * Every class overrides printVehicleInfo() to display its own
 * information while reusing the functionality provided by its parent class.
 */

#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include <string>

/**
 * @class Vehicle
 * @brief Base class representing a generic vehicle.
 *
 * Vehicle stores the common information shared by all vehicles,
 * including name, color, fuel type, identification number,
 * and manufacturing year.
 *
 * This class serves as the parent of the entire vehicle hierarchy
 * and provides a virtual interface for displaying vehicle information.
 */
class Vehicle
{
    public:
    /**
        * @brief Default constructor.
        *
        * Initializes the vehicle with predefined default values.
    */
    Vehicle();

    /**
        * @brief Constructs a vehicle with custom information.
        *
        * @param name Vehicle name.
        * @param color Vehicle color.
        * @param fuel_type Fuel type.
        * @param vehicle_id Unique vehicle identifier.
        * @param vehicle_year Manufacturing year.
    */
    Vehicle(const std::string &name, const std::string &color, const std::string &fuel_type, 
                 const unsigned int vehicle_id,const  unsigned int vehicle_year);

    
    /**
        * @brief Copy constructor.
        *
        * Creates a new Vehicle object as a copy of an existing Vehicle.
        * All data members are copied from the source object to the newly
        * created object.
        *
        * @param obj Vehicle object to be copied.
    */
    Vehicle(const Vehicle &obj);

    /**
        * @brief Virtual destructor.
        *
        * Releases the resources associated with the Vehicle object.
        * Declaring the destructor as virtual ensures that the correct
        * destructor is invoked when deleting an object through a base
        * class pointer, allowing proper cleanup of derived class objects.
    */
    virtual ~Vehicle();

    /**
        * @brief Returns the vehicle name.
        *
        * @return Constant reference to the vehicle name.
    */
    const std::string &getVehicleName() const;

    /**
        * @brief Sets the vehicle color.
        *
        * @param color New vehicle color.
    */
    const std::string &getVehicleColor() const;


    /**
        * @brief Returns the fuel type of the vehicle.
        *
        * This function retrieves the fuel source used by the vehicle,
        * such as Petrol, Diesel, Electric, Hybrid, or any other fuel type.
        *
        * @return Constant reference to the vehicle fuel type.
     */
    const std::string &getVehicleFuelType() const;  

    /**
        * @brief Returns the unique vehicle identifier.
        *
        * Every vehicle has its own identification number that can be
        * used to distinguish it from other vehicles.
        *
        * @return Vehicle ID.
     */
    unsigned int getVehicleID() const;  

    /**
        * @brief Returns the manufacturing year of the vehicle.
        *
        * @return Year in which the vehicle was manufactured.
     */
    unsigned int getVehicleYear() const;    

    /**
        * @brief Sets the vehicle name.
        *
        * Updates the name or manufacturer of the vehicle.
        *
        * @param name New vehicle name.
     */
    void setVehicleName(const std::string &name);   

    /**
        * @brief Sets the vehicle color.
        *
        * Updates the exterior color of the vehicle.
        *
        * @param color New vehicle color.
     */
    void setVehicleColor(const std::string &color); 

    /**
        * @brief Sets the vehicle fuel type.
        *
        * Updates the type of fuel used by the vehicle.
        *
        * @param fuel_type New fuel type.
     */
    void setVehicleFuelType(const std::string &fuel_type);  

    /**
        * @brief Sets the vehicle identification number.
        *
        * Assigns a new unique ID to the vehicle.
        *
        * @param id New vehicle ID.
     */
    void setVehicleID(const unsigned int &id);  

    /**
        * @brief Sets the manufacturing year of the vehicle.
        *
        * Updates the production year of the vehicle.
        *
        * @param year Manufacturing year.
     */
    void setVehicleYear(const unsigned int &year);

    /**
        * @brief Prints all vehicle information.
        *
        * This virtual function can be overridden by derived classes
        * to display additional information while reusing the base
        * class implementation.
    */
    virtual void printVehicleInfo() const;

    protected:
    std::string name_;
    std::string color_;
    std::string fuel_type_;
    unsigned int vehicle_id_;
    unsigned int vehicle_year_;

};

/**
 * @class Car
 * @brief Represents a generic car.
 *
 * The Car class extends Vehicle by adding the number of doors.
 * It serves as the parent class for different car manufacturers
 * such as BMW and Toyota.
 */
class Car : public Vehicle
{
    public:
        /**
            * @brief Default constructor.
            *
            * Creates a Car object and initializes it with predefined
            * default values inherited from the Vehicle class along with
            * a default number of doors.
        */
        Car();      

        /**
            * @brief Parameterized constructor.
            *
            * Creates a Car object with user-defined information.
            *
            * @param name Vehicle name.
            * @param color Vehicle color.
            * @param fuel_type Vehicle fuel type.
            * @param vehicle_id Unique vehicle identifier.
            * @param vehicle_year Manufacturing year.
            * @param door_number Number of doors.
        */
        Car(const std::string &name,
            const std::string &color,
            const std::string &fuel_type,
            const unsigned int vehicle_id,
            const unsigned int vehicle_year,
            const unsigned int door_number);        

        /**
            * @brief Copy constructor.
            *
            * Creates a new Car object as a deep copy of an existing
            * Car object, including all inherited Vehicle data and
            * the number of doors.
            *
            * @param obj Car object to copy.
        */
        Car(const Car &obj);        

        /**
            * @brief Destructor.
            *
            * Destroys the Car object and releases any resources
            * associated with it.
        */
        ~Car();     

        /**
            * @brief Displays complete car information.
            *
            * Overrides Vehicle::printVehicleInfo() to display the
            * common vehicle information inherited from the Vehicle
            * class, followed by the car-specific information such as
            * the number of doors.
        */
        void printVehicleInfo() const override;     

        /**
            * @brief Returns the number of doors.
            *
            * @return Number of car doors.
        */
        unsigned int getDoorNumber() const;     

        /**
            * @brief Sets the number of doors.
            *
            * Updates the number of doors of the car.
            *
            * @param num Number of doors.
        */
        void setDoorNumber(const unsigned int &num);        

            private:
            unsigned int door_number_;
        };      

/**
    * @class Bicycle
    * @brief Represents a bicycle.
    *
    * Adds information about whether the bicycle has a basket.
    * This class is the parent of MountainBike.
*/
class Bicycle : public Vehicle
{
    public:
    Bicycle();
    Bicycle(const std::string &name, const std::string &color, const std::string &fuel_type, 
            const unsigned int vehicle_id,const  unsigned int vehicle_year, bool has_basket);
    Bicycle(const Bicycle &obj);
    ~Bicycle();
    void printVehicleInfo() const override;

    bool getBasketState() const;
    void setBasketState(const bool state);

    private:
    bool has_basket_;
};

/**
 * @class Motorcycle
 * @brief Represents a motorcycle.
 *
 * Adds the number of wheels to the generic Vehicle class.
 * HondaMotorcycle inherits from this class.
 */
class Motorcycle : public Vehicle
{
        public:
    /**
        * @brief Default constructor.
        *
        * Creates a Motorcycle object and initializes it with
        * predefined default values inherited from the Vehicle
        * class along with a default number of wheels.
    */
    Motorcycle();
    
    /**
        * @brief Parameterized constructor.
        *
        * Creates a Motorcycle object with custom information.
        *
        * @param name Motorcycle name.
        * @param color Motorcycle color.
        * @param fuel_type Fuel type used by the motorcycle.
        * @param vehicle_id Unique motorcycle identifier.
        * @param vehicle_year Manufacturing year.
        * @param wheel_number Number of wheels.
    */
    Motorcycle(const std::string &name,
               const std::string &color,
               const std::string &fuel_type,
               const unsigned int vehicle_id,
               const unsigned int vehicle_year,
               const unsigned int wheel_number);
    
    /**
        * @brief Copy constructor.
        *
        * Creates a new Motorcycle object as a copy of an existing
        * Motorcycle object, including all inherited Vehicle data
        * and the wheel count.
        *
        * @param obj Motorcycle object to copy.
    */
    Motorcycle(const Motorcycle &obj);
    
    /**
        * @brief Destructor.
        *
        * Destroys the Motorcycle object and performs any required
        * cleanup before the object is removed from memory.
     */
    ~Motorcycle();
    
    /**
        * @brief Displays complete motorcycle information.
        *
        * Overrides Vehicle::printVehicleInfo() to print the common
        * vehicle information followed by the motorcycle-specific
        * information, including the number of wheels.
    */
    void printVehicleInfo() const override;
    
    /**
        * @brief Returns the number of wheels.
        *
        * @return Number of motorcycle wheels.
    */
    unsigned int getWheelNumber() const;
    
    /**
        * @brief Sets the number of wheels.
        *
        * Updates the wheel count of the motorcycle.
        *
        * @param num Number of wheels.
    */
    void setWheelNumber(const unsigned int num);
    
    private:
        unsigned int wheel_number_;
};

/**
 * @class Plane
 * @brief Represents an aircraft.
 *
 * Stores the maximum operating altitude of the aircraft.
 * Boeing inherits from this class.
     */
    class Plane : public Vehicle
    {
        public:
    /**
        * @brief Default constructor.
        *
        * Creates a Plane object and initializes it with predefined
        * default values inherited from the Vehicle class, along with
        * a default maximum altitude.
    */
    Plane();

    /**
        * @brief Parameterized constructor.
        *
        * Creates a Plane object with user-defined information.
        *
        * @param name Plane name.
        * @param color Plane color.
        * @param fuel_type Fuel type used by the plane.
        * @param vehicle_id Unique plane identifier.
        * @param vehicle_year Manufacturing year.
        * @param max_altitude Maximum operating altitude of the plane.
    */
    Plane(const std::string &name,
          const std::string &color,
          const std::string &fuel_type,
          const unsigned int vehicle_id,
          const unsigned int vehicle_year,
          const double max_altitude);

    /**
        * @brief Copy constructor.
        *
        * Creates a new Plane object as a copy of an existing
        * Plane object, including all inherited Vehicle data
        * and the maximum altitude.
        *
        * @param obj Plane object to copy.
    */
    Plane(const Plane &obj);

    /**
        * @brief Destructor.
        *
        * Destroys the Plane object and performs any necessary
        * cleanup before the object is removed from memory.
     */
    ~Plane();

    /**
        * @brief Displays complete plane information.
        *
        * Overrides Vehicle::printVehicleInfo() to display the
        * common vehicle information followed by the plane-specific
        * information, including the maximum operating altitude.
    */
    void printVehicleInfo() const override;

    /**
        * @brief Returns the maximum operating altitude.
        *
        * @return Maximum altitude of the plane.
    */
    double getMaxAltitude() const;

    /**
        * @brief Sets the maximum operating altitude.
        *
        * Updates the maximum altitude at which the plane can
        * safely operate.
        *
        * @param max New maximum altitude.
    */
    void setMaxAltitude(const double &max);

    private:
        double max_altitude_;
    };

/**
 * @class Truck
 * @brief Represents a truck.
 *
 * Extends Vehicle by storing the loading capacity.
 * VolvoTruck derives from this class.
 */
class Truck: public Vehicle
{
    public:
    /**
        * @brief Default constructor.
        *
        * Creates a Truck object and initializes it with predefined
        * default values inherited from the Vehicle class, along with
        * a default loading capacity.
    */
    Truck();

    /**
        * @brief Parameterized constructor.
        *
        * Creates a Truck object with user-defined information.
        *
        * @param name Truck name.
        * @param color Truck color.
        * @param fuel_type Fuel type used by the truck.
        * @param vehicle_id Unique truck identifier.
        * @param vehicle_year Manufacturing year.
        * @param load_capacity Maximum loading capacity of the truck.
    */
    Truck(const std::string &name,
          const std::string &color,
          const std::string &fuel_type,
          const unsigned int vehicle_id,
          const unsigned int vehicle_year,
          const double load_capacity);

    /**
        * @brief Copy constructor.
        *
        * Creates a new Truck object as a copy of an existing
        * Truck object, including all inherited Vehicle data
        * and the loading capacity.
        *
        * @param obj Truck object to copy.
    */
    Truck(const Truck &obj);

    /**
        * @brief Destructor.
        *
        * Destroys the Truck object and performs any necessary
        * cleanup before the object is removed from memory.
    */
    ~Truck();

    /**
        * @brief Displays complete truck information.
        *
        * Overrides Vehicle::printVehicleInfo() to display the
        * common vehicle information inherited from the Vehicle
        * class, followed by the truck-specific information,
        * including its loading capacity.
    */
    void printVehicleInfo() const override;

    /**
        * @brief Returns the truck's loading capacity.
        *
        * Retrieves the maximum weight that the truck can safely
        * carry.
        *
        * @return Maximum loading capacity.
    */
    double getLoadingCapacity() const;

    /**
        * @brief Sets the truck's loading capacity.
        *
        * Updates the maximum load that the truck is capable of
        * carrying safely.
        *
        * @param capacity New loading capacity.
    */
    void setLoadingCapacity(const double &capacity);

    private:
    double load_capacity_;
};

/**
 * @class BMW
 * @brief Represents a BMW vehicle.
 *
 * Adds the BMW series (Series 3, Series 5, Series 7, etc.)
 * to the generic Car class.
 */
class BMW : public Car
    {
        public:
    /**
        * @brief Default constructor.
        *
        * Creates a BMW object and initializes it with predefined
        * default values inherited from the Car class, along with
        * a default BMW series.
    */
    BMW();

    /**
        * @brief Parameterized constructor.
        *
        * Creates a BMW object with user-defined information.
        *
        * @param name BMW vehicle name.
        * @param color BMW vehicle color.
        * @param fuel_type Fuel type used by the BMW.
        * @param vehicle_id Unique vehicle identifier.
        * @param vehicle_year Manufacturing year.
        * @param door_number Number of doors.
        * @param series BMW series designation (e.g., Series 3, Series 5, Series 7).
    */
    BMW(const std::string &name,
        const std::string &color,
        const std::string &fuel_type,
        const unsigned int vehicle_id,
        const unsigned int vehicle_year,
        const unsigned int door_number,
        const std::string &series);

    /**
        * @brief Copy constructor.
        *
        * Creates a new BMW object as a copy of an existing BMW,
        * including all inherited Car and Vehicle information
        * as well as the BMW series.
        *
        * @param obj BMW object to copy.
    */
    BMW(const BMW &obj);

    /**
        * @brief Destructor.
        *
        * Destroys the BMW object and performs any necessary
        * cleanup before the object is removed from memory.
    */
    ~BMW();

    /**
        * @brief Displays complete BMW information.
        *
        * Overrides Car::printVehicleInfo() to display all common
        * vehicle and car information, followed by the BMW-specific
        * series designation.
    */
    void printVehicleInfo() const override;

    /**
        * @brief Returns the BMW series.
        *
        * Retrieves the model series of the BMW vehicle,
        * such as Series 3, Series 5, or Series 7.
        *
        * @return Constant reference to the BMW series.
    */
    const std::string &getSeries() const;

    /**
        * @brief Sets the BMW series.
        *
        * Updates the BMW model series.
        *
        * @param series New BMW series.
    */
    void setSeries(const std::string &series);

    private:
    std::string series_;
};

/**
 * @class Toyota
 * @brief Represents a Toyota vehicle.
 *
 * Adds the Toyota model information
 * (Corolla, Camry, Supra, Hilux, etc.).
 */
class Toyota : public Car
{
    public:
    /**
        * @brief Default constructor.
        *
        * Creates a Toyota object and initializes it with predefined
        * default values inherited from the Car class, along with
        * a default Toyota model.
    */
    Toyota();

    /**
        * @brief Parameterized constructor.
        *
        * Creates a Toyota object with user-defined information.
        *
        * @param name Toyota vehicle name.
        * @param color Toyota vehicle color.
        * @param fuel_type Fuel type used by the Toyota.
        * @param vehicle_id Unique vehicle identifier.
        * @param vehicle_year Manufacturing year.
        * @param door_number Number of doors.
        * @param model Toyota model name (e.g., Corolla, Camry, Supra, Hilux).
    */
    Toyota(const std::string &name,
           const std::string &color,
           const std::string &fuel_type,
           const unsigned int vehicle_id,
           const unsigned int vehicle_year,
           const unsigned int door_number,
           const std::string &model);

    /**
        * @brief Copy constructor.
        *
        * Creates a new Toyota object as a copy of an existing Toyota,
        * including all inherited Car and Vehicle information along
        * with the Toyota model.
        *
        * @param obj Toyota object to copy.
    */
    Toyota(const Toyota &obj);

    /**
        * @brief Destructor.
        *
        * Destroys the Toyota object and performs any necessary
        * cleanup before the object is removed from memory.
    */
    ~Toyota();

    /**
        * @brief Displays complete Toyota information.
        *
        * Overrides Car::printVehicleInfo() to display all common
        * vehicle and car information, followed by the Toyota-specific
        * model.
    */
    void printVehicleInfo() const override;

    /**
        * @brief Returns the Toyota model.
        *
        * Retrieves the model name of the Toyota vehicle,
        * such as Corolla, Camry, Supra, Hilux, Prius, or RAV4.
        *
        * @return Constant reference to the Toyota model.
    */
    const std::string &getModel() const;

    /**
        * @brief Sets the Toyota model.
        *
        * Updates the Toyota model name.
        *
        * @param model New Toyota model.
    */
    void setModel(const std::string &model);

    private:
    std::string model_;
};

/**
 * @class Boeing
 * @brief Represents a Boeing aircraft.
 *
 * Extends Plane by storing passenger capacity.
 */
class Boeing : public Plane
{
    public:
    /**
        * @brief Default constructor.
        *
        * Creates a Boeing aircraft object and initializes it with
        * predefined values inherited from the Plane class, along with
        * default passenger capacity.
    */
    Boeing();

    /**
        * @brief Parameterized constructor.
        *
        * Creates a Boeing aircraft with custom information.
        *
        * @param name Aircraft name.
        * @param color Aircraft color.
        * @param fuel_type Fuel type used by the aircraft.
        * @param vehicle_id Unique aircraft identifier.
        * @param vehicle_year Manufacturing year.
        * @param max_altitude Maximum operating altitude.
        * @param passenger_capacity Maximum number of passengers the aircraft can carry.
    */
    Boeing(const std::string &name,
            const std::string &color,
            const std::string &fuel_type,
            const unsigned int vehicle_id,
            const unsigned int vehicle_year,
            double max_altitude,
            unsigned int passenger_capacity);

    /**
        * @brief Copy constructor.
        *
        * Creates a new Boeing object as a copy of an existing Boeing
        * aircraft, including all inherited Plane and Vehicle data,
        * along with its passenger capacity.
        *
        * @param obj Boeing object to copy.
    */
    Boeing(const Boeing &obj);

    /**
        * @brief Destructor.
        *
        * Destroys the Boeing object and performs any necessary
        * cleanup before the object is removed from memory.
    */
    ~Boeing();

    /**
        * @brief Displays complete Boeing aircraft information.
        *
        * Overrides Plane::printVehicleInfo() to display the common
        * vehicle and plane information, followed by the Boeing-specific
        * passenger capacity.
    */
    void printVehicleInfo() const override;

    /**
        * @brief Returns the passenger capacity.
        *
        * Retrieves the maximum number of passengers that the
        * Boeing aircraft can accommodate.
        *
        * @return Maximum passenger capacity.
    */
    unsigned int getPassengerCapacity() const;

    /**
        * @brief Sets the passenger capacity.
        *
        * Updates the maximum number of passengers that the
        * Boeing aircraft can carry.
        *
        * @param capacity New passenger capacity.
    */
    void setPassengerCapacity(const unsigned int &capacity);
    
    private:
    unsigned int passenger_capacity_;
};

/**
 * @class VolvoTruck
 * @brief Represents a Volvo truck.
 *
 * Adds refrigeration support information,
 * indicating whether the truck is refrigerated.
 */
class VolvoTruck : public Truck
{
    public:
    /**
        * @brief Default constructor.
        *
        * Creates a VolvoTruck object and initializes it with
        * predefined values inherited from the Truck class, along
        * with a default refrigeration status.
    */
    VolvoTruck();

    /**
        * @brief Parameterized constructor.
        *
        * Creates a VolvoTruck object with custom information.
        *
        * @param name Truck name.
        * @param color Truck color.
        * @param fuel_type Fuel type used by the truck.
        * @param vehicle_id Unique truck identifier.
        * @param vehicle_year Manufacturing year.
        * @param load_capacity Maximum loading capacity.
        * @param refrigerated Indicates whether the truck is equipped
        *        with a refrigeration system.
    */
    VolvoTruck(const std::string &name,
               const std::string &color,
               const std::string &fuel_type,
               const unsigned int vehicle_id,
               const unsigned int vehicle_year,
               double load_capacity,
               bool refrigerated);

    /**
        * @brief Copy constructor.
        *
        * Creates a new VolvoTruck object as a copy of an existing
        * VolvoTruck, including all inherited Truck and Vehicle data,
        * as well as the refrigeration status.
        *
        * @param obj VolvoTruck object to copy.
    */
    VolvoTruck(const VolvoTruck &obj);

    /**
        * @brief Destructor.
        *
        * Destroys the VolvoTruck object and performs any necessary
        * cleanup before the object is removed from memory.
    */
    ~VolvoTruck();

    /**
        * @brief Displays complete Volvo truck information.
        *
        * Overrides Truck::printVehicleInfo() to display the common
        * vehicle and truck information, followed by the Volvo-specific
        * refrigeration status.
    */
    void printVehicleInfo() const override;

    /**
        * @brief Returns the refrigeration status.
        *
        * Indicates whether the truck is equipped with a refrigeration
        * system for transporting temperature-sensitive goods.
        *
        * @return true if the truck is refrigerated; otherwise false.
    */
    bool getRefrigeratedStatus() const;

    /**
        * @brief Sets the refrigeration status.
        *
        * Enables or disables the refrigeration feature of the truck.
        *
        * @param state Refrigeration status.
        *              - true  : Refrigerated truck.
        *              - false : Standard truck.
    */
    void setRefrigeratedStatus(const bool state);

    private:
    bool refrigerated_; 
};

/**
 * @class HondaMotorcycle
 * @brief Represents a Honda motorcycle.
 *
 * Adds Anti-lock Braking System (ABS) support.
 */
class HondaMotorcycle : public Motorcycle
{
    public:
    /**
        * @brief Constructs a HondaMotorcycle object with default values.
        *
        * Initializes the motorcycle with predefined Honda-specific
        * attributes and enables or disables the ABS system with
        * a default configuration.
    */
    HondaMotorcycle();

    /**
        * @brief Constructs a HondaMotorcycle object with user-defined values.
        *
        * @param name The motorcycle name.
        * @param color The motorcycle color.
        * @param fuel_type The fuel type used by the motorcycle.
        * @param vehicle_id The unique vehicle identifier.
        * @param vehicle_year The manufacturing year.
        * @param wheel_number The number of wheels.
        * @param abs_system Indicates whether the motorcycle is equipped
        *        with an Anti-lock Braking System (ABS).
    */
    HondaMotorcycle(const std::string &name,
                    const std::string &color,
                    const std::string &fuel_type,
                    const unsigned int vehicle_id,
                    const unsigned int vehicle_year,
                    const unsigned int wheel_number,
                    const bool abs_system);

    /**
        * @brief Copy constructor.
        *
        * Creates a new HondaMotorcycle object as a copy of another
        * HondaMotorcycle instance.
        *
        * @param obj The HondaMotorcycle object to copy.
    */
    HondaMotorcycle(const HondaMotorcycle &obj);

    /**
        * @brief Destroys the HondaMotorcycle object.
    */
    ~HondaMotorcycle();

    /**
        * @brief Displays all Honda motorcycle information.
        *
        * Overrides the Motorcycle::printVehicleInfo() function to print
        * both the inherited vehicle information and the Honda-specific
        * ABS system status.
    */
    void printVehicleInfo() const override;

    /**
        * @brief Gets the ABS system status.
        *
        * @return true if the motorcycle has an Anti-lock Braking System
        *         enabled, otherwise false.
    */
    bool getABSSystemState() const;

    /**
        * @brief Sets the ABS system status.
        *
        * @param state The new ABS system state.
        *              - true : ABS enabled.
        *              - false: ABS disabled.
    */
    void setABSSystemState(const bool &state);

    private:
    bool abs_system_;
};

/**
 * @class MountainBike
 * @brief Represents a mountain bicycle.
 *
 * Adds the mountain bike category
 * (Cross-Country, Trail, Enduro, Downhill, etc.).
 */
class MountainBike : public Bicycle
{
    public:
    /**
        * @brief Constructs a MountainBike object with default values.
        *
        * Initializes the mountain bike with predefined information,
        * including the inherited Bicycle and Vehicle attributes,
        * along with a default bike type.
    */
    MountainBike();

    /**
        * @brief Constructs a MountainBike object with custom values.
        *
        * Initializes all inherited Vehicle and Bicycle attributes,
        * as well as the specific mountain bike type.
        *
        * @param name The name of the mountain bike.
        * @param color The color of the mountain bike.
        * @param fuel_type The fuel type (typically "Human Power").
        * @param vehicle_id The unique vehicle identifier.
        * @param vehicle_year The manufacturing year.
        * @param has_basket Indicates whether the bike has a basket.
        * @param bike_type The mountain bike category (e.g., Cross Country,
        *                  Trail, Enduro, Downhill, All-Mountain, Dirt Jump).
    */
    MountainBike(const std::string &name,
                 const std::string &color,
                 const std::string &fuel_type,
                 const unsigned int vehicle_id,
                 const unsigned int vehicle_year,
                 const bool has_basket,
                 const std::string &bike_type);

    /**
        * @brief Copy constructor.
        *
        * Creates a new MountainBike object as a copy of another.
        *
        * @param obj The MountainBike object to copy.
    */
    MountainBike(const MountainBike &obj);

    /**
        * @brief Destroys the MountainBike object.
    */
    ~MountainBike();

    /**
        * @brief Prints complete mountain bike information.
        *
        * Displays all inherited Vehicle and Bicycle information,
        * followed by the mountain bike type.
    */
    void printVehicleInfo() const override;

    /**
        * @brief Returns the mountain bike type.
        *
        * @return Constant reference to the bike type string.
    */
    const std::string &getBikeType() const;

    /**
        * @brief Sets the mountain bike type.
        *
        * @param bike_type The new bike type.
    */
    void setBikeType(const std::string &bike_type);

    private:
    std::string bike_type_;
};


#endif /* _VEHICLE_HPP_ */