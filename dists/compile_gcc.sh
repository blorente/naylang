#!/usr/bin/bash

if [[ $( pwd ) == *"/dists" ]]
then
  cd ..
fi
ROOTDIR=$( pwd )

while [ "$#" -gt 0 ]; do
  case "$1" in
    -o) override="yes"; shift 1;;
    -t) tests="yes"; shift 1;;

    --tests) tests="yes"; shift 1;;
    --override) override="yes"; shift 1;;

    -*) echo "unknown option: $1" >&2; exit 1;;
    *) handle_argument "$1"; shift 1;;
  esac
done

echo "$override"
echo "$tests"

if [ "$override" == "yes" ] ; then
	if [[ -d "bin" ]]
	then
		rm -rf bin
	fi
	mkdir bin
fi

COMPILEDIR="$ROOTDIR/bin"

cd $COMPILEDIR
cmake -G "Unix Makefiles" ..
cmake --build .

if [ "$tests" == "yes" ] ; then
  cd tests
  ./tests
fi
