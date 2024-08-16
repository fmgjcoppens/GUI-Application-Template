cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
project(GUIApplicationTemplate LANGUAGES CXX)

find_package(Vulkan REQUIRED)

add_executable(GAT src/main.cpp)

include(cmake/CPM.cmake)
CPMAddPackage(
    NAME glfw
    GITHUB_REPOSITORY glfw/glfw
    GIT_TAG 3.4
    OPTIONS "GLFW_BUILD_DOCS OFF" "GLFW_BUILD_TESTS OFF" "GLFW_BUILD_EXAMPLES OFF")

CPMAddPackage("gh:ocornut/imgui#docking")
include(cmake/imgui.cmake)

target_link_libraries(GAT
    Vulkan::Vulkan
    glfw
    imgui)
