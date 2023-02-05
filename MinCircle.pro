QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algorithm/circle.cpp \
    algorithm/coords_converter.cpp \
    algorithm/min_disc_builder.cpp \
    exceptions/not_enough_points_exception.cpp \
    main.cpp \
    min_circle.cpp \
    paint_scene.cpp

HEADERS += \
    algorithm/circle.h \
    algorithm/coords_converter.h \
    algorithm/min_disc_builder.h \
    exceptions/not_enough_points_exception.h \
    min_circle.h \
    paint_scene.h

FORMS += \
    min_circle.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
