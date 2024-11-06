#pragma once

#include "Logger.h"
#include <iostream>


class ConsoleLog : public Logger {
public:
    void log(const std::string& logMessage) const override {
        std::cout << logMessage << std::endl;
    };

    void error(const std::string& logMessage) const override {
        std::cout << "\033[31mERROR\033[0m - " << logMessage << "\n";
    };

    void warning(const std::string& logMessage) const override {
        std::cout << "\033[33mWARNING\033[0m - " << logMessage << "\n";
    };
};
