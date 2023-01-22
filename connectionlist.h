#ifndef CONNECTIONLIST_H
#define CONNECTIONLIST_H

#include <string>

#include "connection.h"

struct Node
{
   std::string name;
};

// a list of a person's connections
class ConnectionList
{
    public:
    // constructor
    ConnectionList();

    // returns true if connection between given people is in the list
    bool find(std::string person1, std::string person2);

    // adds given connection to the list
    // returns false if connection is already in the list
    bool add(Connection connection);

    // creates connection and adds it to the list
    // returns false if equivalent connection is already in the list
    // bool add(std::string person1, std::string person2); 

    // removes connection between person1 and person2 from the list
    // returns false if no such connection
    bool remove(std::string person1, std::string person2);
};

#endif