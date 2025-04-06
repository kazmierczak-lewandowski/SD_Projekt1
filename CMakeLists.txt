cmake_minimum_required(VERSION 3.30)
project(SD_Projekt1)

set(CMAKE_CXX_STANDARD 23)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(SD_Projekt1 main.cpp
        ArrayList.cpp
        LinkedList.cpp
        Collection.cpp
)
target_link_libraries(SD_Projekt1 ${CURSES_LIBRARIES})
