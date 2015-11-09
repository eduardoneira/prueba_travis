cmake_minimum_required(VERSION 2.8.9)
project (TestRocksdb)

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


#Includes for .h
include_directories(include)
include_directories(src)

add_executable(machoTest ${SOURCES})
target_link_libraries(machoTest RocksDB Zlib Snappy Bz2 )
set(CMAKE_CXX_FLAGS " -std=c++11 -pthread -g -lrt" )
