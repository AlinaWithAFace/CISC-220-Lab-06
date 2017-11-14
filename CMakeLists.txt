cmake_minimum_required(VERSION 3.8)
project(CISC_220_Lab_06)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/mainWordHub.cpp
        src/Game.cpp
        src/Game.hpp
        #src/LL.cpp
        #src/LL.hpp
        src/NodeL.cpp
        src/NodeL.hpp
        #src/AVLTree.cpp
        #src/AVLTree.hpp
        src/NodeT.cpp
        src/NodeT.hpp
        src/AVLTree.cpp
        src/AVLTree.hpp
        src/LL.cpp
        src/LL.hpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(CISC_220_Lab_06 ${SOURCE_FILES} src/AVLTree.cpp src/AVLTree.hpp src/LL.cpp src/LL.hpp)