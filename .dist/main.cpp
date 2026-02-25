#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "artistInfo.hpp"
#include "linkedList.hpp"
#include "saveFeatures.hpp"


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
            std::cout << "Provide the artist's name: \n";
            std::string intakename;
            std::getline(std::cin, intakename);
            struct ArtistInfo* temp = new ArtistInfo;
            addName(intakename, temp);
            list->pushData(temp);
            std::cout << "Successfully Added !\n";
        } else if(intake == "AAA") {
            std::cout << "Provide the artist's name:\n";
            std::string intakename;
            std::getline(std::cin, intakename);
            struct ArtistInfo* temp = list->pullData(intakename);
            if(!temp) {
                continue;
            }
            std::cout << "Provide the album's name\n";
            std::getline(std::cin, intakename);
            addAlbum(intakename, temp);
            std::cout << "Album " << intakename << "successfully added to artist !\n";
        } else if(intake == "RA") {
            std::cout << "Provide the artist's name:\n";
            std::string intakename;
            std::getline(std::cin, intakename);
            list->removeData(intakename);
            std::cout << "Successfully removed !\n";
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