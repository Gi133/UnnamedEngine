cmake_minimum_required (VERSION 3.8)

set(LIB_NAME UnnamedEngineCore)

set(LIB_SOURCE_FILES
    "enginecore.cpp"
    "source/application.cpp"

    "include/application.h"
)

add_library(${LIB_NAME} ${LIB_SOURCE_FILES})

target_include_directories(${LIB_NAME}
    PUBLIC
        "include"
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIB_NAME}
    PUBLIC
        SDL2
        SDL2main
)
