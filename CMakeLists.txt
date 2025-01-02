cmake_minimum_required(VERSION 3.25)
set(APP RASPBERRY_REMOTE_DEV)
project (${APP})

include_directories(inc)

file(GLOB  SOURCEFILES
           src/*.c)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./../")
add_executable(demo ${SOURCEFILES} )

file(GLOB  SOURCEFILES
           src/*.c)
