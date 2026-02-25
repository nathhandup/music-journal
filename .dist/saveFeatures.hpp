#ifndef SAVEFEATURES_HPP
#define SAVEFEATURES_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>

bool saveString(const std::string& s, std::ofstream& out);
bool saveVectorOfStrings(const std::vector<std::string>& v, std::ofstream& out);
bool saveList(struct LinkedList* list);
bool loadString(std::string& s, std::ifstream& in);
bool loadVectorOfStrings(std::vector<std::string>& v, std::ifstream& in);
LinkedList* loadList();

#endif