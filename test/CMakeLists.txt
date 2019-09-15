cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11" )



add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )

set(TEST_SOURCE_FILES runAllTests.cpp FileLoaderTest.cpp ProgressBarTest.cpp BitProgressBarTest.cpp)

add_executable(runAllTests ${TEST_SOURCE_FILES})

target_link_libraries(runAllTests gtest gtest_main core )