SquareMat Project

Author: Yair Mandel
Email: yair340@gmail.com

Overview

This project implements a C++ class SquareMat inside the namespace MatrixLib, representing square matrices of real numbers. It supports a wide range of mathematical operations including addition, subtraction, multiplication, scalar operations, transposition, determinant computation, and more.

Structure

SquareMat.hpp – Header file with full class declaration.

SquareMat.cpp – Implementation of all member and friend functions.

Main.cpp – Demonstration of key matrix operations.

Test.cpp – Unit tests using the doctest framework.

Makefile – Build system for running demo, tests, and memory checks.

 Build & Run

Make sure you have g++ and valgrind installed.

Build and run demo:

make makeMain

Run unit tests:

make makeTest

Run memory leak checks:

make makeValgrind

Clean build files:

make makeClean

 Features

Matrix construction from size or 2D vector.

Element access via mat[i][j].

Arithmetic operators: +, -, *, /, %, unary -.

Compound assignment: +=, -=, *=, /=, %=

Comparison: ==, !=, <, <=, >, >= (based on sum of elements).

Transpose: ~mat

Determinant: !mat

Power: mat^n

Increment/Decrement: ++mat, mat++, --mat, mat--

Stream output: std::cout << mat

 Testing

The project uses doctest for unit testing. Each function is tested individually to verify correctness.

 Memory Management

All memory is managed using STL containers (std::vector). There are no raw pointers. The project passes valgrind checks for memory leaks.