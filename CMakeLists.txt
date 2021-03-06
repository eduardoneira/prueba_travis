cmake_minimum_required(VERSION 2.8)
project (TestRocksdb)

#Flags

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	#set(warnings "-Wall -Wextra")
endif()
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${warnings}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -pthread -fprofile-arcs -ftest-coverage") #tal vez incluir pthread como las demas, no hardcodeada

# "-Wl,--as-needed" hace que solo se linkee con librerias que se usan en el ejecutable"
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--as-needed -L/usr/lib")


#For the source files:
file(GLOB SOURCES "src/*.cpp")

#For the static libraries:

#include_directories(RocksDB)
add_library(RocksDB STATIC IMPORTED)
set_property(TARGET RocksDB PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/RocksDB/librocksdb.a")

# Zlib
#include_directories(Zlib)
add_library(Zlib STATIC IMPORTED)
set_property(TARGET Zlib PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/Zlib/libz.a")

# Snappy
#include_directories(Snappy)
add_library(Snappy STATIC IMPORTED)
set_property(TARGET Snappy PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/Snappy/libsnappy.a")

# Bz2
#include_directories(Bz2)
add_library(Bz2 STATIC IMPORTED)
set_property(TARGET Bz2 PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/Bz2/libbz2.a")

# GTest y GMock
add_library(GMock STATIC IMPORTED)
set_property(TARGET GMock PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/GMock/libgmock.a")

add_library(GMock_main STATIC IMPORTED)
set_property(TARGET GMock_main PROPERTY IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/GMock/libgmock_main.a")

#Includes for .h
include_directories(include)
include_directories(src)

add_executable(machoTest ${SOURCES})
target_link_libraries(machoTest RocksDB Zlib Snappy Bz2 GMock GMock_main -lrt)
