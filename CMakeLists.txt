cmake_minimum_required (VERSION 3.8)

project ("WrapperEngine")

add_executable (WrapperEngine   "main.cpp" "Arguments.hpp" "Wrapper.hpp" "Engine.hpp" "Subject.hpp")

set_property(TARGET WrapperEngine PROPERTY CXX_STANDARD 20)