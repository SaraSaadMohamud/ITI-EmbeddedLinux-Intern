cmake_minimum_required(VERSION 3.16)

project(Session3_Task VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick LinguistTools)

qt_standard_project_setup(
    REQUIRES 6.10
    I18N_SOURCE_LANGUAGE en
    I18N_TRANSLATED_LANGUAGES ar fr
)

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

qt_add_executable(appSession3_Task
    main.cpp
    LanguageManager.h
    LanguageManager.cpp
)

qt_add_qml_module(appSession3_Task
    URI Session3_Task

    QML_FILES
        Main.qml
        LoginPage.qml
        DashboardPage.qml
        SettingsPage.qml

    RESOURCES
        images/user.png
        images/air_conditioner.png
        images/bedroom_light.png
        images/fan.png
        images/garage_door.png
        images/light.png
        images/smart_home_background.png
        images/security_camera.png
        images/smart_lock.png
        images/smart_tv.png
        images/thermostat.png
        images/washing_machine.png
)

qt_add_translations(appSession3_Task
    TS_FILE_BASE Session3_Task
    TS_FILE_DIR i18n

    RESOURCE_PREFIX
        /qt/qml/Session3_Task/i18n
)

set_target_properties(appSession3_Task PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSession3_Task
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)

install(TARGETS appSession3_Task
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)