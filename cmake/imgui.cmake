# This CMake script to build imgui as a static library is made to be used with
# a parent project that uses CPM to add GLFW and ImGui before this script is
# called. It uses only the headers of GLFW by means of the CPM variable
# ${glfw_SOURCE_DIR} and then build ImGui using the source path in CPM variable
# ${imgui_SOURCE_DIR}.
# The static library and ${INCLUDES} are then made available to the parent
# project.
cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
project(IMGUI LANGUAGES CXX)

set(INCLUDES
    ${imgui_SOURCE_DIR}/.
    ${imgui_SOURCE_DIR}/backends
    ${glfw_SOURCE_DIR}/include)

set(SOURCES
    ${imgui_SOURCE_DIR}/backends/imgui_impl_vulkan.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp)

add_library(imgui STATIC ${SOURCES})

# Use PUBLIC scope to make include files available to the parent project.
target_include_directories(imgui PUBLIC ${INCLUDES})
