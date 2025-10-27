
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
    void push_front(void* value);
    void push_back(void* value);
    void print(void (*func)(void*)) const;
    bool remove(void* value);
};