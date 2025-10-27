#ifndef ARTISTINFO
#define ARTISTINFO

#include <string>
#include <vector>

struct ArtistInfo {
    std::string name;
    std::vector<std::string> albums;
};

extern void printArtistInfo(const struct ArtistInfo* obj);
extern bool addName(const std::string line, struct ArtistInfo* obj);
extern bool addAlbum(const std::string line, struct ArtistInfo* obj);


#endif