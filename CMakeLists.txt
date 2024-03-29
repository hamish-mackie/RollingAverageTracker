cmake_minimum_required(VERSION 3.22)
project(RollingAverageTracker)

set(CMAKE_CXX_STANDARD 20)

add_library(RollingAverageTracker INTERFACE)
target_include_directories(RollingAverageTracker INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/source)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(RollingAverageTrackerTests tests/main_tests.cpp)

target_link_libraries(RollingAverageTrackerTests
        PUBLIC RollingAverageTracker gtest_main
)

include(GoogleTest)
gtest_discover_tests(RollingAverageTrackerTests)
