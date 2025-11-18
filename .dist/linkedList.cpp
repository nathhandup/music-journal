#include <iostream>
#include "artistinfo.hpp"
#include "linkedlist.hpp"

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
}
void LinkedList::pushData(ArtistInfo* value) {
    if(!value) {
        std::cerr << "Error with LinkedList::pushData(ArtistInfo* value): Passed null\n";
        return;
    }
    // Case 1: empty list
    if (head == NULL) {
        head = new Node(value);
        return;
    }

    // Case 2: new node should go before the head
    if (before(value, head->data)) {
        if(value->name == head->data->name) {
            std::cerr << "Error in LinkedList::pushData(ArtistInfo* value): Name Already Exits\n";
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case 3: find proper place to insert in the middle or at end
    Node* current = head;
    while (current->next && !before(value, current->next->data)) {
        current = current->next;
    }
    if(value->name == current->data->name) {
        std::cerr << "Error in LinkedList::pushData(ArtistInfo* value): Name Already Exits\n";
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = current->next;
    current->next = newNode;
}

void LinkedList::printList() const {
    Node* current = head;
    if(!head || !head->data) {
        std::cerr << "Error with LinkedList::printList(): List is null\n";
        return;
    } 
    std::cout << "---------------------\n";
    while (current && current->data) {
        printArtistInfo(current->data);
        current = current->next;
    }
    std::cout << "---------------------\n";
}

bool LinkedList::removeData(std::string value) {
    if (!head) {
        std::cerr << "Error with LinkedList::removeData(ArtistInfo* value): Head is null\n";
        return -1;
    }
    Node* current = head;
    Node* prev = NULL;
    while(current) {
        if(value == current->data->name) {
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
    std::cerr << "Error in LinkedList::removeinfo(std::string value): Cannot find passed value\n";
    return false;
}   

struct ArtistInfo* LinkedList::pullData (std::string value) {
    if(!head) {
        std::cerr << "Error in LinkedList::pullData(std::string value): Head Null\n";
    }
    Node* current = head;
    while(current) {
        if(current->data->name == value) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}
