# Collect source files
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.h)

# Create the library
add_library(SimpleEngine STATIC ${SOURCE_FILES} ${HEADER_FILES})

# Set the include directories
target_include_directories(SimpleEngine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Installation rules
install(TARGETS SimpleEngine
    EXPORT SimpleEngineTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")

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