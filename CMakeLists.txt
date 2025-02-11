cmake_minimum_required(VERSION 3.10)

project(Snake)

add_executable(Snake block.h Board.cpp Block.h Food.cpp Food.h
mainGame.cpp Snake.cpp Snake.h Time.h)