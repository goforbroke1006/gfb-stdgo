#!/usr/bin/env bash

sudo apt-get install -y cmake libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib # copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
