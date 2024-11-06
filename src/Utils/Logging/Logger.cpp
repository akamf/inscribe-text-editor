#include "Logger.h"
#include "ConsoleLog.h"


Logger& Logger::instance() {
    static ConsoleLog loggerInstance;
    return loggerInstance;
};
