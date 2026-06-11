TARGET = UAR
TEMPLATE = app

QT += core widgets charts network

CONFIG += c++17

win32: CONFIG += windows

HEADERS += \
    UAR_ARX/NetworkData.h \
    UAR_ARX/NetworkManager.h \
    mainwindow.h \
    graph.h \
    arx_settings.h \
    UAR_ARX/ARX_Model.h \
    UAR_ARX/FeedbackLoop.h \
    UAR_ARX/Generator.h \
    UAR_ARX/MenagerSymulacji.h \
    UAR_ARX/NQueue.h \
    UAR_ARX/Regulator_PID.h \
    UAR_ARX/Testy.h

SOURCES += \
    UAR_ARX/NetworkManager.cpp \
    main.cpp \
    mainwindow.cpp \
    graph.cpp \
    arx_settings.cpp \
    UAR_ARX/ARX_Model.cpp \
    UAR_ARX/FeedbackLoop.cpp \
    UAR_ARX/Generator.cpp \
    UAR_ARX/MenagerSymulacji.cpp \
    UAR_ARX/Regulator_PID.cpp \
    UAR_ARX/Testy.cpp

FORMS += \
    mainwindow.ui \
    arx_settings.ui

INCLUDEPATH += UAR_ARX

target.path = $$[QT_INSTALL_BINS]
INSTALLS += target
