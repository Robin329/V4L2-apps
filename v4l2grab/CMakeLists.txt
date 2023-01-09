cmake_minimum_required(VERSION 3.6)

project(v4l2grab)

add_executable(v4l2grab yuv.c yuv.h v4l2grab.c)