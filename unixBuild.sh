#!/bin/bash
mkdir -p build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
cp compile_commands.json ../
make && make flash
cd ..
