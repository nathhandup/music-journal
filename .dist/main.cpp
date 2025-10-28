#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "artistinfo.hpp"
#include "linkedlist.hpp"

int main(void) {
    if(1) {
        LinkedList* list = new LinkedList;
        ArtistInfo* obj1 = new ArtistInfo;
        ArtistInfo* obj2 = new ArtistInfo;
        addName("Nathan", obj1);
        addAlbum("Crimson", obj1);
        addName("Daniel", obj2);
        addAlbum("Cake", obj2);
        list->pushinfo(obj1);
        list->pushinfo(obj2);
        list->printlist();
        list->removeinfo("Nathan");
        list->printlist();
        list->removeinfo("Daniel");
        list->printlist();
        list->removeinfo("Daniel");
        list->printlist();
        delete list;
    }

    return 0;
}