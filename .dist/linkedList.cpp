#include <iostream>
#include "artistinfo.hpp"

struct Node {
    ArtistInfo* data;
    Node* next;
    Node(ArtistInfo* val) : data(val), next(NULL) {}
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
            delete temp->data;
            delete temp;
        }
    }

    void pushinfo(ArtistInfo* value) {
        Node* new_node = new Node(value);
        if(!head) {
            head = new_node;
            return;
        }
        Node* current = head;
        Node* prev = NULL;
        while (current) {
            if(before(current->data, new_node->data)) {
                new_node->next = current;
                if(prev) {
                    prev->next = new_node;
                }
            }
            prev = current;
            current = current->next;
        }
    }

    void printlist() const {
        Node* current = head;
        while (current) {
            printArtistInfo(current->data);
            current = current->next;
        }
        std::cout << "NULL\n";
    }

    bool removeinfo(ArtistInfo* value) {
        Node* current = head;
        Node* prev = NULL;
        while(current) {
            if(equal(value->name, current->data)) {
                if(prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current->data;
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }   
};