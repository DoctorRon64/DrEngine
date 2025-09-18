cmake_minimum_required(VERSION 3.10)
project(rapidXML)

# file(GLOB_RECURSE INCLUDE "include/*.hpp")
 add_library(${PROJECT_NAME} INTERFACE ${INCLUDE})

target_include_directories(${PROJECT_NAME} INTERFACE include)
# target_include_directories(${PROJECT_NAME} PRIVATE src)
# INTERFACE = FOR HEADER ONLY LIBRARIES