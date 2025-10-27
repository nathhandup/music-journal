#ifndef ARTISTINFO
#define ARTISTINFO

#include <string>
#include <vector>

struct ArtistInfo {
    std::string name;
    std::vector<std::string> albums;
};

void printArtistInfo(struct ArtistInfo* obj);
bool addName(std::string string, struct ArtistInfo* obj);
void insert(int point, std::string name, std::vector<std::string> names);
bool addAlbum(std::string string, struct ArtistInfo* obj);

#endif