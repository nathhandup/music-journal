#include <iostream>

struct Node {
    void* data;
    Node* next;
    Node(void* val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head = NULL;

public:
    ~LinkedList() {
        while(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(void* value) {
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }

    void push_back(void* value) {
        Node* new_node = new Node(value);
        if(!head) {
            head = new_node;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    void print(void (*func)(void*)) const {
        Node* current = head;
        while (current) {
            func(current->data);
            current = current->next;
        }
        std::cout << "NULL\n";
    }

    bool remove(void* value) {
        Node* current = head;
        Node* prev = NULL;
        while(current) {
            if(current->data == value) {
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