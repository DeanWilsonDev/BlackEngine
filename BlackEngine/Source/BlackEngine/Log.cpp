//
// Created by Dean on 24/09/2023.
//

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace BlackEngine {

  BlackEngine::Logger Log::CoreLogger;
  BlackEngine::Logger Log::ClientLogger;

  void Log::Init() {

    CoreLogger = BlackEngine::Logger("BlackEngine", true);
    ClientLogger = BlackEngine::Logger("SandBox", false);
  }

  BlackEngine::Logger &Log::GetCoreLogger() {
    return CoreLogger;
  }

  BlackEngine::Logger &Log::GetClientLogger() {
      return ClientLogger;
  }

} // BlackEngine
