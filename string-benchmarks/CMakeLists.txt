# Copyright (c) 2022 Kaiyan M. Lee
#
# This project is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License v3.0.

project(qstring-benchmarks)

find_package(Qt6 REQUIRED COMPONENTS Core Test)

set(CMAKE_AUTOMOC ON)

add_executable(qstring-benchmarks "benchmark.cc" "benchmark.h")
target_link_libraries(qstring-benchmarks Qt6::Test)
add_test(qstring-benchmarks qstring-benchmarks)
