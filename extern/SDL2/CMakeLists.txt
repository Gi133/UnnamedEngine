cmake_minimum_required (VERSION 3.14)

include(FetchContent)
FetchContent_Declare(
    SDL2
    GIT_REPOSITORY  https://github.com/libsdl-org/SDL.git
    GIT_TAG         release-2.0.14
    GIT_SHALLOW     true
)
FetchContent_MakeAvailable(SDL2)