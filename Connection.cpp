#include "Connection.h"
#include "connectionlist.h"

Connection::Connection(string p1, string p2)
{
    person1 = p1;
    person2 = p2;
    // set up nodes in associated connection lists
    ConnectionList* c1 = network->get_connections_of(p1);
    connect1 = c1->add(this);
    ConnectionList* c2 = network->get_connections_of(p2);
    connect2 = c2->add(this);
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