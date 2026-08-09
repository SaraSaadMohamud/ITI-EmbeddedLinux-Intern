import QtQuick

ListModel{

    // =========================================
    // Filtered Products
    // =========================================

    function getProductsByCategory(categoryName) {
        var filteredProducts = []
        for (var i = 0; i < count; i++) {
            var product = get(i)
            if (product.productCategory === categoryName) {
                filteredProducts.push(product)
            }
        }

        return filteredProducts
    }

    // =========================================
    // Search Products
    // =========================================
    function searchProducts(searchText) {
        var results = []

        if (searchText.trim() === "") {
            return results
        }

        var query = searchText.toLowerCase().trim()

        for (var i = 0; i < count; i++) {

            var product = get(i)

            if (
                product.productName.toLowerCase().includes(query) ||
                product.productCategory.toLowerCase().includes(query) ||
                product.productBrand.toLowerCase().includes(query) ||
                product.productVersion.toLowerCase().includes(query) ||
                product.productInterface.toLowerCase().includes(query)
            ) {
                results.push(product)
            }
        }

        return results
    }

    // =========================================================
    // Development Boards
    // =========================================================
    ListElement{
        productName: "ESP32 Development Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/esp32.png"
        productPrice: "$12.99"
        productCategory: "Development Boards"
        productAvailable: true
        productBrand: "Espressif"
        productVersion: "ESP32-WROOM"
        productColor: "Black"
        productVoltage: "3.3V"
        productInterface: "WiFi / Bluetooth"
    }

    ListElement {
        productName: "STM32F401 Black Pill"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/stm32f401.png"
        productPrice: "$9.99"
        productCategory: "Development Boards"
        productAvailable: true
        productBrand: "STMicroelectronics"
        productVersion: "STM32F401CCU6"
        productColor: "Black"
        productVoltage: "3.3V"
        productInterface: "USB"
    }

    ListElement {
        productName: "STM32F103 Blue Pill"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/stm32f103.png"
        productPrice: "$6.99"
        productCategory: "Development Boards"
        productAvailable: true
        productBrand: "STMicroelectronics"
        productVersion: "STM32F103C8T6"
        productColor: "Blue"
        productVoltage: "3.3V"
        productInterface: "Micro USB"
    }

    ListElement {
        productName: "Raspberry Pi Pico W"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/pico_w.png"
        productPrice: "$8.99"
        productCategory: "Development Boards"
        productAvailable: true
        productBrand: "Raspberry Pi"
        productVersion: "Pico W"
        productColor: "Green"
        productVoltage: "3.3V"
        productInterface: "WiFi / USB"
    }

    ListElement {
        productName: "Arduino Nano"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/arduino_nano.png"
        productPrice: "$19.99"
        productCategory: "Development Boards"
        productAvailable: true
        productBrand: "Arduino"
        productVersion: "Nano V3"
        productColor: "Blue"
        productVoltage: "5V"
        productInterface: "Mini USB"
    }

    ListElement {
        productName: "Arduino Mega 2560"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/arduino_mega.png"
        productPrice: "$29.99"
        productCategory: "Development Boards"
        productAvailable: true
        productBrand: "Arduino"
        productVersion: "Mega 2560"
        productColor: "Blue"
        productVoltage: "5V"
        productInterface: "USB"
    }

    ListElement {
        productName: "ATmega328P Development Board"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/atmega328p.png"
        productPrice: "$7.49"
        productCategory: "Development Boards"
        productAvailable: true
        productBrand: "Microchip"
        productVersion: "ATmega328P"
        productColor: "Blue"
        productVoltage: "5V"
        productInterface: "USB"
    }

    ListElement {
        productName: "PIC16F877A Development Board"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/pic16f877a.png"
        productPrice: "$15.99"
        productCategory: "Development Boards"
        productAvailable: true
        productBrand: "Microchip"
        productVersion: "PIC16F877A"
        productColor: "Blue"
        productVoltage: "5V"
        productInterface: "UART"
    }

    ListElement {
        productName: "ESP8266 NodeMCU"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/esp8266.png"
        productPrice: "$7.99"
        productCategory: "Development Boards"
        productAvailable: true
        productBrand: "Espressif"
        productVersion: "ESP-12E"
        productColor: "Blue"
        productVoltage: "3.3V"
        productInterface: "WiFi / Micro USB"
    }

    ListElement {
        productName: "Teensy 4.1"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/teensy41.png"
        productPrice: "$31.99"
        productCategory: "Development Boards"
        productAvailable: false
        productBrand: "PJRC"
        productVersion: "4.1"
        productColor: "Black"
        productVoltage: "3.3V"
        productInterface: "USB"
    }


    // =========================================================
    // ROBOTICS
    // =========================================================


    ListElement {
        productName: "2WD Robot Car Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/2wd_robot.png"
        productPrice: "$24.99"
        productCategory: "Robotics"
        productAvailable: true
        productBrand: "Generic"
        productVersion: "2WD"
        productColor: "Black"
        productVoltage: "6V"
        productInterface: "Motor Driver"
    }

    ListElement {
        productName: "4WD Smart Robot Car"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/4wd_robot.png"
        productPrice: "$39.99"
        productCategory: "Robotics"
        productAvailable: true
        productBrand: "Generic"
        productVersion: "4WD"
        productColor: "Black"
        productVoltage: "12V"
        productInterface: "UART"
    }

    ListElement {
        productName: "SG90 Servo Motor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/sg90.png"
        productPrice: "$3.49"
        productCategory: "Robotics"
        productAvailable: true
        productBrand: "Tower Pro"
        productVersion: "SG90"
        productColor: "Blue"
        productVoltage: "5V"
        productInterface: "PWM"
    }

    ListElement {
        productName: "MG996R Servo Motor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/mg996r.png"
        productPrice: "$8.99"
        productCategory: "Robotics"
        productAvailable: true
        productBrand: "Tower Pro"
        productVersion: "MG996R"
        productColor: "Metal / Red"
        productVoltage: "6V"
        productInterface: "PWM"
    }

    ListElement {
        productName: "NEMA 17 Stepper Motor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/nema17.png"
        productPrice: "$14.99"
        productCategory: "Robotics"
        productAvailable: true
        productBrand: "StepperOnline"
        productVersion: "NEMA 17"
        productColor: "Black"
        productVoltage: "12V"
        productInterface: "4-Wire"
    }

    ListElement {
        productName: "Micro Metal Gear Motor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/gear_motor.png"
        productPrice: "$5.99"
        productCategory: "Robotics"
        productAvailable: true
        productBrand: "Pololu"
        productVersion: "25GA370"
        productColor: "Metal"
        productVoltage: "12V"
        productInterface: "2-Wire"
    }

    ListElement {
        productName: "TB6612FNG Motor Driver"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/tb6612fng.png"
        productPrice: "$6.49"
        productCategory: "Robotics"
        productAvailable: true
        productBrand: "Toshiba"
        productVersion: "TB6612FNG"
        productColor: "Green"
        productVoltage: "5V"
        productInterface: "PWM"
    }

    ListElement {
        productName: "L298N Motor Driver"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/l298n.png"
        productPrice: "$4.99"
        productCategory: "Robotics"
        productAvailable: true
        productBrand: "ST"
        productVersion: "L298N"
        productColor: "Red"
        productVoltage: "5V"
        productInterface: "GPIO"
    }


    ListElement {
        productName: "Robot Arm Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/robot_arm.png"
        productPrice: "$49.99"
        productCategory: "Robotics"
        productAvailable: true
        productBrand: "Generic"
        productVersion: "4DOF"
        productColor: "Black"
        productVoltage: "6V"
        productInterface: "PWM"
    }


    ListElement {
        productName: "Arduino Robotic car"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/arduino_robot_car.png"
        productPrice: "$34.99"
        productCategory: "Robotics"
        productAvailable: false
        productBrand: "Generic"
        productVersion: "V2"
        productColor: "Blue"
        productVoltage: "7.4V"
        productInterface: "Bluetooth"
    }

    // =========================================================
    // SENSORS
    // =========================================================

    ListElement {
        productName: "HC-SR04 Ultrasonic Sensor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/hcsr04.png"
        productPrice: "$2.99"
        productCategory: "Sensors"
        productAvailable: true
        productBrand: "Generic"
        productVersion: "HC-SR04"
        productColor: "Blue"
        productVoltage: "5V"
        productInterface: "GPIO"
    }

    ListElement {
        productName: "MPU9250 IMU Sensor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/mpu9250.png"
        productPrice: "$12.49"
        productCategory: "Sensors"
        productAvailable: true
        productBrand: "TDK InvenSense"
        productVersion: "MPU9250"
        productColor: "Green"
        productVoltage: "3.3V"
        productInterface: "I2C / SPI"
    }

    ListElement {
        productName: "MPU6050 Gyroscope"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/mpu6050.png"
        productPrice: "$4.99"
        productCategory: "Sensors"
        productAvailable: true
        productBrand: "InvenSense"
        productVersion: "MPU6050"
        productColor: "Green"
        productVoltage: "3.3V"
        productInterface: "I2C"
    }

    ListElement {
        productName: "DHT22 Temperature Sensor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/dht22.png"
        productPrice: "$5.49"
        productCategory: "Sensors"
        productAvailable: true
        productBrand: "Aosong"
        productVersion: "DHT22"
        productColor: "White"
        productVoltage: "3.3V"
        productInterface: "Digital"
    }

    ListElement {
        productName: "HC-SR501 PIR Sensor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/hcsr501.png"
        productPrice: "$3.49"
        productCategory: "Sensors"
        productAvailable: true
        productBrand: "Generic"
        productVersion: "HC-SR501"
        productColor: "White"
        productVoltage: "5V"
        productInterface: "Digital"
    }

    ListElement {
        productName: "BMP280 Pressure Sensor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/bmp280.png"
        productPrice: "$3.99"
        productCategory: "Sensors"
        productAvailable: true
        productBrand: "Bosch"
        productVersion: "BMP280"
        productColor: "Blue"
        productVoltage: "3.3V"
        productInterface: "I2C / SPI"
    }

    ListElement {
        productName: "LDR Light Sensor Module"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/ldr.png"
        productPrice: "$1.99"
        productCategory: "Sensors"
        productAvailable: true
        productBrand: "Generic"
        productVersion: "LDR"
        productColor: "Blue"
        productVoltage: "5V"
        productInterface: "Analog"
    }

    ListElement {
        productName: "MQ-2 Gas Sensor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/mq2.png"
        productPrice: "$3.99"
        productCategory: "Sensors"
        productAvailable: true
        productBrand: "Hanwei"
        productVersion: "MQ-2"
        productColor: "Blue"
        productVoltage: "5V"
        productInterface: "Analog"
    }

    ListElement {
        productName: "IR Obstacle Sensor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/ir_sensor.png"
        productPrice: "$2.49"
        productCategory: "Sensors"
        productAvailable: true
        productBrand: "Generic"
        productVersion: "IR"
        productColor: "Black"
        productVoltage: "5V"
        productInterface: "Digital"
    }

    ListElement {
        productName: "VL53L0X ToF Sensor"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/vl53l0x.png"
        productPrice: "$9.99"
        productCategory: "Sensors"
        productAvailable: false
        productBrand: "STMicroelectronics"
        productVersion: "VL53L0X"
        productColor: "Green"
        productVoltage: "2.8V"
        productInterface: "I2C"
    }


    // =========================================================
    // ELECTRONIC TOOLS
    // =========================================================

    ListElement {
        productName: "Digital Multimeter"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/multimeter.png"
        productPrice: "$19.99"
        productCategory: "Electronic Tools"
        productAvailable: true
        productBrand: "UNI-T"
        productVersion: "UT33D+"
        productColor: "Yellow"
        productVoltage: "600V"
        productInterface: "Test Leads"
    }

    ListElement {
        productName: "Soldering Iron 60W"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/soldering_iron.png"
        productPrice: "$14.99"
        productCategory: "Electronic Tools"
        productAvailable: true
        productBrand: "YIHUA"
        productVersion: "60W"
        productColor: "Black"
        productVoltage: "220V"
        productInterface: "Power"
    }

    ListElement {
        productName: "Soldering Station"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/soldering_station.png"
        productPrice: "$39.99"
        productCategory: "Electronic Tools"
        productAvailable: true
        productBrand: "YIHUA"
        productVersion: "936"
        productColor: "Black"
        productVoltage: "220V"
        productInterface: "AC Power"
    }

    ListElement {
        productName: "Digital Oscilloscope"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/oscilloscope.png"
        productPrice: "$149.99"
        productCategory: "Electronic Tools"
        productAvailable: true
        productBrand: "OWON"
        productVersion: "XDS1022"
        productColor: "Black"
        productVoltage: "100-240V"
        productInterface: "USB / BNC"
    }

    ListElement {
        productName: "Logic Analyzer"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/logic_analyzer.png"
        productPrice: "$11.99"
        productCategory: "Electronic Tools"
        productAvailable: true
        productBrand: "Kingst"
        productVersion: "8 Channel"
        productColor: "Black"
        productVoltage: "5V"
        productInterface: "USB"
    }

    ListElement {
        productName: "Wire Stripper Tool"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/wire_stripper.png"
        productPrice: "$7.99"
        productCategory: "Electronic Tools"
        productAvailable: true
        productBrand: "Jakemy"
        productVersion: "JM-8172"
        productColor: "Red / Black"
        productVoltage: "N/A"
        productInterface: "Manual"
    }

    ListElement {
        productName: "Precision Screwdriver Set"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/screwdriver_set.png"
        productPrice: "$12.99"
        productCategory: "Electronic Tools"
        productAvailable: true
        productBrand: "Jakemy"
        productVersion: "JM-8139"
        productColor: "Black"
        productVoltage: "N/A"
        productInterface: "Manual"
    }

    ListElement {
        productName: "Desoldering Pump"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/desoldering_pump.png"
        productPrice: "$4.49"
        productCategory: "Electronic Tools"
        productAvailable: true
        productBrand: "Generic"
        productVersion: "Professional"
        productColor: "Blue"
        productVoltage: "N/A"
        productInterface: "Manual"
    }

    ListElement {
        productName: "Digital Component Tester"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/component_tester.png"
        productPrice: "$16.99"
        productCategory: "Electronic Tools"
        productAvailable: true
        productBrand: "FNIRSI"
        productVersion: "LCR-T7"
        productColor: "Black"
        productVoltage: "9V"
        productInterface: "USB"
    }

    // =========================================================
    // ELECTRONIC Components
    // =========================================================
    ListElement {
        productName: "Resistor Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/resistor_kit.png"
        productPrice: "$9.99"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "Yageo"
        productVersion: "1/4W"
        productColor: "Mixed"
        productVoltage: "250V"
        productInterface: "Through-Hole"
    }

    ListElement {
        productName: "Capacitor Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/capacitor_kit.png"
        productPrice: "$12.99"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "KEMET"
        productVersion: "Standard"
        productColor: "Mixed"
        productVoltage: "50V"
        productInterface: "Through-Hole"
    }

    ListElement {
        productName: "Diode Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/diode_kit.png"
        productPrice: "$8.49"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "Vishay"
        productVersion: "General Purpose"
        productColor: "Black"
        productVoltage: "1000V"
        productInterface: "Through-Hole"
    }

    ListElement {
        productName: "LED Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/led_kit.png"
        productPrice: "$7.99"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "Kingbright"
        productVersion: "5mm"
        productColor: "Mixed"
        productVoltage: "3.3V"
        productInterface: "Through-Hole"
    }

    ListElement {
        productName: "Transistor Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/transistor_kit.png"
        productPrice: "$10.99"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "ON Semiconductor"
        productVersion: "NPN/PNP"
        productColor: "Black"
        productVoltage: "60V"
        productInterface: "Through-Hole"
    }

    ListElement {
        productName: "MOSFET Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/mosfet_kit.png"
        productPrice: "$14.99"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "Infineon"
        productVersion: "Power MOSFET"
        productColor: "Black"
        productVoltage: "100V"
        productInterface: "Through-Hole"
    }

    ListElement {
        productName: "Voltage Regulator"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/voltage_regulator.png"
        productPrice: "$6.99"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "Texas Instruments"
        productVersion: "LM7805"
        productColor: "Black"
        productVoltage: "35V"
        productInterface: "TO-220"
    }

    ListElement {
        productName: "Relay Module"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/relay_module.png"
        productPrice: "$5.99"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "Songle"
        productVersion: "1-Channel"
        productColor: "Blue"
        productVoltage: "5V"
        productInterface: "Digital"
    }

    ListElement {
        productName: "Potentiometer Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/potentiometer_kit.png"
        productPrice: "$8.99"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "Bourns"
        productVersion: "10K Ohm"
        productColor: "Mixed"
        productVoltage: "50V"
        productInterface: "Through-Hole"
    }

    ListElement {
        productName: "Push Button Kit"
        productImage: "qrc:/qt/qml/Session4Task_ElectronicsShop/imags/push_button_kit.png"
        productPrice: "$6.49"
        productCategory: "Electronic Components"
        productAvailable: true

        productBrand: "Omron"
        productVersion: "12mm"
        productColor: "Mixed"
        productVoltage: "12V"
        productInterface: "Through-Hole"
    }
}


