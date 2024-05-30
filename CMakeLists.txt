cmake_minimum_required(VERSION 3.28)
project(AlgorithemAssighments)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlgorithemAssighments src/source/Codes/Main.cpp
        src/source/headers/Edge.h
        src/source/headers/Base.h
        src/source/headers/Graph.h
        src/source/headers/Vertex.h
        src/source/headers/main.h
        src/source/headers/AlgoMethod.h
        src/source/Codes/AlgoMethod.cpp
)
