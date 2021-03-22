cmake_minimum_required (VERSION 3.8)
include(GenerateExportHeader)

set(LIB_NAME enginecore)

set(LIB_SOURCE_FILES
    "enginecore.cpp"
    "source/logging.cpp"

    "enginecore.h"
    "${LIB_NAME}_export.h"
    "include/enginecore/logging.h"
)

#add_library(${LIB_NAME} SHARED ${LIB_SOURCE_FILES})
add_library(${LIB_NAME})
add_library(UnnamedEngine::${LIB_NAME} ALIAS ${LIB_NAME})

target_sources(${LIB_NAME}
    PRIVATE
        ${LIB_SOURCE_FILES}
)

generate_export_header(${LIB_NAME} 
    EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/${LIB_NAME}_export.h
)

target_include_directories(${LIB_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include/"
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(${LIB_NAME}
    PUBLIC
        SDL2
)
