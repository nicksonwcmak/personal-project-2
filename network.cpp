#include "network.h"
#include "connectionlist.h"
#include "connection.h"

#include <cstdlib>
#include <string>
#include <map>

using namespace std;

//creates an empty network
Network::Network() = default;
/*
Network::~Network() {

}*/

bool Network::add_person(string name) {
    incident_edges[name] = new ConnectionList(name);
    return true;
};

bool Network::add_connection(string person1, string person2) {
    ConnectionList* conn1 = get_connections_of(person1);
    ConnectionList* conn2 = get_connections_of(person2);
    if (conn1->has_connection(person1,person2) || conn2->has_connection(person1,person2)) {
        return false;
    }
    Connection* connect = new Connection(person1,person2,this);
    // error: no matching constructor for initialization of 'Connection'
    // candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 3 were provided
    // connection constructor adds the nodes: unnecessary dependence?
    edges.push_back(connect);
    return true;
};

bool Network::find(std::string name) {
    auto lookup = incident_edges.find(name);
    return lookup != incident_edges.end();
};

ConnectionList* Network::get_connections_of(string name) {
    auto lookup = incident_edges.find(name);
    if (lookup != incident_edges.end()) {
        return lookup->second; // the connection list
    } else {
        return nullptr; // nothing found
    }
    // try "at" + exception handling?
};

bool Network::remove_person(std::string name) {
    for (auto it = incident_edges.begin(); it != incident_edges.end();)
    {
        if (it->first == name) {
            ConnectionList* connect = it->second;
            delete connect; // calls ConnectionList destructor
            it->second = nullptr;
            it = incident_edges.erase(it);// will this memory leak??
            return true; 
        } else
            ++it;
    } // using C++ 11, can't use map::extract
    return false; // couldn't find person to delete
};

bool Network::remove_connection(std::string person1, std::string person2) {
    for (auto it  = edges.begin(); it != edges.end();){
        Connection* conn = *it;
        if (conn->person1 == person1 && conn->person2 == person2) {
            edges.erase(it);
            return true;
        } else if (conn->person1 == person2 && conn->person2 == person1) {
            edges.erase(it);
            return true;
        }
    }
    return false;
};

int Network::distance(std::string person1, std::string person2) {
    return -1; // use breadth first search
};