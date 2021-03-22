cmake_minimum_required (VERSION 3.8)
include(GenerateExportHeader)

set(LIB_NAME engine)

set(LIB_SOURCE_FILES
    "engine.cpp"
    "source/application.cpp"

    "engine.h"
    "${LIB_NAME}_export.h"
    "include/engine/application.h"
 )

add_library(${LIB_NAME} ${LIB_SOURCE_FILES})
#add_library(${LIB_NAME} SHARED ${LIB_SOURCE_FILES})
add_library(UnnamedEngine::${LIB_NAME} ALIAS ${LIB_NAME})

generate_export_header(${LIB_NAME} 
    EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/${LIB_NAME}_export.h
)

target_include_directories(${LIB_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include/"
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIB_NAME}
    PUBLIC
        SDL2main
        enginecore
)
