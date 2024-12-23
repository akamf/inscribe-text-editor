#include "FileManager.h"
#include "../Utils/Logging/Logger.h"

#include <fstream>
#include <cstdio>
#include <algorithm>


FileManager::FileManager() : textBuffer{} {}

const std::vector<std::string>& FileManager::getTextBuffer() const {
    return textBuffer;
};

const std::vector<TextHandler::Match>& FileManager::getSearchResults() const {
    return textHandler.getMatches();
};

bool FileManager::readFile(const std::string& filename) {
    std:: ifstream file {filename};

    if (!file) {
        Logger::instance().error("Could not open " + filename + ".\n");
        return false;
    }

    textBuffer.clear();
    std::string line;
    while (std::getline(file, line)) {
        textBuffer.push_back(line);
    }
    file.close();

    Logger::instance().log(filename + " loaded successfully!\n");
    return true;
};

bool FileManager::saveFile(const std::string& filename) {
    std::ofstream file {filename};

    if (!file) {
        Logger::instance().error("Could not open " + filename + " for writing.\n");
        return false;
    }

    for (const auto& line : textBuffer) {
        file << line << "\n";
    }
    file.close();

    Logger::instance().log(filename + " saved successfully!.\n");
    return true;
};

bool FileManager::deleteFile(const std::string& filename) {
    if (std::remove(filename.c_str()) != 0) {
        Logger::instance().error("Could not delete " + filename + ".\n");
        return false;
    }

    Logger::instance().log(filename + " deleted successfully.\n");
    return true;
};

bool FileManager::search(const std::string& searchTerm) {
    return textHandler.searchText(textBuffer, searchTerm);
};

bool FileManager::searchAndReplace(const std::string& searchTerm, const std::string& replacement) {
    bool found = textHandler.searchText(textBuffer, searchTerm);

    if (found) {
        textHandler.replaceText(textBuffer, searchTerm, replacement);
    }

    return found;
};