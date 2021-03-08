cmake_minimum_required (VERSION 3.8)

set(LIB_NAME UnnamedEngineCore)

set(LIB_SOURCE_FILES
    enginecore.cpp
)

add_library(${LIB_NAME} ${LIB_SOURCE_FILES})

target_link_libraries(${LIB_NAME}
    PUBLIC
        SDL2
        SDL2main
)
