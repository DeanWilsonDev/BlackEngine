//
// Created by Dean Wilson on 27/9/2023.
//
#include "Logger.h"

namespace BlackEngine::Logging {

Logger::Logger(std::string _name, bool _debugEnabled) {
  name = std::move(_name);
  debugEnabled = _debugEnabled;
}

Logger::Logger(std::string _name, std::string _fileName, bool _debugEnabled) {
  name = std::move(_name);
  debugEnabled = _debugEnabled;
  fileName = _fileName;
  logfile.open(_fileName, std::ios::out | std::ios::app);
  if (!logfile.is_open()) {
    std::cerr << "Error: Could not open log file." << std::endl;
  }
}

Logger::~Logger() {
  if (logfile.is_open()) {
    logfile.close();
  }
};

void Logger::setColor(LogLevel level) {
  switch (level) {
  case LogLevel::Trace:
    std::cout << "\033[0;34m";
    break;
  case LogLevel::Debug:
    std::cout << "\033[0;32m";
    break;
  case LogLevel::Info:
    std::cout << "\033[0;36m";
    break;
  case LogLevel::Warn:
    std::cout << "\033[0;33m";
    break;
  case LogLevel::Error:
    std::cout << "\033[0;31m";
    break;
  case LogLevel::Fatal:
    std::cout << "\033[0;35m";
    break;
  case LogLevel::Off:
    std::cout << "\033[0m";
    break;
  default:
    std::cout << "\033[0m";
    break;
  }
}

void Logger::resetColor() { std::cout << "\033[0m"; }

void Logger::log(LogLevel level, std::string_view message) {
  bool logEnabled = shouldLogMessage(level);

  std::string levelString;
  switch (level) {
  case LogLevel::Trace:
    // TODO: Add tracing?
    levelString = "[TRACE]: ";
    break;
  case LogLevel::Debug:
    levelString = "[DEBUG]: ";
    break;
  case LogLevel::Info:
    levelString = "[INFO]: ";
    break;
  case LogLevel::Warn:
    levelString = "[WARN]: ";
    break;
  case LogLevel::Error:
    levelString = "[ERROR]: ";
    break;
  case LogLevel::Fatal:
    levelString = "[FATAL]: ";
    break;
  case LogLevel::Off:
    levelString = "[OFF]: ";
    break;
  default:
    levelString = "[UNKNOWN]: ";
    break;
  }

  std::time_t now = std::time(0);
  std::tm *timeinfo = std::localtime(&now);
  char timestamp[80];
  std::strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S] ", timeinfo);
  std::string loggerName = "[" + name + "] ";
  if (logfile.is_open()) {
    logfile << timestamp << loggerName << levelString << message << std::endl;
  }

  Logger::setColor(level);
  std::cout << timestamp << loggerName << levelString << message << std::endl;
  Logger::resetColor();
}

bool Logger::shouldLogMessage(LogLevel level) const {
  if (debugEnabled) {
    return true;
  }
  return level >= LogLevel::Info;
}

void Logger::trace(std::string_view message) { log(LogLevel::Trace, message); }
void Logger::debug(std::string_view message) { log(LogLevel::Debug, message); }
void Logger::info(std::string_view message) { log(LogLevel::Info, message); }
void Logger::warn(std::string_view message) { log(LogLevel::Warn, message); }
void Logger::error(std::string_view message) { log(LogLevel::Error, message); }
void Logger::fatal(std::string_view message) { log(LogLevel::Fatal, message); }

bool Logger::enableDebugging() { return debugEnabled = true; }

bool Logger::disableDebugging() { return debugEnabled = false; }

bool Logger::getDebugEnabled() const { return debugEnabled; }

} // namespace BlackEngine::Logging
