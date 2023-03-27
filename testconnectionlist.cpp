#include <iostream>

#include "connectionlist.h"

using namespace std;

void testconstructor() {
    ConnectionList conn = ConnectionList("TEST");
    cout << conn.get_person() << endl; // expect: TEST
};