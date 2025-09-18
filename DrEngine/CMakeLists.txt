cmake_minimum_required(VERSION 3.10)
project(DrEngine)

file(GLOB_RECURSE SOURCE "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

add_subdirectory(libs/SFML-3.0.1)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)

add_subdirectory(libs/rapidXML)
target_link_libraries(${PROJECT_NAME} PRIVATE rapidXML)