cmake_minimum_required(VERSION 3.16)

project(Session4Task_ElectronicsShop VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)


qt_add_executable(appSession4Task_ElectronicsShop
    main.cpp
)

qt_add_qml_module(appSession4Task_ElectronicsShop
    URI Session4Task_ElectronicsShop
    QML_FILES
        Main.qml
        HomePage.qml
        components/HeaderBar.qml
    RESOURCES
        imags/electronics_bg.png
        imags/logo.png
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
