//
// Created by Dean Wilson on 27/9/2023.
//

#pragma once

namespace BlackEngine::Logging {

const int BLACK_ENGINE_LOG_LEVEL_TRACE = 0;
const int BLACK_ENGINE_LOG_LEVEL_DEBUG = 1;
const int BLACK_ENGINE_LOG_LEVEL_INFO = 2;
const int BLACK_ENGINE_LOG_LEVEL_WARN = 3;
const int BLACK_ENGINE_LOG_LEVEL_ERROR = 4;
const int BLACK_ENGINE_LOG_LEVEL_FATAL = 5;
const int BLACK_ENGINE_LOG_LEVEL_OFF = 6;

enum LogLevel : int {
  Trace = BLACK_ENGINE_LOG_LEVEL_TRACE,
  Debug = BLACK_ENGINE_LOG_LEVEL_DEBUG,
  Info = BLACK_ENGINE_LOG_LEVEL_INFO,
  Warn = BLACK_ENGINE_LOG_LEVEL_WARN,
  Error = BLACK_ENGINE_LOG_LEVEL_ERROR,
  Fatal = BLACK_ENGINE_LOG_LEVEL_FATAL,
  Off = BLACK_ENGINE_LOG_LEVEL_OFF
};

class Logger {
public:
  Logger(std::string _name, bool _debugEnabled = false);
  Logger(std::string _name, std::string _fileName, bool _debugEnabled = false);
  ~Logger();

  Logger &operator=(const Logger &other) {
    if (this == &other) {
      return *this;
    }

    if (logfile.is_open()) {
      logfile.close();
    }

    std::string newFilename = other.logfile.rdbuf()->getloc().name();
    logfile.open(newFilename, std::ios::out | std::ios::app);

    return *this;
  };

  void log(LogLevel level, std::string_view message);

  void trace(std::string_view message);
  void debug(std::string_view message);
  void info(std::string_view message);
  void warn(std::string_view message);
  void error(std::string_view message);
  void fatal(std::string_view message);

  [[nodiscard]] bool shouldLogMessage(LogLevel level) const;
  [[nodiscard]] bool getDebugEnabled() const;
  bool enableDebugging();
  bool disableDebugging();

private:
  std::string name;
  bool debugEnabled;
  std::ofstream logfile;
  std::string fileName;

  void setColor(LogLevel level);
  void resetColor();
};
} // namespace BlackEngine::Logging
