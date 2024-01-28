QT       += core gui opengl

macx {
QT       += openglwidgets
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(./QtGifImage/src/gifimage/qtgifimage.pri)
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    command/command.cc \
    main.cpp \
    mainwindow.cpp \
    matrix/s21_matrix_oop.cc \
    objreader/objreader_v2.cc \
    oglwidget.cpp \
    transform/transform.cc

HEADERS += \
    command/command.h \
    mainwindow.h \
    matrix/s21_matrix_oop.h \
    objreader/objreader_v2.h \
    oglwidget.h \
    singleton_facade/facade.h \
    transform/transform.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
