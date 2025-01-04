cmake_minimum_required(VERSION 3.25)
set(APP demo)
project (${APP})


SET(PROJECT_VER_MAJOR 1)
SET(PROJECT_VER_MINOR 0)
SET(PROJECT_VER_PATCH 0)
SET(PROJECT_VER "${PROJECT_VER_MAJOR}.${PROJECT_VER_MINOR}.${PROJECT_VER_PATCH}")
SET(PROJECT_APIVER "${PROJECT_VER}")


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER gcc)

# compiler flags
#set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-unused-result -Wno-implicit-function-declaration -Wno-implicit-int -Wno-implicit -Wno-implicit-int-float-conversion")
set ( CMAKE_C_FLAGS "-Wall -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable")


# Link wiringPi
set(CMAKE_EXE_LINKER_FLAGS "-lm -lwiringPi -lwiringPiDev -lpthread")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./../")


# Include headers
include_directories(inc /usr/local/include)

add_executable(${APP}
        src/main.c
        src/bmp180.c)


# Link against wiringPi
find_library(wiringPi_LIB wiringPi)
target_link_libraries(${APP} ${wiringPi_LIB})