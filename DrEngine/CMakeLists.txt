cmake_minimum_required(VERSION 3.10)
project(DrEngine)

file(GLOB_RECURSE SOURCE "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCE})