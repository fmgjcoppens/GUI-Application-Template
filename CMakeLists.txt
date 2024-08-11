cmake_minimum_required(VERSION 3.10)

project(GUIApplicationTemplate)

add_executable(GAT src/main.cpp)

include(cmake/CPM.cmake)
CPMAddPackage("gh:fmtlib/fmt#11.0.2")
CPMAddPackage("gh:glfw/glfw#3.4")
CPMAddPackage("gh:fmgjcoppens/imgui#docking")

target_link_libraries(GAT fmt glfw imgui)
