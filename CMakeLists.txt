cmake_minimum_required(VERSION 2.8)
project(mastermind)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

foreach(MODULE IN ITEMS test engine)
    string(TOUPPER ${MODULE}_SRC MODULE_SRC)
    file(GLOB ${MODULE_SRC} "${MODULE}/*.h" "${MODULE}/*.cpp")
endforeach(MODULE)

add_library(engine ${ENGINE_SRC})

add_executable(runTests ${TEST_SRC})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread engine)
