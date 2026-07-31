cmake_minimum_required(VERSION 4.3)
project(CS106B_Study)

set(CMAKE_CXX_STANDARD 20)

# -----字符编码配置-----
# 针对 MSVC 编译器（如 Visual Studio 工具链）
if (MSVC)
    add_compile_options(/utf-8)
endif()

# 针对 GCC / Clang 编译器（如 MinGW / Linux GCC）
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()
# -----字符编码配置-----
