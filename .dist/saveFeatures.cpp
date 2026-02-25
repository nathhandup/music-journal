
#include "saveFeatures.hpp"
#include "linkedList.hpp"
#include "artistInfo.hpp"

bool saveString(const std::string& s, std::ofstream& out) {
    size_t size = s.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));
    out.write(s.data(), size);
    return static_cast<bool>(out);
}

bool saveVectorOfStrings(const std::vector<std::string>& v, std::ofstream& out) {
    size_t vector_length = v.size();
    out.write(reinterpret_cast<const char*>(&vector_length), sizeof(vector_length));
    for(int i = 0; i < (int)vector_length; i++) {
        saveString(v[i], out);
    }
    return static_cast<bool>(out);
}

bool saveList(struct LinkedList* list) {
    std::ofstream out("file.dat", std::ios::binary);
    if(!out) return 0;

    struct Node* iterator = list->head;
    size_t length = 0;
    while (iterator) {
        length++;
        iterator = iterator->next;
    }
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));

    iterator = list->head;
    for(int i = 0; i < length; i++) {
        ArtistInfo* a = iterator->data;
        saveString(a->name, out);
        saveVectorOfStrings(a->albums, out);
        iterator = iterator->next;
    }
    return static_cast<bool>(out);
}
bool loadString(std::string& s, std::ifstream& in) {
    size_t size;
    in.read(reinterpret_cast<char*>(&size), sizeof(size));

    s.resize(size);
    in.read(&s[0], size);

    return static_cast<bool>(in);
}


bool loadVectorOfStrings(std::vector<std::string>& v, std::ifstream& in) {
    size_t length;
    in.read(reinterpret_cast<char*>(&length), sizeof(length));
    
    v.resize(length);

    for (size_t i = 0; i < length; i++) {
        loadString(v[i], in);
    }

    return static_cast<bool>(in);
}


LinkedList* loadList() {
    std::ifstream in("file.dat", std::ios::binary);
    if (!in) {
        LinkedList* list = new LinkedList;
        return list;
    }

    // Create the list
    LinkedList* list = new LinkedList;
    list->head = nullptr;

    size_t length;
    in.read(reinterpret_cast<char*>(&length), sizeof(length));

    // Empty list case
    if (length == 0)
        return list;

    Node* prev = nullptr;

    for (size_t i = 0; i < length; i++) {

        // Allocate one node and its payload
        struct Node* node = new Node(NULL);
        node->data = new ArtistInfo;
        node->next = nullptr;

        // Load fields
        loadString(node->data->name, in);
        loadVectorOfStrings(node->data->albums, in);

        // Insert node into list
        if (list->head == nullptr) {
            list->head = node;
        } else {
            prev->next = node;
        }

        prev = node;
    }

    return list;
}

