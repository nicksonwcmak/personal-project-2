#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

class Network;

#include "connectionlist.h"
#include "network.h"

using std::string;

struct Node;

// represents a connection between two different people 
struct Connection
{
    Network* network; //network this connection is in
    // should nodes be public or private?
    Node* connect1; // pointer to this connection in person 1's connection list
    Node* connect2; // pointer to this connection in person 2's connection list
    string person1; // first person
    string person2; // second person
    Connection(string person1, string person2, Network* net);
    ~Connection();
    bool set_connect1(Node* to_p1);
    bool set_connect2(Node* to_p2);
};

#endif