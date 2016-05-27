# project (project_name)
project (Connexion)

cmake_minimum_required(VERSION 2.6)

file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}" d)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${d}/CMake")
find_package(Imagine)

#ImagineAddExecutable(folder_name main.cpp example.cpp example.h)
 ImagineAddExecutable(Connexion main.cpp Point2D.h Point2D.cpp Simulation.h Simulation.cpp Tools.h Tools.cpp CmdLine.h heap.h heap.cpp heap_T.h)

#ImagineUseModules(folder_name module_name)
 ImagineUseModules(Connexion Graphics)


#add_executable(folder_name main.cpp example.cpp example.h)