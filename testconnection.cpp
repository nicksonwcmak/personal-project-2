#include <iostream>

#include "Connection.h"

using namespace std;

// simple tests using print statements

void test_constructor() {
    Connection connect = Connection("TEST1","TEST2",nullptr);
    cout << "Person 1: " << connect.person1 << "; Person 2: " << connect.person2;
};

void test_set_connect() {
    // stub
}
