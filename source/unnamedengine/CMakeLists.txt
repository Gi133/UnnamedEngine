cmake_minimum_required (VERSION 3.8)

set(EXE_NAME UnnamedEngine)

set (${EXE_NAME}_SOURCE_FILES
    "UnnamedEngine.cpp"

    "UnnamedEngine.h"
)
add_executable (${EXE_NAME} WIN32 ${${EXE_NAME}_SOURCE_FILES})

target_link_libraries(${EXE_NAME}
    PRIVATE
        engine
)

target_compile_definitions(${EXE_NAME}
    PRIVATE
        NOMINMAX
        WIN32_LEAN_AND_MEAN
)

add_custom_command(TARGET ${EXE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:SDL2>"
        "$<TARGET_FILE_DIR:${EXE_NAME}>"
)

add_custom_command(TARGET ${EXE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:enginecore>"
        "$<TARGET_FILE_DIR:${EXE_NAME}>"
)

add_custom_command(TARGET ${EXE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:engine>"
        "$<TARGET_FILE_DIR:${EXE_NAME}>"
)