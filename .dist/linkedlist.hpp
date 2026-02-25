#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "artistInfo.hpp"

// Node structure
struct Node {
    ArtistInfo* data;
    Node* next;
    Node(ArtistInfo* val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    // head with all other nodes stored within
    Node* head;
    LinkedList();
    ~LinkedList();
    // pushes value to linked list and preserves ordering
    void pushData(ArtistInfo* value);
    // creates an ArtistInfo object with the given name and adds it to the list, 
    // returns success or failure depending on length of name. 
    bool createData(LinkedList* list, std::string name);
    // prints linked list
    void printList() const;
    // removes value, or does nothing
    bool removeData(std::string value);
    // pulls data. returns null if not found
    struct ArtistInfo* pullData(std::string value);
};

#endif