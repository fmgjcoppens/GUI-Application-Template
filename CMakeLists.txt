cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(GUIApplicationTemplate)

add_executable(GAT src/main.cpp)

include(cmake/CPM.cmake)
CPMAddPackage("gh:fmtlib/fmt#11.0.2")
#CPMAddPackage("gh:gabime/spdlog#v1.14.1")
CPMAddPackage("gh:gabime/spdlog#v2.x")
CPMAddPackage("gh:glfw/glfw#3.4")
CPMAddPackage("gh:fmgjcoppens/imgui#docking")

target_link_libraries(GAT fmt spdlog glfw imgui)
