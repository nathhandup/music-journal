#include "ArtistInfo.h"
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

bool addName(const std::string string, struct ArtistInfo* obj) {
    if(obj->name == "") {
        obj->name = string;
        return 1;
    } 
    return 0;
}

void insert_name(const int point, 
            std::string name, 
            std::vector<std::string>* names_pointer) {
    std::string temp1;
    std::string temp2;
    std::vector<std::string> names = *names_pointer;
    if(names.size() == 0) {
        names[0] = name;
        return;
    }
    for(int i = 0; i < names.size() + 1; i++) {
        if(i == point) {
            temp1 = names[i]; // temp 1 takes the value where name is
            names[i] = name; // name is inserted
            i++;
            std::string temp2;
            for(int j = i; j < names.size() + 1; j++) { // names[j] must become temp1
                temp2 = names[j];
                names[j] = temp1;
                temp1 = temp2;
            } //probably works. you should test this moron
            break;
        }
    }
}

bool addAlbum(const std::string string, struct ArtistInfo* obj) {
    std::vector<std::string> objalbums = obj->albums;
    int size = objalbums.size();
    if(size == 0) {
        objalbums[0] = string;
        return 1;
    }
    for(int i = 0; i < size; i++) {
        if(string > objalbums[i]) {
            insert_name(i, string, &objalbums);
            break;
            return 1;
        }
    }
    return 0;
}