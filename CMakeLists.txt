cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
project(GUIApplicationTemplate LANGUAGES CXX)

#################
## MAIN TARGE  ##
#################
# The main build target (it is nice if the main target is defined first because
# the nvim-cmake plugin picks the first one from the Ninja build script).
add_executable(GAT
    src/main.cpp
    src/GAT.cpp)

target_include_directories(GAT PRIVATE include)

target_link_libraries(GAT
    Vulkan::Vulkan
    glfw
    imgui
    fmt
    spdlog)

##################
## DEPENDENCIES ##
##################
# The Vulkan SDK should be available on the system
find_package(Vulkan REQUIRED)

# Load CMake Package Manager
include(cmake/CPM.cmake)

# Pull in and build glfw
CPMAddPackage(
    NAME glfw
    GITHUB_REPOSITORY glfw/glfw
    GIT_TAG 3.4
    OPTIONS "GLFW_BUILD_DOCS OFF" "GLFW_BUILD_TESTS OFF" "GLFW_BUILD_EXAMPLES OFF")

# This will pull in only the ImGui GH repository, because not a Cmake project
CPMAddPackage("gh:ocornut/imgui#docking")
# Build ImGui from the repo we just pulled
include(cmake/imgui.cmake)

# Use fmt instead if iostream
CPMAddPackage("gh:fmtlib/fmt#11.0.2")

# Use spdlog logger.
CPMAddPackage("gh:gabime/spdlog#v2.x")
