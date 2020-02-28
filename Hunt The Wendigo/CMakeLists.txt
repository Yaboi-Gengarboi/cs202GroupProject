cmake_minimum_required(VERSION 3.16)
project(wendigo)

# Can manually add the sources using the set command as follows:
set(SOURCES HTW_main_file.cpp lib/tilemap.cpp)

add_executable(wendigo ${SOURCES})

# Find SFML
find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

target_link_libraries(wendigo
  sfml-graphics sfml-system
)
