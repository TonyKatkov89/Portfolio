cmake_minimum_required(VERSION 3.5)

project(S21_SmartCalc_v2_1 VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui Widgets PrintSupport)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Widgets PrintSupport)



set(PROJECT_SOURCES
        main.cpp
        s21_smartcalc.cpp
        s21_smartcalc.h
        s21_smartcalc.ui
        graph.ui
        mortgage.cpp
        mortgage.h
        mortgage.ui
        qcustomplot.cpp
        qcustomplot.h
        s21_smartcalc.cpp
        s21_smartcalc.h
        s21_smartcalc.ui
        scale.cpp
        scale.h
        scale.ui
        ../model/lexem.h
        ui_creditpayments.h
        ui_graph.h
        ui_mortgage.h
        ui_s21_smartcalc.h
        ui_scale.h
        ../model/calculator.cpp
        ../model/calculator.h
        ../controller/calc_controller.cpp
        ../controller/calc_controller.h
        creditpayments.cpp
        creditpayments.h
        creditpayments.ui
        graph.cpp
        graph.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(S21_SmartCalc_v2_1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET S21_SmartCalc_v2_1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(S21_SmartCalc_v2_1 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(S21_SmartCalc_v2_1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

#add_dependencies(app qcustomplot)

target_link_libraries(S21_SmartCalc_v2_1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(S21_SmartCalc_v2_1 PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
#target_link_libraries(qcustomplot PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets Qt6::PrintSupport)

set_target_properties(S21_SmartCalc_v2_1 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS S21_SmartCalc_v2_1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(S21_SmartCalc_v2_1)
endif()
