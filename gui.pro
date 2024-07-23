TEMPLATE = app
TARGET = LineDotDot
INCLUDEPATH += .
QT += widgets core
SOURCES += source/encyclopedia.cpp source/settings.cpp source/decoder.cpp source/encoder.cpp source/gui.cpp source/main.cpp
HEADERS += header/encyclopedia.hpp header/settings.hpp header/decoder.hpp header/encoder.hpp header/gui.hpp
OBJECTS_DIR = object