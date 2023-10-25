//
// Created by Dean Wilson on 27/9/2023.
//
#include "Logger.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

namespace BlackEngine::Logging {

Logger::Logger(std::string name, bool debugEnabled) {
  sName = std::move(name);
  bDebugEnabled = debugEnabled;
}

Logger::Logger(std::string name, std::string fileName, bool debugEnabled) {
  sName = std::move(name);
  bDebugEnabled = debugEnabled;
  logfile.open(filename, std::ios::out | std::ios::app);
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

void Logger::log(std::chrono::system_clock::time_point logTime, LogLevel level,
                 std::string_view message) {
  bool logEnabled = shouldLogMessage(level);

  // TODO Add tracing?
  if (!logEnabled) {
    return;
  }

  std::string levelString;
  switch (level) {
  case LogLevel::Trace:
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

    std::time_t now = std::time(0);
    std::tm *timeinfo = std::localtime(&now);
    char timestamp[80];
    std::strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S] ",
                  timeinfo);
    if (logfile.is_open()) {
      logfile << timestamp << levelString << message << std::endl;
    }

    Logger::setColor(level);
    std::cout << timestamp << levelString << message << std::endl;
    Logger::resetColor();
  }
}

bool Logger::shouldLogMessage(LogLevel level) const {
  if (bDebugEnabled) {
    return true;
  }
  return level >= LogLevel::Info;
}

bool Logger::enableDebugging() { return bDebugEnabled = true; }

bool Logger::disableDebugging() { return bDebugEnabled = false; }

bool Logger::getDebugEnabled() const { return bDebugEnabled; }

void Logger::logMessage(std::chrono::system_clock::time_point logTime,
                        std::string name, LogLevel level,
                        std::string_view message) {}

} // namespace BlackEngine::Logging
