# Copyright (c) 2022 Kaiyan M. Lee
#
# This project is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License v3.0.

cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

project(qt6-benchmarks VERSION 0.0.0 LANGUAGES CXX)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

macro(set_opt)
  set(${ARGV0} ${ARGV1} CACHE INTERNAL "")
endmacro()

set_opt(CMAKE_CXX_STANDARD 20)
set_opt(CMAKE_CXX_STANDARD_REQUIRED ON)
set_opt(CMAKE_CXX_EXTENSIONS OFF)
set_opt(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY ON)
set_opt(CMAKE_VERBOSE_MAKEFILE OFF)
set_opt(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_opt(CMAKE_COLOR_MAKEFILE ON)
set_opt(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)
set_opt(CMAKE_UNITY_BUILD OFF)
set_opt(CMAKE_OPTIMIZE_DEPENDENCIES ON)
set_opt(CMAKE_ENABLE_EXPORTS OFF)
set_opt(CMAKE_POSITION_INDEPENDENT_CODE ON)
set_opt(CMAKE_AUTOGEN_VERBOSE OFF)
set_opt(CMAKE_AUTOMOC_PATH_PREFIX ON)
set_opt(CMAKE_SKIP_INSTALL_RPATH ON)
set_opt(CMAKE_RULE_MESSAGES OFF)
set_opt(CMAKE_ERROR_DEPRECATED ON)

set_opt(BENCHMARKS_ENABLE_STRING ON)
set_opt(BENCHMARKS_ENABLE_QUICK_VS_WIDGETS ON)

find_program(CCACHE_PROGRAM "ccache")
if(CCACHE_PROGRAM)
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif()

add_compile_definitions(QT_NO_DEBUG)
add_compile_definitions(QT_NO_DEBUG_OUTPUT)

add_compile_definitions(QT_NO_CAST_TO_ASCII
                        QT_NO_CAST_FROM_ASCII
                        QT_NO_KEYWORDS
                        QT_NO_FOREACH
                        QT_NO_NARROWING_CONVERSIONS_IN_CONNECT
                        QT_NO_CURSOR
                        QT_NO_JAVA_STYLE_ITERATORS
                        QT_NO_SESSIONMANAGER
                        QT_NO_WIDGETS
                        QT_NO_CAST_FROM_BYTEARRAY
                        QT_NO_DBUS
                        QT_NO_ACTION
                        QT_NO_SHORTCUT
                        QT_NO_URL_CAST_FROM_STRING
)

enable_testing()

if(BENCHMARKS_ENABLE_STRING)
  add_subdirectory("string-benchmarks")
endif()

if(BENCHMARKS_ENABLE_QUICK_VS_WIDGETS)
  add_subdirectory("quick-vs-widgets")
endif()
