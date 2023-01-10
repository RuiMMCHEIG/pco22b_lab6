QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 console

QT += testlib gui

LIBS += -lpcosynchro

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/application.cpp \
    src/barber.cpp \
    src/client.cpp \
    src/main.cpp \
    src/pcosalon.cpp \
    src/utils/display.cpp \
    src/utils/graphicsaloninterface.cpp \
    src/utils/mainwindow.cpp

HEADERS += \
    src/application.h \
    src/barber.h \
    src/client.h \
    src/pcosalon.h \
    src/salon.h \
    src/salonbarberinterface.h \
    src/salonclientinterface.h\
    src/utils/display.h \
    src/utils/graphicsaloninterface.h \
    src/utils/launchable.h \
    src/utils/mainwindow.h

FORMS += \
    src/utils/mainwindow.ui

RESOURCES += \
    assets/ \
    assets/actors \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
