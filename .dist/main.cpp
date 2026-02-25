#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "artistInfo.hpp"
#include "linkedList.hpp"
#include "saveFeatures.hpp"

bool _add_artist(LinkedList* list) {
    std::cout << "Provide the artist's name: \n";
    /* Grab name */
    std::string intakename;
    std::getline(std::cin, intakename);
    // Creates ArtistInfo object and adds it to linkedlist
    if  (!list->createData(list, intakename)) {
        return false;
    }
    std::cout << "Successfully Added !\n";
    return true;
}   

bool _add_album_to_artist(LinkedList* list) {
    std::cout << "Provide the artist's name:\n";
    /* Grab name */
    std::string intakename;
    std::getline(std::cin, intakename);
    /* Pull data from list */
    struct ArtistInfo* temp = list->pullData(intakename);
    /* Error check */
    if(!temp) {
        return false;
    }
    std::cout << "Provide the album's name\n";
    /* Grab name */
    std::getline(std::cin, intakename);
    /* Add album to artistInfo object */
    addAlbum(intakename, temp);
    std::cout << "Album " << intakename << "successfully added to artist !\n";  
    return true;      
}

bool _remove_artist(LinkedList* list) {
    std::cout << "Provide the artist's name:\n";
    /* Grab data */
    std::string intakename;
    std::getline(std::cin, intakename);
    /* Remove data & error check within function */
    if (!list->removeData(intakename)) {
        return false;
    }
    std::cout << "Successfully removed !\n";
    return true;
}

int main(void) {
    LinkedList* list = loadList();
    while(1) {
        std::cout << "Use one of the following commands:  ";
        std::cout << "Add Artist (AA), ";
        std::cout << "Add Album to Artist (AAA), ";
        std::cout << "Remove Artist (RA), ";
        std::cout << "Print (P), ";
        std::cout << "Quit (Q)\n";
        std::string intake;
        std::getline(std::cin, intake);
        
        if(intake == "AA") {
            _add_artist(list);
        } else if(intake == "AAA") {
            _add_album_to_artist(list);
        } else if(intake == "RA") {
            _remove_artist(list);
        } else if(intake == "P") {
            list->printList();
        } else if(intake == "Q") {  
            break;
        }
    }
    saveList(list);
    delete list;
    return 0;
}