//
// Created by Dean on 24/09/2023.
//

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace DaemonEngine {

  std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
  std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

  void Log::Init() {

    spdlog::set_pattern("%^[%T] %n: %v%$");

    Log::s_CoreLogger = spdlog::stdout_color_mt("DAEMON_ENGINE");
    Log::s_CoreLogger->set_level(spdlog::level::trace);

    Log::s_ClientLogger = spdlog::stdout_color_mt("APP");
    Log::s_ClientLogger->set_level(spdlog::level::trace);
  }
} // DaemonEngine