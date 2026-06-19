QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addstudentdialog.cpp \
    dashboard.cpp \
    dormitory.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    restaurant.cpp \
    restaurantinfo.cpp \
    roominfo.cpp \
    rooms.cpp \
    sidebar.cpp \
    studentinfo.cpp \
    students.cpp \
    university.cpp

HEADERS += \
    addstudentdialog.h \
    dashboard.h \
    dormitory.h \
    login.h \
    mainwindow.h \
    restaurant.h \
    restaurantinfo.h \
    roominfo.h \
    rooms.h \
    sidebar.h \
    studentinfo.h \
    students.h \
    university.h

FORMS += \
    addstudentdialog.ui \
    dashboard.ui \
    dormitory.ui \
    login.ui \
    mainwindow.ui \
    restaurant.ui \
    rooms.ui \
    sidebar.ui \
    students.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    ProjectRessource.qrc
