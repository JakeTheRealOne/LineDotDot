TEMPLATE = app
TARGET = LineDotDot
INCLUDEPATH += .
QT += widgets core gui
SOURCES += asset/app_infos.cpp source/encyclopedia.cpp source/settings.cpp source/decoder.cpp source/encoder.cpp source/about.cpp source/gui.cpp source/gui_wrapper.cpp source/main.cpp
HEADERS += header/encyclopedia.hpp header/settings.hpp header/decoder.hpp header/encoder.hpp header/about.hpp header/gui.hpp header/gui_wrapper.hpp
OBJECTS_DIR = object