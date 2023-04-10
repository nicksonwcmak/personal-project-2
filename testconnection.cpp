#include <iostream>

#include "connection.h"

// simple tests using print statements

/* TODO: fix "v=clang: error: linker command failed with exit code 1"*/

void test_constructor() {
    Connection connect = Connection("TEST1","TEST2",nullptr);
    std::cout << "Person 1: " << connect.person1 << "; Person 2: " << connect.person2 << std::endl;
};

// to compile: 