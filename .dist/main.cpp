#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "artistinfo.hpp"
#include "linkedlist.hpp"

int main(void) {

    ArtistInfo* object = new ArtistInfo;
    // test shell for artistinfo.cpp
    while(0) {
        std::cout << "addName, addAlbum, print, quit\n";
        std::string intake;
        std::getline(std::cin, intake);
        if(intake == "addName") {
            std::cout << "Name?\n";
            std::getline(std::cin, intake);
            if(!addName(intake, object)) {
                std::cout << "Failed to add name. Already exists\n";
            }
            printArtistInfo(object);
        } else if(intake == "addAlbum") {
            std::cout << "Album name?\n";
            std::getline(std::cin, intake);
            addAlbum(intake, object);
            printArtistInfo(object);
        } else if(intake == "print") {
            printArtistInfo(object);
        } else if(intake == "quit") {
            break;
        }
    }
    delete object;

    LinkedList* list = new LinkedList;
    ArtistInfo* obj1 = new ArtistInfo;
    ArtistInfo* obj2 = new ArtistInfo;
    addName("Nathan", obj1);
    addAlbum("Crimson", obj1);
    addName("Daniel", obj2);
    addAlbum("Cake", obj2);
    list->pushinfo(obj1);
    list->pushinfo(obj2);
    list->printlist();
    delete list;

    return 0;
}