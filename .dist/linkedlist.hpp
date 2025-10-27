#ifndef LINKEDLIST
#define LINKEDLIST

// Node structure
struct Node;
// LinkedList structure. Includes:
// push_front(void* value)
// push_back(void* value)
// print(void (*func)(void*)) 
// remove(void* value)
class LinkedList {
public:
    Node* head;
    void push(void* value, bool (*compare)(void*, void*));
    void print(void (*func)(void*)) const;
    bool remove(void* value, bool (*func)(void*, void*));
};

#endif