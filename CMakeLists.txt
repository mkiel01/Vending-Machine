cmake_minimum_required(VERSION 3.25)
project(Vending_Machine)

set(CMAKE_CXX_STANDARD 14)

add_executable(Vending_Machine
        main.cpp
        money.cpp
        product.cpp
        vending_machine.cpp
        )
