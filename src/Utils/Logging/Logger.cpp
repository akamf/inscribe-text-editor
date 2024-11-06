#include "Logger.h"
#include "ConsoleLog.h"


constexpr Logger& Logger::instance() {
    static ConsoleLog loggerInstance;
    return loggerInstance;
};
