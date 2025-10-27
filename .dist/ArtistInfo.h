#ifndef ARTISTINFO
#define ARTISTINFO

#include <string>
#include <vector>

struct ArtistInfo {
    std::string name;
    std::vector<std::string> albums;
};

void printArtistInfo(const struct ArtistInfo* obj);
bool addName(const std::string string, struct ArtistInfo* obj);
void insert(const int point, 
            const std::string name, 
            std::vector<std::string>* names_pointer);
bool addAlbum(const std::string string, struct ArtistInfo* obj);

#endif