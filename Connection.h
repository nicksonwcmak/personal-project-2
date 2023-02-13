#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

#include "connectionlist.h"
#include "network.h"

using std::string;

// represents a connection between two different people 
class Connection
{
private:
    string person1; // first person
    string person2; // second person
    Node* connect1; // pointer to this connection in person 1's connection list
    Node* connect2; // pointer to this connection in person 2's connection list
    Network* network; //network this connection is in
public:
    Connection(string person1, string person2);
    ~Connection();
};

Connection::Connection(string p1, string p2)
{
    person1 = p1;
    person2 = p2;
    // set up nodes in associated connection lists
    Node* connect1 = nullptr;
    Node* connect2 = nullptr; //stubs

    // network.get_connections_of(p1);
};

Connection::~Connection() 
{
    delete connect1; 
    delete connect2;
    // DO NOT delete the entire network...
}

#endif