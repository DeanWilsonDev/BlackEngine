//
// Created by Dean Wilson on 29/9/2023.
//

#include "../../../BlackEngine/Source/BlackEngine/Logging/Logger.h"
#include <gtest/gtest.h>

namespace BlackEngine::Logging {
    TEST(LoggerTest, ShouldLogMessage) {
        Logger logger("LoggerTest", true);
        logger.Log(std::chrono::system_clock::now(), LogLevel::Trace, "Trace Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Debug, "Debug Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Info, "Info Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Warn, "Warn Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Error, "Error Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Fatal, "Fatal Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Off, "Off Message");
    }

    TEST(LoggerTest, GetDebugEnabled) {
        Logger logger("LoggerTest", true);
        logger.EnableDebugging();
        logger.Log(std::chrono::system_clock::now(), LogLevel::Debug, "Debug Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Info, "Info Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Warn, "Warn Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Error, "Error Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Fatal, "Fatal Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Off, "Off Message");
        logger.DisableDebugging();
        logger.Log(std::chrono::system_clock::now(), LogLevel::Debug, "Debug Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Info, "Info Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Warn, "Warn Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Error, "Error Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Fatal, "Fatal Message");
        logger.Log(std::chrono::system_clock::now(), LogLevel::Off, "Off Message");
    }
}
