cmake_minimum_required(VERSION 3.16)
project(cmake_example) #update project name

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(cifuzz NO_SYSTEM_ENVIRONMENT_PATH)
enable_fuzz_testing()

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp ) 

target_link_libraries(${PROJECT_NAME} PRIVATE passchecker)

add_fuzz_test(test1 test/test1.cpp)
target_link_libraries(test1 PRIVATE passchecker)