cmake_minimum_required(VERSION 3.14)
project(Clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(Clion main.cpp LinkedList.cpp LinkedList.h Contact.cpp Contact.h ContactManager.cpp ContactManager.h Treaps.cpp Treaps.h Error.cpp Error.h)