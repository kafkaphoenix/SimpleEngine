cmake_minimum_required(VERSION 3.21)
project(SimpleEngine VERSION 0.1 DESCRIPTION "A simple game engine" LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the source files
set(SOURCE_FILES src/Engine.cpp)
set(HEADER_FILES src/Engine.h)

# Create the library
add_library(SimpleEngine STATIC ${SOURCE_FILES} ${HEADER_FILES})

# Set the include directories
target_include_directories(SimpleEngine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:src>
)

# Installation rules
install(TARGETS SimpleEngine
    EXPORT SimpleEngineTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION src
)

install(DIRECTORY src/ DESTINATION src FILES_MATCHING PATTERN "*.h")

# Export the package for find_package
install(EXPORT SimpleEngineTargets
    FILE SimpleEngineTargets.cmake
    NAMESPACE SimpleEngine::
    DESTINATION lib/cmake/SimpleEngine
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/SimpleEngineConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/SimpleEngineConfig.cmake"
    INSTALL_DESTINATION lib/cmake/SimpleEngine
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/SimpleEngineConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/SimpleEngineConfigVersion.cmake"
    DESTINATION lib/cmake/SimpleEngine
)
