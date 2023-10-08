//
// Created by Dean on 24/09/2023.
//

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace BlackEngine {

  std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
  std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

  void Log::Init() {

    spdlog::set_pattern("%^[%T] %n: %v%$");

    s_CoreLogger = spdlog::stdout_color_mt("DAEMON_ENGINE");
    s_CoreLogger->set_level(spdlog::level::trace);

    s_ClientLogger = spdlog::stdout_color_mt("APP");
    s_ClientLogger->set_level(spdlog::level::trace);
  }

  std::shared_ptr<spdlog::logger> &Log::GetCoreLogger() {
    return s_CoreLogger;
  }

  std::shared_ptr<spdlog::logger> &Log::GetClientLogger() {
    return s_ClientLogger;
  }


} // BlackEngine