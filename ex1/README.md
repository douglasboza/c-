# Intro

In this programming project, **IntRanges** you should implement all the items in the assignment.
For each item, create a set of tests to prove that they are correct.

You may also, use the function in the `driver` app, just to demonstrate the function in action.

Therefore, you have to create two targets (executables): the driver (simulating a
cliente using the functions), and the tests (the google tests suite).
But don't worry, they are already set up in the `CMakeLists.txt` script.

# Compiling

This project may be compiled with [CMake](https://cmake.org).
CMake is an open-source, cross-platform family of tools designed to build, test and package software.
Basically, cmake reads a script (`CMakeLists.txt`) with meta-information on the project and **creates a Makefile automatically**, tailored to your system configuration.
After that, you may run the `make` command, as usual.

Alternatively, the same script might be used to create Xcode projects, Ninja, or Microsoft Visual Studio projects, for instance.

To compile this project with [cmake](https://cmake.org) follow these steps:

1. `cd ranges`: enters into the main project directory.
2. `mkdir build`: this creates a new directory in which the compilation output will be stored, including the executable.
3. `cd build`: just moves into the directory created in the step above.
4. `cmake -G "Unix Makefiles" ..`: asks cmake to create the Makefile based on the script found in `CMakeLists.txt`, one level up.
5. `cmake --build .`: triggers the compiling process.
5. `make install`: copies the library to the `lib` directory.

And *voilà*, you have an executable inside the `build` directory.
Also, you will have a library `libIntRanges.a` in which the functions are compiled.

# Running

Just run as usual (assuming `$` is the terminal prompt):

```
$ ./build/driver
```

or

```
$ ./build/run_tests
```
