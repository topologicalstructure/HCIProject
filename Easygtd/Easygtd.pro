QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deadlinedistri.cpp \
    expectedworks.cpp \
    extendedworks.cpp \
    longtermworks.cpp \
    main.cpp \
    mainwindow.cpp \
    smallwindows.cpp \
    todayworks.cpp \
    yesterdayworks.cpp

HEADERS += \
    deadlinedistri.h \
    expectedworks.h \
    extendedworks.h \
    longtermworks.h \
    mainwindow.h \
    smallwindows.h \
    sqlconn.h \
    todayworks.h \
    yesterdayworks.h

FORMS += \
    deadlinedistri.ui \
    expectedworks.ui \
    extendedworks.ui \
    longtermworks.ui \
    mainwindow.ui \
    smallwindows.ui \
    todayworks.ui \
    yesterdayworks.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
TARGET = EasyGTD
RC_ICONS = Projectico.ico
QT+=sql
