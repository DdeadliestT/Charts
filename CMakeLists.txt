cmake_minimum_required(VERSION 3.30.1)

project(Graphics LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# MACOSX_BUNDLE
add_executable(Graphics
source/main.cpp
source/IFunction.cpp
source/Parabola.cpp
include/IFunction.h
include/Parabola.h
)

include_directories(
"${CMAKE_SOURCE_DIR}/SFML-2.3.2/include"
"${CMAKE_SOURCE_DIR}/include"
)

link_directories("${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib")

# !!! for Windows operating system in general !!!
if(WIN32)
    target_link_libraries(Graphics
        "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib/win/sfml-graphics.lib"
        "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib/win/sfml-system.lib"
        "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib/win/sfml-window.lib"
    )

# !!! for MacOS X or iOS, watchOS, tvOS (since 3.10.3) !!!
elseif (APPLE)
    target_link_libraries(Graphics
        "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib/macosx/libsfml-graphics.2.3.2.dylib"
        "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib/macosx/libsfml-system.2.3.2.dylib"
        "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib/macosx/libsfml-window.2.3.2.dylib"
    )

# !!! for Linux, BSD, Solaris, Minix !!!
elseif (UNIX AND NOT APPLE)
    target_link_libraries(Graphics
        "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib/linux/libsfml-system.so.2.3.2"
        "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib/linux/libsfml-graphics.so.2.3.2"
        "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib/linux/libsfml-window.so.2.3.2"
    )
endif()

set_target_properties(Graphics PROPERTIES OUTPUT_NAME "Graphics")
