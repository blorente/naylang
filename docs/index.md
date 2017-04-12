# Naylang
An interpreter and debugger for the Grace programming language

## What?
Naylang is the new interpreter, runtime and debugger for a subset of the [Grace Programming Language](http://gracelang.org/applications/).
It's still a work in progress, but it has some great capabilites already!

## How?

To use Naylang, just download the executable for the [latest release](https://github.com/blorente/naylang/releases) and start it up in a terminal!

If you'd rather compile it from source [click me!](#Compilation instructions)

### Commands

For now, Naylang accepts three kinds of commands:

- `load` (or `l`) `<path>`: Open the file in `<path>`, execute it, and show the resulting environment.
- `exec `(or `e`) `<code>`: Execute the code and show the resulting environment.
- `print` (or `p`) `<expression>`: Execute the expression and show the result.

Here's an example execution of Naylang:

[![asciicast](https://asciinema.org/a/eqkmros19kzugc2fy96wo8u12.png)](https://asciinema.org/a/eqkmros19kzugc2fy96wo8u12)

## Want to contribute?

Naylang is written entirely in modern C++14. It uses [ANTLR4](https://antlr.org) for parsing, [CMake](https://cmake.org/) as a build system and [Catch](https://github.com/philsquared/Catch) as a testing framework.

If you'd like to contribute to this project, you are more than welcome to. Feel free to [submit an issue](https://github.com/blorente/naylang/issues/new), fork the [main repo](https://github.com/blorente/naylang) and submit a pull request with your improvements, or even shoot me an email (blorente@ucm.es) if you want some direction on where to begin.

### Compilation instructions
Naylang uses standard out-of-source compilation with CMake. It requires at least version 3 of CMake and a compiler that supports C++14 (for example, GCC6.x).
When all the dependencies are installed, and the repo is downloaded, a simple sequence of commands should suffice to run the tests:

```
cd /root/of/repo
mkdir build &6 cd build
cmake ..
make -j antlr4cpp antlr4cpp_generation_naylang
cmake ..
make -j
cd tests
chmod +x ./tests
./tests
```