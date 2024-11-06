#pragma once

#include "TextHandler.h"
#include <string>
#include <vector>


class FileManager {
public:
    FileManager();
    ~FileManager() = default;

    const std::vector<std::string>& getTextBuffer() const;
    const std::vector<TextHandler::Match>& getSearchResults() const;

    bool readFile(const std::string& filename);
    bool saveFile(const std::string& filename);
    bool deleteFile(const std::string& filename);

    bool search(const std::string& searchTerm);
    bool searchAndReplace(const std::string& searchTerm, const std::string& replacement);

private:
    TextHandler textHandler;
    std::vector<std::string> textBuffer;

};
