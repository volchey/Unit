cmake_minimum_required(VERSION 3.9)
project(abstractVM)

set(CMAKE_CXX_STANDARD 11)

add_executable(abstractVM
        main.cpp
        IOperand.hpp
        abstractVM.hpp
        OperandFactory.hpp
        OperandFactory.cpp
        CmdLine.hpp
        CmdLine.cpp
        AbstractVM.cpp
        Operand.hpp
        Operand.cpp)