# raytracer
Simple raytracer, compile and run ./a.out in console

Developed with Kate on Linux Ubuntu OS:
Distributor ID:	Ubuntu
Description:	Ubuntu 20.04 LTS
Release:	20.04
Codename:	focal

HOW TO USE THE RAYTRACER:
  - create a directory build: mkdir build
  - locate a directory build: cd build
  - run command: cmake ..
  - run command: cmake --build .
  - run command: ./simple_raytracer
  - in console interface, run Render / Render All
  - open build/output.bmp file with image viewer (GIMP is recommended)

#if you dont have CMake installed:
  - run command: g++ Main.cpp Menu.cpp ./raytracer/Raytracer.cpp
  - run command ./a.out
  - in console interface, run Render / Render All
  - open output.bmp file with image viewer (GIMP is recommended)
  
By Tomáš Makyča 10. 9. 2020
