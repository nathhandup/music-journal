#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "artistinfo.hpp"

int main(void) {
    ArtistInfo* object = new ArtistInfo;
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
    delete object;
    return 0;
}