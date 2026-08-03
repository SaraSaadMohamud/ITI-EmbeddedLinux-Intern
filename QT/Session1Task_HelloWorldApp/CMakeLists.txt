cmake_minimum_required(VERSION 3.16)

project(Session1Task_HelloWorldApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(appSession1Task_HelloWorldApp
    main.cpp
)

qt_add_qml_module(appSession1Task_HelloWorldApp
    URI Session1Task_HelloWorldApp
    QML_FILES
        Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appSession1Task_HelloWorldApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appSession1Task_HelloWorldApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSession1Task_HelloWorldApp
    PRIVATE Qt6::Quick
)

install(TARGETS appSession1Task_HelloWorldApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
