# Copyright (c) 2022 Kaiyan M. Lee
#
# This project is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License v3.0.

project(quick-vs-widgets)

find_package(Qt6 REQUIRED
             COMPONENTS Core
                        Gui
                        Quick
                        Qml
                        Widgets
)

set(CMAKE_AUTOMOC ON)

add_executable(quick-executable "main.quick.cc")
target_link_libraries(quick-executable
                      PRIVATE Qt6::Core Qt6::Qml Qt6::Gui Qt6::Quick
)

add_executable(widgets-executable "main.widgets.cc")
target_link_libraries(widgets-executable
                      PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets
)

qt_add_executable(quick-engine-executable "main.quick-engine.cc")
target_link_libraries(quick-engine-executable
                      PRIVATE Qt6::Core Qt6::Qml Qt6::Quick Qt6::Gui
)

qt6_add_qml_module(quick-engine-executable
                   URI
                   "."
                   VERSION
                   "1.0"
                   QML_FILES
                   "main.qml"
)
