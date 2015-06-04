#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T14:41:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Haushaltsbuch
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    booking.cpp \
    category.cpp \
    bookingwidget.cpp \
    categorycombobox.cpp

HEADERS  += mainwindow.h \
    booking.h \
    category.h \
    bookingwidget.h \
    categorycombobox.h \
    constants.h

FORMS    += mainwindow.ui \
    bookingwidget.ui

RESOURCES += \
    icons.qrc

ICON = book227.icns
