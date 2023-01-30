#ifndef CONNECTIONLIST_H
#define CONNECTIONLIST_H

#include <string>

// represents a connection between two different people
struct Connection
{
    std::string person1;
    std::string person2;
    // std:: string desc;
};


struct Node
{
   std::string name;
   Connection* connection; // pointer to connection in network's connections map
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