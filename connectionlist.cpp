#include "connectionlist.h"

ConnectionList::ConnectionList() {
    head = nullptr;
};

// delete the Connection
ConnectionList::~ConnectionList() {
    Node* curr = head;
    while(curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

// returns pointer to connection between given people if one is in the list
// returns nullptr otherwise
Node* ConnectionList::find(std::string person1, std::string person2) {
    Node* curr = head;
    while(curr != nullptr) {
        Connection* connection = curr->connection;
        if (connection->person1 == person1 && connection->person2 == person2) {
            return curr;
        } else if (connection->person2 == person1 && connection->person1 == person2) {
            return curr;
        } else {
            curr = curr->next;
        }
    }
    return nullptr;
};

// adds given connection to the list
// returns false if connection is already in the list
bool ConnectionList::add(Connection* connection){
    if (has_connection(connection->person1,connection->person2)) return false;

    Node* node = new Node();
    node->connection = connection;
    node->prev = nullptr;
    node->next = head;
    head = node; // adds new node at head of list
    return true;
};

// returns true if connection between these two people is in the list
bool ConnectionList::has_connection(string person1, string person2){
    if (find(person1,person2) != nullptr) {
        return true;
    }
    return false;
}

// creates connection and adds it to the list
// returns false if equivalent connection is already in the list
// bool add(std::string person1, std::string person2); 

// removes connection between person1 and person2 from the list
// returns false if no such connection
bool ConnectionList::remove(std::string person1, std::string person2){
    Node* node = find(person1,person2);
    if (node == nullptr) return false;

    Node* left = node->prev;
    Node* right = node->next;
    if (right != nullptr){right->prev = left;} // not end of list
    if (left != nullptr) { // not head of list
        left->next = right;
    } else { // head of list, need to update
        head = right;
    }
    delete node->connection;
    delete node;
    return true;
};