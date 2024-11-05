#!/bin/bash
mkdir -p build
cd build
cmake -G "Xcode" ..
cmake --build . --config Debug --target Graphics
cmake --build . --config Release --target Graphics
Release/Graphics
