# Install script for directory: /home/pi/workspace/V4L2-apps/v4l2tools/libyuv

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/pi/workspace/V4L2-apps/build/v4l2tools/libyuv/libyuv.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libyuv" TYPE FILE FILES
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/basic_types.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/compare.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/convert.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/convert_argb.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/convert_from.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/convert_from_argb.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/cpu_id.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/format_conversion.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/planar_functions.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/rotate.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/rotate_argb.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/row.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/scale.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/scale_argb.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/scale_row.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/version.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/video_common.h"
    "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv/mjpeg_decoder.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/pi/workspace/V4L2-apps/v4l2tools/libyuv/include/libyuv.h")
endif()

