#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

int main(void) {
    std::fstream MyFile("data.txt");
    if(MyFile.is_open()) {
        //write to file
        MyFile << "Beginning.\n";
        MyFile.seekg(0);
        std::string line;
        while(std::getline(MyFile, line)) {
            std::cout << line << std::endl;
        }
        MyFile.close();
    } else {
        std::cerr << "Failed to open file. Check existence.\n";
    }
    return 0;
}