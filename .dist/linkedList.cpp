#include <iostream>

struct Node {
    void* data;
    Node* next;
    Node(void* val) : data(val), next(NULL) {}
};


class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        while(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(void* value, bool (*compare)(void*, void*)) {
        Node* new_node = new Node(value);
        if(!head) {
            head = new_node;
            return;
        }
        Node* current = head;
        Node* prev = NULL;
        while (current) {
            if(compare(current->data, new_node->data)) {
                new_node->next = current;
                if(prev) {
                    prev->next = new_node;
                }
            }
            prev = current;
            current = current->next;
        }
    }

    void print(void (*func)(void*)) const {
        Node* current = head;
        while (current) {
            func(current->data);
            current = current->next;
        }
        std::cout << "NULL\n";
    }

    bool remove(void* value, bool (*func)(void*, void*)) {
        Node* current = head;
        Node* prev = NULL;
        while(current) {
            if(func(value, current->data)) {
                if(prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }   
};