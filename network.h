#ifndef NETWORK_H
#define NETWORK_H

#include <cstdlib>
#include <string>
#include <map>

/* A network of different people*/
class Network
{
    public:
    
    Network();

    // adds a person with name name to the network
    bool add_person(std::string name);

    // adds a connection between 

    private:
    //map storing the connections
    std::map<std::string, int> m;
};

#endif