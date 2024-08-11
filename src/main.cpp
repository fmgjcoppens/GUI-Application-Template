#include <fmt/core.h>
#include "spdlog/spdlog.h"
#include <GLFW/glfw3.h>

int main (int argc, char *argv[]) {
    fmt::print("We're up and running!\n");
    spdlog::info("Welcome to spdlog!");
    return 0;
}
