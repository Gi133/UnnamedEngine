cmake_minimum_required(VERSION 3.16)

include(GoogleTest)

set(TARGET_NAME UnnamedEngineUnittests)

add_executable(${TARGET_NAME})

file(GLOB_RECURSE UNITTEST_FILES *_unittest.cpp *_unittest.h)

target_sources(${TARGET_NAME}
    PRIVATE
        "unnamedenginetests.cpp"
        "unnamedenginetests.h"
        ${UNITTEST_FILES}
)

target_include_directories(${TARGET_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(${TARGET_NAME}
    PRIVATE
        gtest_main
        UnnamedEngine::enginecore
)

#Not the best way to do this...
target_compile_options(${TARGET_NAME}
    PRIVATE
        -MT$<$<CONFIG:Debug>:d>
)

gtest_discover_tests(${TARGET_NAME})