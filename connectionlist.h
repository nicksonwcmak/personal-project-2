#ifndef CONNECTIONLIST_H
#define CONNECTIONLIST_H

#include <string>

#include "connection.h"

using std::string;

struct Connection;

struct Node
{
   string name;
   Connection* connection; // pointer to connection in network's connections map
   Node* prev;
   Node* next;
};

// a list of a person's connections
class ConnectionList
{
    public:
    // creates a connection list for this person
    ConnectionList(string per);

    // destructor
    ~ConnectionList();

    // adds given connection to the list and returns the node added
    Node* add(Connection* connection);

    // returns true if there is a connection between these two people
    bool has_connection(string person1, string person2);

    // creates connection and adds it to the list
    // returns false if equivalent connection is already in the list
    // bool add(std::string person1, std::string person2); 

    // removes connection between person1 and person2 from the list
    // returns false if no such connection
    bool remove(string person1, string person2);

    string get_person();

    private:
    // head of the list
    Node* head;

    //person whose connections this list is of
    string person;

    // returns node with given people if one exists in the list
    Node* find(string person1, string person2);
};

#endif