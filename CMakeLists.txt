cmake_minimum_required(VERSION 3.25)
set(APP demo)
project (${APP})


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./../")


# Include headers
include_directories(inc)

add_executable(${APP}
        src/main.c
        src/bmp180.c)


# Link against wiringPi
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
target_link_libraries(${APP} ${WIRINGPI_LIBRARIES})