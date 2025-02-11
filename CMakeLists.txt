cmake_minimum_required(VERSION 3.10)

project(Snake)

include_directories(./EasyX/include)
link_directories(./EasyX/lib64)
link_libraries(libeasyx.a)

add_executable(Snake block.h Board.cpp Block.h Food.cpp Food.h
mainGame.cpp Snake.cpp Snake.h Time.h easyx.h)