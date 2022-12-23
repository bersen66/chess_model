cmake_minimum_required(VERSION 3.5)

project(TEMPLATE VERSION 0.1 LANGUAGES CXX) # change project name here

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

include_directories(include)

#Add app-sources there
add_library(
        APPLICATION
        src/chess/figure.cpp
        src/chess/sector.cpp
        src/chess/field.cpp
        src/chess/chess.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(Boost COMPONENTS stacktrace_backtrace REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} Boost::stacktrace_backtrace)
endif ()


get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)
option(ENABLE_TESTING "Enable testing" ON)



if (NOT ENABLE_TESTING)
    message(STATUS "Testing disabled")
elseif (IS_SUBPROJECT)
    message(STATUS "Do not build tests for subproject")
else ()
    add_subdirectory(tests)
endif ()

find_package(fmt REQUIRED)
if (fmt_FOUND)
    message("${PROJECT_NAME}: FOUND FMT")
    include_directories(${fmt_INCLUDE_DIRS})
    target_link_libraries(APPLICATION ${fmt_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} ${fmt_LIBRARIES})
endif ()

target_link_libraries(${PROJECT_NAME} APPLICATION)
