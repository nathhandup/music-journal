#include "artistInfo.hpp"
#include <iostream>

void printArtistInfo(const struct ArtistInfo* obj) {
    if(!obj) { 
        std::cerr << "Error in printArtistInfo: Passed null\n";
        return;
    }
    std::cout << obj->name << "\n";
    std::vector<std::string> objalbums = obj->albums;
    if(objalbums.size() == 0) {
        std::cout << "|-----------------------------------|\n";
        return;
    } 

    for(int i = 0; i < objalbums.size(); i++) {
        std::cout << "- " << objalbums[i] << "\n";
    }
    std::cout << "|-----------------------------------|\n";
}

bool addName(const std::string line, struct ArtistInfo* obj) {
    if(!obj) { 
        std::cerr << "Error in printArtistInfo: Passed null\n";
        return -1;
    }
    if(obj->name == "") {
        obj->name = line;
        return 1;
    } 
    return 0;
}

bool addAlbum(const std::string line, struct ArtistInfo* obj) {
    if(!obj) { 
        std::cerr << "Error in printArtistInfo: Passed null\n";
        return -1;
    }
    int size = obj->albums.size();
    if(size == 0) {
        obj->albums.push_back(line);
        return 1;
    }
    for(int i = 0; i < size; i++) {
        if(line < obj->albums[i]) {
            obj->albums.insert(obj->albums.begin() + i, line);
            break;
            return 1;
        }
        if(i + 1 == size) {
            obj->albums.push_back(line);
        }
    }
    return 0;
}

bool equal(const std::string line, struct ArtistInfo* obj) {
    if(!obj) { 
        std::cerr << "Error in printArtistInfo: Passed null\n";
        return -1;
    }

    if(line == obj->name) {
        return 1;
    }
    return 0;
}

bool before(struct ArtistInfo* a, struct ArtistInfo* b) {
    if (!a) return true;     // treat null as "before" anything
    if (!b) return false;    // nothing comes before null
    return a->name < b->name;
}