//
// Created by Dean Wilson on 27/9/2023.
//
#include "Logger.h"

#include <utility>

namespace DaemonEngine::Logging {

  Logger::Logger(std::string name, bool debugEnabled) {
    sName = std::move(name);
    bDebugEnabled = debugEnabled;
  }

  Logger::~Logger() = default;

  void Logger::Log(std::chrono::system_clock::time_point logTime, LogLevel level, std::string_view message) {
    bool logEnabled = ShouldLogMessage(level);
    // TODO Add tracing?
    if (!logEnabled) {
      return;
    }

    LogMessage(logTime, sName, level, message);
  }

  bool Logger::ShouldLogMessage(LogLevel level) const {
    if (bDebugEnabled) {
      return true;
    }
    return level >= LogLevel::Info;
  }

  bool Logger::EnableDebugging() {
    return bDebugEnabled = true;
  }

  bool Logger::DisableDebugging() {
    return bDebugEnabled = false;
  }

  bool Logger::GetDebugEnabled() const {
    return bDebugEnabled;
  }

  void Logger::LogMessage(std::chrono::system_clock::time_point logTime, std::string name, LogLevel level,
                          std::string_view message) {

  }


}