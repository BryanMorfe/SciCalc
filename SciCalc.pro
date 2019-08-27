#-------------------------------------------------
#
# Project created by QtCreator 2019-08-12T16:47:18
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SciCalc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        src/main.cpp \
        src/scbinaryfunction.cpp \
        src/scbinaryoperator.cpp \
        src/scevaluator.cpp \
        src/scexpression.cpp \
        src/scexpressionparser.cpp \
        src/scexpressionvalidator.cpp \
        src/scfunction.cpp \
        src/scinexpression.cpp \
        src/scoperand.cpp \
        src/scoperator.cpp \
        src/scoutputdisplay.cpp \
        src/scparsedexpression.cpp \
        src/scstore.cpp \
        src/sctoken.cpp \
        src/sctokenoperations.cpp \
        src/sctokenrepresentable.cpp \
        src/scunaryfunction.cpp \
        src/scunaryoperator.cpp \
        src/scwindow.cpp

HEADERS += \
        include/scbinaryfunction.h \
        include/scbinaryoperator.h \
        include/scevaluator.h \
        include/scexpression.h \
        include/scexpressionparser.h \
        include/scexpressionvalidator.h \
        include/scfunction.h \
        include/scinexpression.h \
        include/scoperand.h \
        include/scoperator.h \
        include/scoutputdisplay.h \
        include/scparsedexpression.h \
        include/scstore.h \
        include/sctoken.h \
        include/sctokenoperations.h \
        include/sctokenrepresentable.h \
        include/sctokentypes.h \
        include/scunaryfunction.h \
        include/scunaryoperator.h \
        include/scwindow.h

FORMS += \
    scwindow.ui

QMAKE_LIBFLAGS += \VERBOSE

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
