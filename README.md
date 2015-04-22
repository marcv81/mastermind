Scope
=====

This project implements the rules of the Mastermind game. There is no
interface for a human to play, but an implementation of Knuth's algorithm
to win the game in a maximum of 5 turns. The tests verify this claim.

Build
=====

These instructions are given for Ubuntu Trusty.

Build tools
-----------

    sudo apt-get install g++ cmake

GoogleTest
----------

    sudo apt-get install libgtest-dev
    cd /usr/src/gtest
    sudo cmake CMakeLists.txt
    sudo make
    sudo cp *.a /usr/lib

Build
-----

    cmake -H. -Bbuild
    cd build/
    make
    ./runTests

Documentation
-------------

    doxygen Doxyfile
