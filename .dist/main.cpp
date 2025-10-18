#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

// Returns 1 if string exists in file, 0 if not
int stringExists(std::fstream MyFile, std::string str) {
    std::string line;
    while(std::getline(MyFile, line)) {
        if(line == str) {
            return 1;
        }
    }
    return 0;
}

// check if file exists
int checkFile() {
    std::fstream MyFile("data.txt", std::ios::app);
    if(MyFile.is_open()) {
        std::cout << "File opened successfully.\n";
        MyFile.close();
        return 1;
    } else {
        std::cerr << "Failed to open file. Check existence.\n";
        MyFile.close();
        return 0;
    }
}

// wipe file
void wipeFile() {
    std::ofstream MyFile("data.txt", std::ios::trunc);
    MyFile.close();
}

int main(void) {
    // MyFile.tellg() returns current position of file pointer
    // MyFile.seekg(pos) sets the position of the file pointer to pos
    // fstream::beg, fstream::cur, fstream::end 
    checkFile();
    wipeFile();
    std::ofstream MyFile("data.txt", std::ios::app);
    while(1) {
        std::cout << "Enter a string to add to data.txt (or EXIT to quit);\n";
        std::string input;
        std::cin >> input;
        if(input == "EXIT") {
            break;
        } else {;
            MyFile << input << "\n";
        }
        MyFile.flush();
        std::ifstream MyFile("data.txt", std::ios::app);
        std::string line;
        MyFile.seekg(0);
        while(std::getline(MyFile, line)) {
            std::cout << line << "\n";
        }
    }
    MyFile.close();
    return 0;
}