cmake_minimum_required(VERSION 3.24)
project(lab_4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_4 main.cpp App.cpp App.hh hexagon.cpp hexagon.hh circle.hh circle.cpp BaseCObject.hh IDialogInitiable.hh IGeoFig.hh IPhysObject.hh IPrintable.hh Vector2D.hh)
