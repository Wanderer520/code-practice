cmake_minimum_required(VERSION 4.4.2)
project(Study)

set(CMAKE_CXX_STANDARD 17)

add_executable(Study main.cpp
        hello_world.cpp
        Test.cpp
        Algorithm/Demo1.cpp
        SqList/SqList.c
        LinkedList/LinkedList.c
        SqStack/SqStack.c
        LinkStack/LinkStack.c
        SqQueue/SqQueue.c
        BinaryTree/BinaryTree.c
        "Threaded BinaryTree/InTree.c"
        "Threaded BinaryTree/PreTree.c"
        "Threaded BinaryTree/PostTree.c"
        BST/BST.c
)
