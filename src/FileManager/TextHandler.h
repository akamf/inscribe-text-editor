#pragma once

#include <string>
#include <vector>


class TextHandler {
public:
    struct Match {
        int lineNumber;
        int position;
    };

    const std::vector<Match>& getMatches() const;

    bool searchText(const std::vector<std::string>& textBuffer, const std::string& searchTerm);
    bool replaceText(std::vector<std::string>& textBuffer, const std::string& searchTerm, const std::string& replacement);

private:
    std::vector<Match> m_matches;
};
