cmake_minimum_required(VERSION 3.16)

project(FinalProject_AdioPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia)

qt_standard_project_setup(REQUIRES 6.10)

# Content of downloaded design from Figma to Qt or similar
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
        SOURCES audioplayer.h audioplayer.cpp
        SOURCES radioplayer.h radioplayer.cpp
        SOURCES loggin.h loggin.cpp
    RESOURCES
        images/splashPage.png
        images/blutooth.png
        images/localAduio.png
        images/radio.png
        images/sourcepage.png
        images/USB.png
        images/muted.png
        images/Next.png
        images/pause.png
        images/play.png
        images/privous.png
        images/stop.png
        images/unmuted.png
        images/folderUplode.png
        images/localAudioPlayer.png
        images/localPage.png
        images/return.png
        images/radioPlayer.png
        images/radio_connect.png

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appFinalProject_AdioPlayer PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appFinalProject_AdioPlayer
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appFinalProject_AdioPlayer
    PRIVATE
    Qt6::Quick
    Qt6::Multimedia
)

install(TARGETS appFinalProject_AdioPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
