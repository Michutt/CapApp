cmake_minimum_required(VERSION 3.16)

project(CapApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick Core SerialPort REQUIRED)


qt_add_executable(appCapApp
    main.cpp
    serialportfactory.cpp      serialportfactory.h
    backend.cpp                backend.h
    resources/icon.rc
)

qt_add_qml_module(appCapApp
    URI CapApp
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(appCapApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appCapApp
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(appCapApp
    PRIVATE Qt6::Quick
            Qt::Core
            Qt::SerialPort
)
