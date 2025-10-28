#ifndef ARTISTINFO_HPP
#define ARTISTINFO_HPP

#include <string>
#include <vector>

struct ArtistInfo {
    std::string name;
    std::vector<std::string> albums;
};

// prints struct ArtistInfo
extern void printArtistInfo(const struct ArtistInfo* obj);
// adds name to struct ArtistInfo
extern bool addName(const std::string line, struct ArtistInfo* obj);
// adds album to struct ArtistInfo
extern bool addAlbum(const std::string line, struct ArtistInfo* obj);
// determines if ArtistInfo possesses given name
extern bool equal(const std::string line, struct ArtistInfo* obj);
// determines if a belongs before b
extern bool before(struct ArtistInfo* a, struct ArtistInfo* b);

#endif