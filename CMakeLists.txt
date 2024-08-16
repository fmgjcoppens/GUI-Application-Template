cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(GUIApplicationTemplate)

find_package(Vulkan REQUIRED)

add_executable(GAT
    src/main.cpp)

include(cmake/CPM.cmake)
#CPMAddPackage("gh:fmtlib/fmt#11.0.2")
#CPMAddPackage("gh:gabime/spdlog#v2.x")
CPMAddPackage(
    NAME glfw
    GITHUB_REPOSITORY glfw/glfw
    GIT_TAG 3.4
    OPTIONS "GLFW_BUILD_DOCS OFF" "GLFW_BUILD_TESTS OFF" "GLFW_BUILD_EXAMPLES OFF")
CPMAddPackage("gh:fmgjcoppens/imgui#docking")

target_link_libraries(GAT
    #fmt
    #spdlog
    Vulkan::Vulkan
    glfw
    imgui)
