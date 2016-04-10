#-------------------------------------------------
#
# Project created by QtCreator 2016-04-09T17:16:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = basicOccWidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    occtwindow.cpp \
    occview.cpp

HEADERS  += mainwindow.h \
    occtwindow.h \
    occview.h

FORMS    += mainwindow.ui

LIBS += -lTKernel -lPTKernel -lTKMath -lTKService -lTKV3d -lTKOpenGl \
        -lTKBRep -lTKIGES -lTKSTL -lTKVRML -lTKSTEP -lTKSTEPAttr -lTKSTEP209 \
        -lTKSTEPBase -lTKShapeSchema -lTKGeomBase -lTKGeomAlgo -lTKG3d -lTKG2d \
        -lTKXSBase -lTKPShape -lTKShHealing -lTKHLR -lTKTopAlgo -lTKMesh -lTKPrim \
        -lTKCDF -lTKBool -lTKBO -lTKFillet -lTKOffset \
