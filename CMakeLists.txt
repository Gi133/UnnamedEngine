cmake_minimum_required (VERSION 3.8)

enable_testing()
project ("UnnamedEngine" CXX)

# Include sub-projects.
add_subdirectory ("extern")
add_subdirectory ("source")
add_subdirectory ("tests")