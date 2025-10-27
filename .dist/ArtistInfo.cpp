#include "artistinfo.hpp"
#include <iostream>

void printArtistInfo(const struct ArtistInfo* obj) {
    std::cout << obj->name << "\n";
    std::vector<std::string> objalbums = obj->albums;
    if(objalbums.size() == 0) {
        return;
    } 

    for(int i = 0; i < objalbums.size(); i++) {
        std::cout << "- " << objalbums[i] << "\n";
    }
}

bool addName(const std::string line, struct ArtistInfo* obj) {
    if(obj->name == "") {
        obj->name = line;
        return 1;
    } 
    return 0;
}

bool addAlbum(const std::string line, struct ArtistInfo* obj) {
    std::vector<std::string> objalbums = obj->albums;
    int size = objalbums.size();
    if(size == 0) {
        objalbums.push_back(line);
        return 1;
    }
    for(int i = 0; i < size; i++) {
        if(line < objalbums[i]) {
            objalbums.insert(objalbums.begin() + i, line);
            break;
            return 1;
        }
    }
    return 0;
}