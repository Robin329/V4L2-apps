v4l2grab
========

[![Travis](http://img.shields.io/travis/twam/v4l2grab/master.svg)](https://travis-ci.org/twam/v4l2grab/)
[![GitHub license](https://img.shields.io/github/license/twam/v4l2grab.svg)]()

This is a small command line utility for grabbing JPEGs form V4L2 devices (e.g. USB webcams).

For installation, follow the instructions into the [GitHub Wiki](https://github.com/twam/v4l2grab/wiki/Installation).

Try `./v4l2grab -h` or just `v4l2grab` if you have installed it to get some help.

If your webcam works, please add it to the [Compatible Devices](https://github.com/twam/v4l2grab/wiki/Compatible%20Devices) table.

# Installation

1. Install the required libraries (libv4l and libjpeg) and autotools
   Ubuntu/Debian: `sudo apt-get install libjpeg-dev libv4l-dev autoconf automake libtool`
   Gentoo: `emerge -va libjpeg-turbo libv4l`
2. Clone the repository
   `git clone https://github.com/twam/v4l2grab.git`
3. Go into directory
   `cd v4l2grab`
4. Creating autotools files
   `./autogen.sh`
5. Run configure
   `./configure`
6. Run make
   `make`
7. Run make install
   `sudo make install`