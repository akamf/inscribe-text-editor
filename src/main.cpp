#include "FileManager/FileManager.h"
#include "Utils/Logging/Logger.h"

#include <iostream>

// int changed = 0;
// char filename[256] = "";

int main() {
    FileManager fileManager;
    const std::string filename = "Test/test.txt";

    // Försök att läsa filen
    if (!fileManager.readFile(filename)) {
        Logger::instance().error("Filen " + filename + " kunde inte hittas.");
        return 1;
    }
    Logger::instance().log("Filen " + filename + " lästes in framgångsrikt.");

    // Testa sökfunktion med en existerande term
    std::string searchTerm = "pojke";
    if (fileManager.search(searchTerm)) {
        Logger::instance().log("Söktermen '" + searchTerm + "' hittades:");
        for (const auto& match : fileManager.getSearchResults()) {
            Logger::instance().log("(rad: " + std::to_string(match.lineNumber) + ", kolumn: " + std::to_string(match.position) + ")");
        }
    } else {
        Logger::instance().warning("Söktermen '" + searchTerm + "' hittades inte i filen.");
    }

    // Testa sökfunktion med en term som inte finns i texten
    std::string missingTerm = "drake";
    if (!fileManager.search(missingTerm)) {
        Logger::instance().warning("Söktermen '" + missingTerm + "' hittades inte i filen.");
    }

    // Testa searchAndReplace med en existerande term
    std::string termToReplace = "magisk";
    std::string replacement = "mystisk";
    if (fileManager.searchAndReplace(termToReplace, replacement)) {
        Logger::instance().log("Ersättning utförd: '" + termToReplace + "' ersattes med '" + replacement + "'.");
    } else {
        Logger::instance().warning("Termen '" + termToReplace + "' hittades inte för ersättning.");
    }

    // Testa searchAndReplace med en term som inte finns
    std::string nonExistentTerm = "ocean";
    std::string nonExistentReplacement = "hav";
    if (!fileManager.searchAndReplace(nonExistentTerm, nonExistentReplacement)) {
        Logger::instance().warning("Termen '" + nonExistentTerm + "' hittades inte för ersättning.");
    }

    // Skriv ut filens innehåll efter ersättningar
    Logger::instance().log("\nInnehåll efter sök och ersättning:");
    for (const auto& line : fileManager.getTextBuffer()) {
        Logger::instance().log(line);
    }

    std::cin.get();

    return 0;
};
