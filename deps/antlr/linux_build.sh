#!/usr/bin/env bash
mkdir -p build && mkdir -p run && cd build
cmake ..
make
-DESTDIR=$( pwd )/../run sudo make install
