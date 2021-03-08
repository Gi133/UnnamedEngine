cmake_minimum_required (VERSION 3.8)

set(EXE_NAME UnnamedEngine)

set (${EXE_NAME}_SOURCE_FILES
    "UnnamedEngine.cpp"

    "UnnamedEngine.h"
)
add_executable (${EXE_NAME} ${${EXE_NAME}_SOURCE_FILES})

target_link_libraries(${EXE_NAME}
    PRIVATE
        UnnamedEngineCore
)

add_custom_command(TARGET ${EXE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:SDL2>"
        "$<TARGET_FILE_DIR:${EXE_NAME}>"
)
