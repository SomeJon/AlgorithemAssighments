cmake_minimum_required(VERSION 3.28)
project(AlgorithemAssighments)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlgorithemAssighments src/Main.cpp
        src/Edge.h
        src/Base.h
        src/Graph.h
        src/Vertex.h
        src/main.h
        src/AlgoMethod.h
        src/AlgoMethod.cpp
        src/Adjacent.h
)
