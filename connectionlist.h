#ifndef CONNECTIONLIST_H
#define CONNECTIONLIST_H

#include <string>

using std::string;

// represents a connection between two different people 
struct Connection
{
    string person1;
    string person2;
    // std:: string desc;
};


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
    // creates an empty connection list
    ConnectionList();

    // destructor
    ~ConnectionList();

    // adds given connection to the list
    // returns false if connection is already in the list
    bool add(Connection* connection);

    // returns true if there is a connection between these two people
    bool has_connection(string person1, string person2);

    // creates connection and adds it to the list
    // returns false if equivalent connection is already in the list
    // bool add(std::string person1, std::string person2); 

    // removes connection between person1 and person2 from the list
    // returns false if no such connection
    bool remove(string person1, string person2);

    private:
    // head of the list
    Node* head;

    // returns node with given people if one exists in the list
    Node* find(string person1, string person2);

    // helper for destructor
    // removes the head of the list
    void remove_head();
};

#endif