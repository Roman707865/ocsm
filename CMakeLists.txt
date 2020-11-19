cmake_minimum_required(VERSION 2.8)

project(temptative_architecture)

add_subdirectory(OSMModule)

include_directories(OSMModule OSMModule/Include OSMModule/Include/Util OSMModule/Include/Data)

add_executable(temptative_architecture main.cpp)

target_link_libraries(temptative_architecture OSMModule)

install(TARGETS temptative_architecture RUNTIME DESTINATION bin)