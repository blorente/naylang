#!/bin/bash

if [[ $( pwd ) == *"/dists" ]]
then
  cd ..
fi
ROOTDIR=$( pwd )

if [[ -d "bin" ]]
then
  rm -rf bin
fi

mkdir bin
COMPILEDIR="$ROOTDIR/bin"

cd $COMPILEDIR
cmake -G "Unix Makefiles" ..
cmake --build .

echo -n "Run tests? [y/n]: "
read repl
if [ $repl == "y" ] ; then
  cd tests
  ./tests
fi
