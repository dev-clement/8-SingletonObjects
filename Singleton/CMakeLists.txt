cmake_minimum_required(VERSION 3.16)

project(Singleton VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appSingleton
    ./src/main.cpp
)

qt_add_qml_module(appSingleton
    URI Singleton
    VERSION 1.0
    QML_FILES
        ./qml/Main.qml
    SOURCES
        ./inc/mysingleton.hpp
        ./src/mysingleton.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appSingleton PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appSingleton
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(appSingleton PUBLIC ./inc/)

target_link_libraries(appSingleton
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appSingleton
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
