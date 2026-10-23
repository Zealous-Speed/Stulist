
cmake_minimum_required(VERSION 3.20)

project(StudentManagement LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(StudentManagement
    src/main.cpp
    src/Mystring.cpp
    src/StudentList.cpp
)

target_include_directories(StudentManagement
    PRIVATE include
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(StudentManagement
        PRIVATE -Wall -Wextra
    )
endif()
