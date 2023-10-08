//
// Created by Dean on 24/09/2023.
//
#pragma once


#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace BlackEngine {
  class Log {
  public:
    DAEMON_ENGINE_API static void Init();
    DAEMON_ENGINE_API inline static std::shared_ptr<spdlog::logger>& GetCoreLogger();
    DAEMON_ENGINE_API inline static std::shared_ptr<spdlog::logger>& GetClientLogger();
  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };
}

// Core Log Macros
#define DE_CORE_TRACE(...)   ::BlackEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DE_CORE_INFO(...)    ::BlackEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DE_CORE_WARN(...) ::BlackEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DE_CORE_ERROR(...)   ::BlackEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DE_CORE_CRIT(...)   ::BlackEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define DE_TRACE(...)   ::BlackEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DE_INFO(...)    ::BlackEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define DE_WARN(...) ::BlackEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DE_ERROR(...)   ::BlackEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define DE_CRIT(...)   ::BlackEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
