QT       += core gui widgets
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    app_initializer.cpp \
    bcrypt.cpp \
    blowfish.cpp \
    database_manager.cpp \
    main.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    app_initializer.h \
    bcrypt.h \
    blowfish.h \
    database_manager.h \
    node_blf.h \
    openbsd.h
