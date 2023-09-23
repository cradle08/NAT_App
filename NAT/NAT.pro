QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ctrlflow_graphicsview.cpp \
    main.cpp \
    login.cpp \
    mainwindow.cpp \
    serial_protocolmsg.cpp \
    serial_toolbar.cpp \
    serialconfig.cpp \
    workflow.cpp \
    workflow_end.cpp \
    workflow_goto.cpp \
    workflow_start.cpp \
    workflow_temp.cpp \
    workflow_tempdata.cpp

HEADERS += \
    ctrlflow_graphicsview.h \
    global_define.h \
    login.h \
    mainwindow.h \
    serial_protocolmsg.h \
    serial_toolbar.h \
    serialconfig.h \
    workflow.h \
    workflow_end.h \
    workflow_goto.h \
    workflow_start.h \
    workflow_temp.h \
    workflow_tempdata.h

FORMS += \
    login.ui \
    mainwindow.ui \
    serialconfig.ui

TRANSLATIONS += \
    NAT_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ui.qrc
