#  Vehicle Management System

A C++ Object-Oriented Programming project that models a real-world vehicle fleet using multi-level inheritance and runtime polymorphism. The system defines a generic `Vehicle` base class and builds out five vehicle categories — cars, bicycles, motorcycles, planes, and trucks — each further specialized into concrete brand/model classes such as `BMW`, `Toyota`, `Boeing`, `VolvoTruck`, `HondaMotorcycle`, and `MountainBike`.

The project is designed as a hands-on demonstration of core C++ OOP principles: encapsulation, inheritance, constructor/destructor chaining, function overriding, and dynamic binding through base-class pointers.

---

##  Features

-  Three-level class hierarchy (`Vehicle` → category → brand)
-  Default, parameterized, and copy constructors for every class
-  Encapsulated data members with public getters/setters
-  Constructor and destructor chaining across inheritance levels
-  Overridden `printVehicleInfo()` that reuses the parent implementation
-  Runtime polymorphism via virtual functions and `Vehicle*` pointers
-  Fully documented header file (Doxygen-style comments)

---

##  Object-Oriented Concepts Demonstrated

| Concept                     | Where It's Applied                                                            |
|------------------------------|--------------------------------------------------------------------------------|
| Encapsulation                 | `protected`/`private` data members with controlled access via getters/setters |
| Inheritance                   | `Car`, `Bicycle`, `Motorcycle`, `Plane`, `Truck` derive from `Vehicle`         |
| Multi-Level Inheritance        | `BMW`/`Toyota` → `Car` → `Vehicle`, `Boeing` → `Plane` → `Vehicle`, etc.       |
| Constructor Overloading        | Default and parameterized constructors in every class                        |
| Copy Constructors              | Deep copy logic implemented at every inheritance level                       |
| Destructor Chaining            | Virtual destructor in `Vehicle` ensures correct cleanup order                |
| Virtual Functions              | `printVehicleInfo()` declared `virtual` in `Vehicle`                          |
| Function Overriding            | Each derived class overrides `printVehicleInfo()`                             |
| Runtime Polymorphism           | Behavior resolved dynamically through `Vehicle` base-class pointers          |
| Function Reuse                 | Derived classes call `Base::printVehicleInfo()` to reuse parent logic         |
| Access Specifiers               | Careful use of `public`, `protected`, and `private`                          |

---

##  Project Structure

```
Vehicle (Base Class)
├── Car
│   ├── BMW
│   └── Toyota
│
├── Bicycle
│   └── MountainBike
│
├── Motorcycle
│   └── HondaMotorcycle
│
├── Plane
│   └── Boeing
│
└── Truck
    └── VolvoTruck
```

---

## Class Descriptions

### `Vehicle` (Base Class)
Stores the attributes common to all vehicles: `name`, `color`, `fuel_type`, `vehicle_id`, and `vehicle_year`. Declares a virtual `printVehicleInfo()` method and a virtual destructor to enable safe polymorphic use and cleanup.

### `Car`
Extends `Vehicle` with a `door_number` attribute. Serves as the parent of `BMW` and `Toyota`.

### `BMW`
Extends `Car` with a `series` attribute (e.g., "7 Series").

### `Toyota`
Extends `Car` with a `model` attribute (e.g., "Corolla").

### `Bicycle`
Extends `Vehicle` with a `has_basket` boolean flag. Parent of `MountainBike`.

### `MountainBike`
Extends `Bicycle` with a `bike_type` attribute (e.g., "Mountain Bike").

### `Motorcycle`
Extends `Vehicle` with a `wheel_number` attribute. Parent of `HondaMotorcycle`.

### `HondaMotorcycle`
Extends `Motorcycle` with an `abs_system` boolean flag indicating whether ABS is available.

### `Plane`
Extends `Vehicle` with a `max_altitude` attribute. Parent of `Boeing`.

### `Boeing`
Extends `Plane` with a `passenger_capacity` attribute.

### `Truck`
Extends `Vehicle` with a `load_capacity` attribute. Parent of `VolvoTruck`.

### `VolvoTruck`
Extends `Truck` with a `refrigerated` boolean flag indicating refrigeration support.

---

## 🛠️ Technologies Used

- **C++** (C++11 or later)
- **Object-Oriented Programming** (inheritance, polymorphism, encapsulation)
- **STL** — `std::string`, `iostream`

---

##  Project Folder Structure

```
VehicleManagementSystem/
├── include/
│   └── vehicle.hh          # Class declarations and Doxygen documentation
├── src/
│   └── vehicle.cc           # Class implementations
├── main.cc                  # Entry point / demo driver
├── README.md
└── LICENSE
```

---

##  Build Instructions

Compile all source files with `g++`:

```bash
g++ *.cc -o VehicleSystem
```

Run the compiled program:

```bash
./VehicleSystem
```

>  Requires a C++11-compatible (or newer) compiler.

---

## 🖥️ Example Output

```
Vehicle Parameteriez Constructor Called!!

Car Parameteriez Constructor Called!!

BMW Parameteriez Constructor Called!!

=================== Vechicle Information ========================

Name        : BMW
Color       : Black
Fuel Type   : Petrol
ID          : 1234
Year        : 2026
Door Number : 4
Series: 7 Series

Plane Parameteriez Constructor Called!!

Boeing Parameteriez Constructor Called!!

=================== Vechicle Information ========================

Name        : Boeing
Color       : White
Fuel Type   : Petrol
ID          : 1505
Year        : 2025
Max Altitude: 2500
Passenger Capacity: 250

BMW Default Destructor Called
Car Default Destructor Called
Vehicle Default Destructor Called
Car Default Destructor Called
Plane Default Destructor Called
Vehicle Default Destructor Called
```

> Output order reflects real constructor/destructor chaining: base classes construct first and destruct last.

---

##  Learning Objectives

This project is a practical reference for learning and reinforcing:

- How to design a clean, extensible class hierarchy using inheritance
- The difference between shallow and deep copying with copy constructors
- Why destructors should be declared `virtual` in polymorphic base classes
- How `override` improves safety when overriding virtual functions
- How to reuse base-class logic instead of duplicating code (`Base::method()`)
- How dynamic binding works when calling virtual functions through base-class pointers
- Good encapsulation practices using access specifiers and getter/setter design

---

##  Future Improvements

-  Replace raw ownership patterns with smart pointers (`std::unique_ptr`, `std::shared_ptr`)
-  Add file handling to persist and reload vehicle data
-  Add exception handling for invalid input and edge cases
-  Introduce templates for generic vehicle collections
-  Implement operator overloading (`==`, `<<`, etc.)
-  Build a searchable vehicle database
-  Add an interactive menu-driven console interface

---

## 👤 Author

**Name:**  Sara Saad
**LinkedIn:** https://www.linkedin.com/in/sara-saad-b7565a2b9/

**GitHub:** https://github.com/SaraSaadMohamud

---
