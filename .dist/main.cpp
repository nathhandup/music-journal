#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "artistinfo.hpp"
#include "linkedlist.hpp"

int main(void) {
    LinkedList* list = new LinkedList;
    while(1) {
        std::cout << "Add Artist, ";
        std::cout << "Add Album to Artist, ";
        std::cout << "Remove Artist, ";
        std::cout << "Print, ";
        std::cout << "Quit\n";
        std::string intake;
        std::cout << "DEBUG: waiting for input...\n" << std::flush;
        std::getline(std::cin, intake);
        
        if(intake == "Add Artist") {
            std::cout << "Artist name?\n";
            std::string intakename;
            std::cout << "DEBUG: waiting for input...\n" << std::flush;
            std::getline(std::cin, intakename);
            struct ArtistInfo* temp = new ArtistInfo;
            addName(intakename, temp);
            list->pushData(temp);
        } else if(intake == "Add Album to Artist") {
            std::cout << "Artist name?\n";
            std::string intakename;
            std::cout << "DEBUG: waiting for input...\n" << std::flush;
            std::getline(std::cin, intakename);
            struct ArtistInfo* temp = list->pullData(intakename);
            if(!temp) {
                continue;
            }
            std::cout << "Album name?\n";
            std::cout << "DEBUG: waiting for input...\n" << std::flush;
            std::getline(std::cin, intakename);
            addAlbum(intakename, temp);

        } else if(intake == "Remove Artist") {
            std::cout << "Artist name?\n";
            std::string intakename;
            std::cout << "DEBUG: waiting for input...\n" << std::flush;
            std::getline(std::cin, intakename);
            list->removeData(intakename);
        } else if(intake == "Print") {
            list->printList();
        } else if(intake == "Quit") {  
            break;
        }
    }
    delete list;
    return 0;
}