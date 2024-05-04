cmake_minimum_required(VERSION 3.28)
project(StructuresAlgos)

set(CMAKE_CXX_STANDARD 20)

add_executable(StructuresAlgos main.cpp
        Array.cpp
        Array.h
        LinkedList.cpp
        LinkedList.h
        Node.cpp
        Node.h
        StringReverser.cpp
        StringReverser.h
        ExpressionChecker.cpp
        ExpressionChecker.h
        Stack.cpp
        Stack.h
        ArrayQueue.cpp
        ArrayQueue.h
        QueueReverser.cpp
        QueueReverser.h
        StackQueue.cpp
        StackQueue.h)
