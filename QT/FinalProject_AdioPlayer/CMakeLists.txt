cmake_minimum_required(VERSION 3.16)

project(FinalProject_AdioPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Qml
    Quick
    Multimedia
    Bluetooth
    Network
)

qt_standard_project_setup(REQUIRES 6.11)

if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

qt_add_executable(appFinalProject_AdioPlayer
    main.cpp
)

qt_add_qml_module(appFinalProject_AdioPlayer
    URI FinalProject_AdioPlayer

    QML_FILES
        Main.qml
        SplashPage.qml
        SourcePage.qml
        LocalAudioPage.qml
        RadioPage.qml
        USBPage.qml
        BluetoothPage.qml

        SOURCES
            audioplayer.h
            audioplayer.cpp

            radioplayer.h
            radioplayer.cpp

            loggin.h
            loggin.cpp

            bluetoothmanager.h
            bluetoothmanager.cpp

    RESOURCES
        images/splashPage.png
        images/blutooth.png
        images/localAduio.png
        images/radio.png
        images/sourcepage.png
        images/USB.png
        images/Next.png
        images/pause.png
        images/play.png
        images/privous.png
        images/stop.png
        images/muted.png
        images/unmuted.png
        images/folderUplode.png
        images/localAudioPlayer.png
        images/localPage.png
        images/return.png
        images/radioPlayer.png
        images/radio_connect.png
        images/USB_page.png
        images/USB_btn.png
        images/1.png
        images/bluetooth_btn.png
)

set_target_properties(appFinalProject_AdioPlayer PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING
        ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appFinalProject_AdioPlayer
    PRIVATE
        Qt6::Quick
        Qt6::Multimedia
        Qt6::Bluetooth
        Qt6::Network
)

install(TARGETS appFinalProject_AdioPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)