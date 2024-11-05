#pragma once


#include <string>
#include <vector>

class FileManager {
public:
    FileManager();
    ~FileManager() = default;

    bool readFile(const std::string& filename);
    bool saveFile(const std::string& filename);
    bool deleteFile(const std::string& filename);

    const std::vector<std::string>& getBuffer() const { return buffer; };

private:
    std::vector<std::string> buffer;

};
