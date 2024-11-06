#pragma once


#include <string>
#include <vector>

class FileManager {
public:
    FileManager();
    ~FileManager() = default;

    const std::vector<std::string>& getBuffer() const;

    bool readFile(const std::string& filename);
    bool saveFile(const std::string& filename);
    bool deleteFile(const std::string& filename);

private:
    std::vector<std::string> buffer;

};
