cmake_minimum_required (VERSION 3.14)

include(FetchContent)
FetchContent_Declare(
    GTest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         release-1.10.0
    GIT_SHALLOW     true
)
FetchContent_MakeAvailable(GTest)

#disable gmock
if (TARGET gmock)
    set_target_properties(gmock PROPERTIES EXCLUDE_FROM_ALL TRUE)
endif()

if (TARGET gmock_main)
    set_target_properties(gmock_main PROPERTIES EXCLUDE_FROM_ALL TRUE)
endif()

#No need for the others if we have this.
set(BUILD_GMOCK FALSE CACHE BOOL "" FORCE)