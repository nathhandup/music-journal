#ifndef LINKEDLIST
#define LINKEDLIST
#include "artistinfo.hpp"

// Node structure
struct Node;

// LinkedList structure. Includes:
// push_front(void* value)
// push_back(void* value)
// print(void (*func)(void*)) 
// remove(void* value)
class LinkedList {
public:
    // head with all other nodes stored within
    Node* head;
    // pushes value to linked list and preserves ordering according to compare function
    void pushinfo(ArtistInfo* value);
    // prints linked list
    void printlist() const;
    // removes value according to equality function given
    bool removeinfo(ArtistInfo* value);
};

#endif