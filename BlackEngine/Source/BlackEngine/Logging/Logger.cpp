//
// Created by Dean Wilson on 27/9/2023.
//
#include "Logger.h"

#include <utility>

namespace BlackEngine::Logging {

  Logger::Logger(std::string name, bool debugEnabled) {
    sName = std::move(name);
    bDebugEnabled = debugEnabled;
    logfile.open(filename, std::ios::out | std::ios::app);
    if(!lofgile.is_open()){
        std::cerr << "Error: Could not open log file." << std::endl;
    }
  }

  Logger::~Logger(){
    id(logfile.is_open()) {
        logfile.close();
    }
  };

  void Logger::Log(std::chrono::system_clock::time_point logTime, LogLevel level, std::string_view message) {
    bool logEnabled = ShouldLogMessage(level);
    // TODO Add tracing?
    if (!logEnabled) {
      return;
    }

    std::string levelString;
    switch(level){
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

    if(logfile.is_open()){
      std::time_t now = std::time(0);
      std::tm* timeinfo = std::localtime(&now);
      char timestamp[80];
      std::srtftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S] ", timeinfo);

      logfile << timestamp << levelString << message << std::endl;
    }
    std::cout << timestamp << levelString <<  message << std::endl;
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
