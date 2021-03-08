cmake_minimum_required (VERSION 3.8)

include(FetchContent)
FetchContent_Declare(
    SDL2
    PREFIX          ${CMAKE_CURRENT_SOURCE_DIR}
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL.git
    GIT_TAG         release-2.0.14
)
FetchContent_MakeAvailable(SDL2)