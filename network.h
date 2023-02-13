#ifndef NETWORK_H
#define NETWORK_H

#include <cstdlib>
#include <string>
#include <map>

#include "connectionlist.h"
//#include "connection.h"

class Connection;

/* A network of different people
   (implement as adjacency list)*/
class Network
{
    public:
    
    Network();
     
    ~Network();

    // adds a person with name name to the network, returns true if successful
    bool add_person(std::string name);
    
    // adds a connection between two people
    bool add_connection(std::string person1, std::string person2);

    // returns true if the network has a person with this name
    bool find(std::string name);

    // get connections of a person in the list if one exists
    ConnectionList get_connections_of(string name);

    // removes person if they exist
    bool remove_person(std::string name);

    // removes connection between person1 and person2 if one exists
    bool remove_connection(std::string person1, std::string person2);

    // finds the shortest number of connections between person1 and person2
    // returns 0 if person1 == person2
    // returns -1 if not possible to connect these people
    int distance(std::string person1, std::string person2);

    private:
    //dict mapping nodes (people) to list of incident edges (their connections)
    std::map<std::string, ConnectionList> incident_edges;

    //vector of edges
    //std::vector<Connection> v; // triggers error "incomplete type is not allowed"
};

#endif