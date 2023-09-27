//
// Created by Dean Wilson on 27/9/2023.
//

#pragma once

#include <string>



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

      void Log(LogLevel level, std::string_view message);
      bool ShouldLogMessage(LogLevel level) const;
      bool GetDebugEnabled() const;
      bool EnableDebugging();
      bool DisableDebugging();
    private:
      bool bDebugEnabled;
    };


}

