# -----------------------------------------------------------------------------
# Determine CMake version and build type.
# -----------------------------------------------------------------------------
# NOTE: cmake_minimum_required() and project() *MUST* be the two first commands
# used, see https://cmake.org/cmake/help/v3.3/command/project.html -- the
# latter in particular handles loading a bunch of shared CMake definitions
# and loading the cross-compilation settings from CMAKE_TOOLCHAIN_FILE.
#
# cmake_minimum_required is also set inside Source/${FRAMEWORK}/CMakeLists.txt
# in support of the AppleWin internal build so this version should be kept in
# sync across those files.
#
cmake_minimum_required(VERSION 3.12)

include(cmake/Hunter/HunterGate.cmake)
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.311.tar.gz"
    SHA1 "1a82b9b73055879181cb1466b2ab5d48ee8ae410"
)

project(WebKit)

# Introduce variables:
# * CMAKE_INSTALL_LIBDIR
# * CMAKE_INSTALL_BINDIR
# * CMAKE_INSTALL_INCLUDEDIR
include(GNUInstallDirs)#MATTC

set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")#MATTC
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")#MATTC
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")#MATTC
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")#MATTC
set(namespace "${PROJECT_NAME}::")#MATTC

# -----------------------------------------------------------------------------
# Common configuration
#------------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Source/cmake") # MATTC do not override CMAKE_MODULE_PATH
include(WebKitCommon)

# -----------------------------------------------------------------------------
# Enable API unit tests and create a target for the test runner
# -----------------------------------------------------------------------------
if (ENABLE_API_TESTS)
    enable_testing()
endif ()

# -----------------------------------------------------------------------------
# Add module directories
# -----------------------------------------------------------------------------
add_subdirectory(Source)

# -----------------------------------------------------------------------------
# Add tools
# -----------------------------------------------------------------------------
if (ENABLE_TOOLS)
    add_subdirectory(Tools)
endif ()

if (DEVELOPER_MODE)
    add_subdirectory(PerformanceTests)
endif ()

# -----------------------------------------------------------------------------
# Print the features list last, for maximum visibility.
# -----------------------------------------------------------------------------
PRINT_WEBKIT_OPTIONS()

#MATTC
### Installation (https://github.com/forexample/package-example) {

include(CMakePackageConfigHelpers)

# Use:
# * TARGETS_EXPORT_NAME
# * PROJECT_NAME
configure_package_config_file(
    "cmake/template/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

install(
    FILES "${project_config}"
    DESTINATION "${config_install_dir}"
)

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)

### }

