#include "network.h"
#include "connectionlist.h"
#include "connection.h"

#include <cstdlib>
#include <string>
#include <map>

using namespace std;

/* creates an empty network
Network::Network() = default;

Network::~Network() {

}*/

bool Network::add_person(string name) {
    incident_edges[name] = new ConnectionList();
    return true;
};

bool Network::add_connection(string person1, string person2) {
    ConnectionList* conn1 = get_connections_of(person1);
    ConnectionList* conn2 = get_connections_of(person2);
    if (conn1->has_connection(person1,person2) || conn2->has_connection(person1,person2)) {
        return false;
    }
    Connection* connect = new Connection(person1,person2);
    // connection constructor adds the nodes: unnecessary dependence?
    edges.push_back(connect);
    return true;
};

bool Network::find(std::string name) {
    // stub: use map iterator
    return false;
};

ConnectionList* Network::get_connections_of(string name) {
    return incident_edges[name];
    // creates a new key if this is not found: try "at" + exception handling?
};

bool Network::remove_person(std::string name) {
    return false; //stub
};

bool Network::remove_connection(std::string person1, std::string person2) {
    return false; //stub
}

int Network::distance(std::string person1, std::string person2) {
    return -1; //stub
}