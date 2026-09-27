cmake_minimum_required(VERSION 3.10)
project(dinosaur_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(inc)

add_executable(main
	src/main.cc
	src/mainLoop.cc
	src/handler.cc
	src/cat.cc
)

find_package(SFML REQUIRED COMPONENTS Audio Graphics Window System)
target_link_libraries(main PRIVATE SFML::Audio SFML::Graphics SFML::Window SFML::System)