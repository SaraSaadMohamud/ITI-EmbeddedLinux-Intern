cmake_minimum_required(VERSION 3.16)

project(Session4Task_ElectronicsShop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick LinguistTools)

qt_standard_project_setup(
    REQUIRES 6.10
    I18N_SOURCE_LANGUAGE en
    I18N_TRANSLATED_LANGUAGES ar fr de
)


qt_add_executable(appSession4Task_ElectronicsShop
    main.cpp
    LanguageManager.cpp
    LanguageManager.h
)

qt_add_qml_module(appSession4Task_ElectronicsShop
    URI Session4Task_ElectronicsShop
    QML_FILES
        Main.qml
        HomePage.qml
        ProductPage.qml
        SearchPage.qml
        CategoriesPage.qml
        CartPage.qml
        components/HeaderBar.qml
        components/ProductCard.qml
        model/CartModel.qml
        model/ProductModel.qml

    RESOURCES
        imags/electronics_bg.png
        imags/logo.png
        imags/2wd_robot.png
        imags/4wd_robot.png
        imags/arduino_mega.png
        imags/arduino_nano.png
        imags/arduino_robot_car.png
        imags/atmega328p.png
        imags/bmp280.png
        imags/capacitor_kit.png
        imags/component_tester.png
        imags/desoldering_pump.png
        imags/dht22.png
        imags/diode_kit.png
        imags/esp32.png
        imags/esp8266.png
        imags/gear_motor.png
        imags/hcsr04.png
        imags/hcsr501.png
        imags/ir_sensor.png
        imags/l298n.png
        imags/ldr.png
        imags/led_kit.png
        imags/logic_analyzer.png
        imags/mg996r.png
        imags/mosfet_kit.png
        imags/mpu6050.png
        imags/mpu9250.png
        imags/mq2.png
        imags/multimeter.png
        imags/nema17.png
        imags/oscilloscope.png
        imags/pic16f877a.png
        imags/pico_w.png
        imags/potentiometer_kit.png
        imags/push_button_kit.png
        imags/relay_module.png
        imags/resistor_kit.png
        imags/robot_arm.png
        imags/screwdriver_set.png
        imags/sg90.png
        imags/soldering_iron.png
        imags/soldering_station.png
        imags/stm32f103.png
        imags/stm32f401.png
        imags/tb6612fng.png
        imags/teensy41.png
        imags/transistor_kit.png
        imags/vl53l0x.png
        imags/voltage_regulator.png
        imags/wire_stripper.png
        imags/products.png
        LanguageManager.h
        LanguageManager.cpp
)

qt_add_translations(appSession4Task_ElectronicsShop
    TS_FILE_BASE Session4_Task_ElectronicsShop
    TS_FILE_DIR i18n

    RESOURCE_PREFIX
        /qt/qml/Session4Task_ElectronicsShop/i18n
)

set_target_properties(appSession4Task_ElectronicsShop PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appSession4Task_ElectronicsShop
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSession4Task_ElectronicsShop
    PRIVATE Qt6::Quick
)

install(TARGETS appSession4Task_ElectronicsShop
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
