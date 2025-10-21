QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    countryinfo.cpp

HEADERS += \
    countryinfo.h

# Configuración de release
CONFIG(release, debug|release) {
    DESTDIR = release
    OBJECTS_DIR = release/obj
    MOC_DIR = release/moc
    RCC_DIR = release/rcc
    UI_DIR = release/ui
}

# Configuración de debug
CONFIG(debug, debug|release) {
    DESTDIR = debug
    OBJECTS_DIR = debug/obj
    MOC_DIR = debug/moc
    RCC_DIR = debug/rcc
    UI_DIR = debug/ui
}

# Nombre del ejecutable
TARGET = CountryInfo