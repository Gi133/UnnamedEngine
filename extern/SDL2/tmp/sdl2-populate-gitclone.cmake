
if(NOT "C:/Users/xkost/source/repos/UnnamedEngine/extern/SDL2/src/sdl2-populate-stamp/sdl2-populate-gitinfo.txt" IS_NEWER_THAN "C:/Users/xkost/source/repos/UnnamedEngine/extern/SDL2/src/sdl2-populate-stamp/sdl2-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: 'C:/Users/xkost/source/repos/UnnamedEngine/extern/SDL2/src/sdl2-populate-stamp/sdl2-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "C:/Users/xkost/source/repos/UnnamedEngine/out/build/x64-Debug/_deps/sdl2-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'C:/Users/xkost/source/repos/UnnamedEngine/out/build/x64-Debug/_deps/sdl2-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"  clone --no-checkout "https://github.com/libsdl-org/SDL.git" "sdl2-src"
    WORKING_DIRECTORY "C:/Users/xkost/source/repos/UnnamedEngine/out/build/x64-Debug/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/libsdl-org/SDL.git'")
endif()

execute_process(
  COMMAND "C:/Program Files/Git/cmd/git.exe"  checkout release-2.0.14 --
  WORKING_DIRECTORY "C:/Users/xkost/source/repos/UnnamedEngine/out/build/x64-Debug/_deps/sdl2-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'release-2.0.14'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"  submodule update --recursive --init 
    WORKING_DIRECTORY "C:/Users/xkost/source/repos/UnnamedEngine/out/build/x64-Debug/_deps/sdl2-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'C:/Users/xkost/source/repos/UnnamedEngine/out/build/x64-Debug/_deps/sdl2-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "C:/Users/xkost/source/repos/UnnamedEngine/extern/SDL2/src/sdl2-populate-stamp/sdl2-populate-gitinfo.txt"
    "C:/Users/xkost/source/repos/UnnamedEngine/extern/SDL2/src/sdl2-populate-stamp/sdl2-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'C:/Users/xkost/source/repos/UnnamedEngine/extern/SDL2/src/sdl2-populate-stamp/sdl2-populate-gitclone-lastrun.txt'")
endif()
