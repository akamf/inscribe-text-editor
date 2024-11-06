#include "TextHandler.h"
#include "../Utils/Logging/Logger.h"


const std::vector<TextHandler::Match>& TextHandler::getMatches() const {
    return m_matches;
};

bool TextHandler::searchText(const std::vector<std::string>& textBuffer, const std::string& searchTerm) {
    int lineNumber {1};
    std::string positionMessage {};

    m_matches.clear();
    for (const auto& line : textBuffer) {
        size_t pos = line.find(searchTerm);
        while (pos != std::string::npos) {
            m_matches.push_back({lineNumber, static_cast<int>(pos)});
            pos = line.find(searchTerm, pos + searchTerm.length());
        }
        ++lineNumber;
    }

    if (m_matches.empty()) {
        Logger::instance().warning("Could not find " + searchTerm + " in the text.\n");
        return false;
    }

    Logger::instance().log(searchTerm + " was found at following positions:\n");
    for (const auto& match : getMatches()) {
        positionMessage = "(row: " + std::to_string(match.lineNumber) + ", col: " + std::to_string(match.position) + ")\n";
        Logger::instance().log(positionMessage);
    }
    
    return true;
};

bool TextHandler::replaceText(std::vector<std::string>& textBuffer, const std::string& searchTerm, const std::string& replacement) {
    bool found {false};

    for (auto& line : textBuffer) {
        size_t pos;
        while ((pos = line.find(searchTerm)) != std::string::npos) {
            line.replace(pos, searchTerm.length(), replacement);
            found = true;
        }
    }

    if (!found) {
        Logger::instance().warning("Could not find " + searchTerm + " in the text.\n");
        return false;
    }

    Logger::instance().log(searchTerm + " has successfully been replaced with " + replacement + ".\n");
    return true;
};
