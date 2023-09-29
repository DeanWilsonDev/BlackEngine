//
// Created by Dean Wilson on 29/9/2023.
//
#pragma once

#include "Logger.h"
#include <doctest.h>

namespace DaemonEngine::Logging {

  TEST_CASE("Returns the output to be logged to the console") {
    Logger logger = *new Logger("EngineLogger", true);
    std::chrono::system_clock::time_point logTime;
    logger.Log(logTime, LogLevel::Info, "Hello World");
    //  delete logger;
  };

}