cmake_minimum_required( VERSION 3.25 )
set( APP demo )
project( ${APP} )


set( PROJECT_VER_MAJOR 1 )
set( PROJECT_VER_MINOR 0 )
set( PROJECT_VER_PATCH 0 )
set( PROJECT_VER "${PROJECT_VER_MAJOR}.${PROJECT_VER_MINOR}.${PROJECT_VER_PATCH}" )
set( PROJECT_APIVER "${PROJECT_VER}" )


set( CMAKE_C_STANDARD 11 )
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_C_COMPILER gcc )
set( CMAKE_CXX_COMPILER gcc )

# compiler & linker flags
set( CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-unused-result -Wno-implicit-function-declaration -Wno-implicit-int -Wno-implicit -Wno-implicit-int-float-conversion" )
set( CMAKE_C_FLAGS "-Wall -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable" )
set( CMAKE_C_LD_FLAGS "-l/usr/local/lib -lwiringPi -lwiringPiDev -lpthread -lm" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "./../" )

# Include headers & libraries
include_directories( inc /usr/local/include )
link_directories( ${CMAKE_SOURCE_DIR}/lib /usr/local/lib )

# Add source files
add_definitions(-I/usr/include -L/usr/lib -lwiringPi -lwiringPiDev)
add_executable( ${APP}
        src/main.c
        src/bmp180.c
        src/test_lib_1.c
        src/test_lib_2.c )

# Link against wiringPi
find_library( wiringPi_LIB wiringPi wiringPiDev )
target_link_libraries( ${APP} ${wiringPi_LIB} ${wiringPiDev_LIB})