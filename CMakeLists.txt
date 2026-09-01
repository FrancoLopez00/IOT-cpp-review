#[[

    @file CMakeLists.txt
    @brief CMake build configuration for cpp-oop-review project
    @author IoT Solution Development Team
    @date 2024-06-10
    @version 1.0.0
    @License MIT License

]]

#minimum required version of cmake
cmake_minimum_required(VERSION 4.3.1)

#project name and language
project(cpp-oop-review LANGUAGES CXX)

#check for minimum required version of cmake
if (CMAKE_VERSION VERSION_LESS "4.3.1")
    message(FATAL_ERROR "CMake version 4.3.1 or higher is required.")
endif ()

#compiler version check and c++26 support check
include(CheckCXXSourceCompiles)

set(CMAKE_REQUIRED_FLAGS "{CMAKE_REQUIRED_FLAGS} -std=c++26")
check_cxx_source_compiles("int main() {return 0; }" CXX26_SUPPORTED)
if(NOT CXX26_SUPPORTED)
    message(FATAL_ERROR "c++26 is not supported by the compiler")
endif ()
#sources files
set( SOURCES
    main.cpp
        include/DomainTypes.h
        src/Resource.cpp
)
#define executable target
add_executable(cpp-oop-review ${SOURCES})

#keep language settings and include paths target-scoped
set_target_properties(cpp-oop-review PROPERTIES
    CXX_STANDARD_26
    CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF)

target_include_directories(cpp-oop-review PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_custom_target(validate-upgrade
COMMAND ${CMAKE_COMMAND} -E echo "Validating toolchain> CMake ${CMAKE_VERSION}
/ ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION} / c++26"
VERBATIM)