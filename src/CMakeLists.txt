cmake_minimum_required(VERSION 3.7)
cmake_policy(SET CMP0048 NEW)

project(ics-servo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PYBIND11_CPP_STANDARD -std=c++14)


if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-pedantic-errors -Wall -Werror -Weverything -Wno-float-equal -Wno-padded -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-missing-prototypes -Wno-range-loop-analysis)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-pedantic-errors -Wall -Wextra -Werror -Wno-float-equal -Wno-padded -Wno-unused-parameter -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef)
endif()

if(NOT CONFIG)
  set(CONFIG Release)
endif()

if(CONFIG STREQUAL "Debug")
  add_compile_options(-O0 -g3)
elseif(CONFIG STREQUAL "Release")
  add_compile_options(-O3 -Wno-error)
endif()

include_directories(include/)

add_subdirectory(lib)
add_subdirectory(bin)

add_subdirectory(pybind11)
# pybind11 headers produce so many errors with strict compiler options
include_directories(SYSTEM ${PYBIND11_INCLUDE_DIR})

add_subdirectory(python)
