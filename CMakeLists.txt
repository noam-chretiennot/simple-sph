cmake_minimum_required(VERSION 3.16)

project(simple-sph)

include_directories(include)
file(GLOB MAIN 
    "src/*.cpp"
    "include/*.h"
)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(executable ${MAIN})
target_link_libraries(executable PRIVATE sfml-graphics)