#pragma once

#include <memory>
#include <string>


class Logger {
public:
    virtual ~Logger() = default;

    virtual void log(const std::string& logMessage) const = 0;
    virtual void error(const std::string& logMessage) const = 0;
    virtual void warning(const std::string& logMessage) const = 0;

    static constexpr Logger& instance();

protected:
    Logger() = default;
};
