//
// Created by Dean Wilson on 27/9/2023.
//
#include "Logger.h"

namespace DaemonEngine::Logging {
    void Logger::Log(LogLevel level, std::string_view message) {
      bool is_log_enabled = ShouldLogMessage(level);
      // Add tracing
      if(!is_log_enabled){
        return;
      }
      
    }


  bool Logger::ShouldLogMessage(LogLevel level) const {
    if(bDebugEnabled){
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

}