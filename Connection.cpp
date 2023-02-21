#include "Connection.h"
#include "connectionlist.h"

Connection::Connection(string p1, string p2)
{
    person1 = p1;
    person2 = p2;
    // set up nodes in associated connection lists
    Node* connect1 = nullptr;
    Node* connect2 = nullptr;
    
};

Connection::~Connection() 
{
    delete connect1; 
    delete connect2;
};

bool Connection::set_connect1(Node* to_p1) {
    connect1 = to_p1;
};

bool Connection::set_connect2(Node* to_p2) {
    connect2 = to_p2;
};