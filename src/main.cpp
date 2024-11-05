#include "FileManager/FileManager.h"
#include <iostream>


int changed = 0;
char filename[256] = "";

int main() {
    FileManager FileManager;
    const std::string filename {"Test/test.txt"}; // Local testing
    
    if (FileManager.readFile(filename)) {
        std::cout << "Inside " << filename << ":\n";
        for (const auto&line : FileManager.getBuffer()) {
            std::cout << line << "\n";
        }
    } else {
        std::cerr << "Could not read " << filename << ".\n";
    }

    std::cin.get();
    
    return 0;
};
