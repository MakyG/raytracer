cmake_minimum_required(VERSION 3.12)
project(simple_raytracer VERSION 1.0.0)

add_executable(simple_raytracer Main.cpp Menu.cpp ./raytracer/Raytracer.cpp)
