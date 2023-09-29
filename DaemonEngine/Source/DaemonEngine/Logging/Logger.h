//
// Created by Dean Wilson on 27/9/2023.
//

#pragma once

#include <string>
#include <chrono>



namespace DaemonEngine::Logging {

const int DAEMON_LOG_LEVEL_TRACE = 0;
const int DAEMON_LOG_LEVEL_DEBUG = 1;
const int DAEMON_LOG_LEVEL_INFO = 2;
const int DAEMON_LOG_LEVEL_WARN = 3;
const int DAEMON_LOG_LEVEL_ERROR = 4;
const int DAEMON_LOG_LEVEL_FATAL = 5;
const int DAEMON_LOG_LEVEL_OFF = 6;

  enum LogLevel : int {
    Trace = DAEMON_LOG_LEVEL_TRACE,
    Debug = DAEMON_LOG_LEVEL_DEBUG,
    Info = DAEMON_LOG_LEVEL_INFO,
    Warn = DAEMON_LOG_LEVEL_WARN,
    Error = DAEMON_LOG_LEVEL_ERROR,
    Fatal = DAEMON_LOG_LEVEL_FATAL,
    Off = DAEMON_LOG_LEVEL_OFF
  };


    class Logger {

    public:
      Logger(std::string name, bool debugEnabled);
      ~Logger();
      void Log(std::chrono::system_clock::time_point logTime, LogLevel level, std::string_view message);
      bool ShouldLogMessage(LogLevel level) const;
      void LogMessage(std::chrono::system_clock::time_point  logTime, std::string name, LogLevel level, std::string_view message);
      bool GetDebugEnabled() const;
      bool EnableDebugging();
      bool DisableDebugging();
    private:
      std::string sName;
      std::chrono::system_clock dtSystemClock;
      bool bDebugEnabled;

    };


}

