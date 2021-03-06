#cmake_minimum_required(VERSION 3.5)
project (SmallIntRangeLibrary)

#=== FINDING PACKAGES ===#

# Locate GTest package (library)
# find_package(GTest REQUIRED)
include_directories(include)
#${GTEST_INCLUDE_DIRS}

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall -pthread" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

#Include dir
include_directories( include )

#=== Library ===
# We want to build a static library.
add_library(IntRange STATIC "src/int_ranges.cpp")

#define C++11 as the standard.
target_compile_features(IntRange PUBLIC cxx_std_11)

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "make install" to apply
install(TARGETS IntRange ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib)

#=== Driver App ===
# Define where the linker should look for libraries at
link_directories( ${CMAKE_SOURCE_DIR}/lib ) # The library is locally installed.

# Define the sources
add_executable(driver_ranges "src/driver.cpp")

set(MY_GTEST_LIB "lib/libgtest.a" "lib/libgtest_main.a")

# Define the lib to link to.
target_link_libraries(driver_ranges PRIVATE IntRange )

#define C++11 as the standard.
target_compile_features(driver_ranges PUBLIC cxx_std_11)

#=== Test target ===

# Define the sources
add_executable(run_tests "test/main.cpp")

# Link with the google test libraries.
target_link_libraries(run_tests PRIVATE ${GTEST_LIBRARIES} PRIVATE IntRange )

#define C++11 as the standard.
target_compile_features(run_tests PUBLIC cxx_std_11)
