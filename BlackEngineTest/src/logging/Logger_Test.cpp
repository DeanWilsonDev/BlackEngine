//
// Created by Dean Wilson on 29/9/2023.
//

#include <gtest/gtest.h>
#include <BlackEngine/Logging/Logger.h>

namespace BlackEngine::Logging {
    TEST(LoggerTest, shouldLogMessage) {
        Logger logger("LoggerTest", true);
        logger.log(std::chrono::system_clock::now(), LogLevel::Trace, "Trace Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Debug, "Debug Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Info, "Info Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Warn, "Warn Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Error, "Error Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Fatal, "Fatal Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Off, "Off Message");
    }

    TEST(LoggerTest, getDebugEnabled) {
        Logger logger("LoggerTest", true);
        logger.enableDebugging();
        logger.log(std::chrono::system_clock::now(), LogLevel::Debug, "Debug Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Info, "Info Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Warn, "Warn Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Error, "Error Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Fatal, "Fatal Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Off, "Off Message");
        logger.disableDebugging();
        logger.log(std::chrono::system_clock::now(), LogLevel::Debug, "Debug Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Info, "Info Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Warn, "Warn Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Error, "Error Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Fatal, "Fatal Message");
        logger.log(std::chrono::system_clock::now(), LogLevel::Off, "Off Message");
    }
}
