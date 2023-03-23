cmake_minimum_required(VERSION 3.6)

project(v4l2-apps)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=1)

# add_subdirectory(v4l2grab)
add_subdirectory(v4l2tools)
add_executable(raspi-v4l2-app raspi-v4l2/v4l2-app.c)