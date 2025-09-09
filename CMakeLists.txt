cmake_minimum_required(VERSION 3.15)
project(DrEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Remove the version number
find_package(SFML REQUIRED COMPONENTS System Window Graphics Audio Network)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/Components
    ${CMAKE_SOURCE_DIR}/include/Systems
)

file(GLOB_RECURSE ENGINE_SOURCES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(DrEngine ${ENGINE_SOURCES})

target_link_libraries(DrEngine PRIVATE
    SFML::System
    SFML::Window
    SFML::Graphics
    SFML::Audio
    SFML::Network
)
