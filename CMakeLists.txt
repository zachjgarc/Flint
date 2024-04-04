cmake_minimum_required(VERSION 3.10)

project(Flint VERSION 1.0 DESCRIPTION "Flint - lightweight but primitive and brittle" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(flint 
    src/main.cpp
    src/Token.cpp
    src/Lexer.cpp
)