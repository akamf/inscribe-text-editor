#include "FileManager/FileManager.h"
#include "Utils/Logging/Logger.h"

#include <iostream>

// int changed = 0;
// char filename[256] = "";

int main() {
    FileManager FileManager;
    const std::string filename {"Test/test.txt"}; // Local testing
    
    if (FileManager.readFile(filename)) {
        Logger::instance().log("Inside " + filename + ":\n");
        for (const auto&line : FileManager.getBuffer()) {
            Logger::instance().log(line + "\n");
        }
    } else {
        Logger::instance().error("Could not read " + filename + ".\n");
    }

    std::cin.get();
    
    return 0;
};
