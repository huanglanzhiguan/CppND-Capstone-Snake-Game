# Project: Snake Game

## Overview
This is the final project for the Udacity C++ Nanodegree Program. <br>
It's adapted from the Snake Game example provided by the course. <br>
[Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

<img src="snake_game.gif"/>

## New Features
1. **Score**: The game now keep track of the player's score. When the game is started, score history is printed. <br>
   Then player name is requested. Once the game is over, the player's score is saved to a file. <br>

## Rubric Points Addressed
### 1. README
[x] README.md is included. <br>
[x] The README indicates the new features of the project. <br>
[x] The README includes information about each rubric point addressed. <br>

### 2. Compiling and Testing
[x] Use cmake and make to compile the project as it can be seen in the Basic Build Instructions section.

### 3. Loops, Functions, I/O <br>
[x] The project demonstrates an understanding of C++ functions and control structures. <br>
[x] The project reads data from a file and process the data, or the program writes data to a file. <br>
[x] The project accepts user input and processes the input. <br>
`Config` class is used to read player's name and initial speed from terminal. Load and save score history from/to file. <br>
See: `config.cpp`(line 6, line 57), `config.h`

### 4. Object Oriented Programming
[x] One or more classes are added to the project with appropriate access specifiers for class members.
[x] Class constructors utilize member initialization lists.
[x] Classes abstract implementation details from their interfaces.
See: `config.cpp`, `config.h(line 17)`


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
