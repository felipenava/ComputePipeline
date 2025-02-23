cmake_minimum_required(VERSION 3.15)
project(ComputePipeline)

# Set the C++ standard to C++14.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(CORE_DIR "${SRC_DIR}/Core")
set(SYSTEMS_DIR "${SRC_DIR}/Systems")
set(LOADERS_DIR "${SRC_DIR}/Loaders")
set(FACTORIES_DIR "${SRC_DIR}/Factories")
set(UTILS_DIR "${SRC_DIR}/Utils")

# Include all header directories.
include_directories(
    ${CORE_DIR}
    ${SYSTEMS_DIR}
    ${LOADERS_DIR}
    ${FACTORIES_DIR}
    ${UTILS_DIR}
)

# Collect all source and header files.
file(GLOB SOURCES
    "${SRC_DIR}/main.cpp"
    "${CORE_DIR}/*.h"
    "${SYSTEMS_DIR}/*.h"
    "${LOADERS_DIR}/*.h"
    "${FACTORIES_DIR}/*.h"
    "${UTILS_DIR}/*.h"
)

# Define the executable target.
add_executable(ComputePipeline ${SOURCES})

# Set output directory for the compiled executable.
set_target_properties(ComputePipeline PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)