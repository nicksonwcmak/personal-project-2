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
    
}