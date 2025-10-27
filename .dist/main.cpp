#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "ArtistInfo.h"

int main(void) {
    ArtistInfo* object;
    while(1) {
        std::cout << "addName, addAlbum, print, quit\n";
        std::string intake;
        std::cin >> intake;
        if(intake == "addName") {
            std::cout << "name?\n";
            std::cin >> intake;
            addName(intake, object);
            printArtistInfo(object);
        } else if(intake == "addAlbum") {
            std::cout << "name?\n";
            std::cin >> intake;
            addAlbum(intake, object);
            printArtistInfo(object);
        } else if(intake == "print") {
            printArtistInfo(object);
        } else if(intake == "quit") {
            break;
        }
    }
    return 0;
}