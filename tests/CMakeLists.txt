cmake_minimum_required(VERSION 3.5)
project(${PROJECT_NAME}_TESTS)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} APPLICATION)

find_package(GTest REQUIRED)
if (GTest_FOUND)
    message("${PROJECT_NAME}: GTEST FOUND")
    include_directories(${GTest_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${GTest_LIBRARIES})
endif()