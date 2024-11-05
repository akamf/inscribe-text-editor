#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <cstdio>

FileManager::FileManager() : buffer{} {}

bool FileManager::readFile(const std::string& filename) {
    std:: ifstream file {filename};

    if (!file) {
        std::cerr << "Could not open " << filename << ".\n";
        return false;
    }

    buffer.clear();
    std::string line;
    while (std::getline(file, line)) {
        buffer.push_back(line);
    }
    file.close();

    std::cout << filename << " loaded successfully!\n";
    return true;
};

bool FileManager::saveFile(const std::string& filename) {
    std::ofstream file {filename};

    if (!file) {
        std::cerr << "Could not open " << filename << " for writing.\n";
        return false;
    }

    for (const auto& line : buffer) {
        file << line << "\n";
    }
    file.close();

    std::cout << filename << " saved successfully!.\n";
    return true;
};

bool FileManager::deleteFile(const std::string& filename) {
    if (std::remove(filename.c_str()) != 0) {
        std::cerr << "Could not delete " << filename << ".\n";
        return false;
    }

    std::cout << filename << " deleted successfully.\n";
    return true;
};
