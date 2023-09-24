//
// Created by Dean on 24/09/2023.
//
#pragma once


#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace DaemonEngine {

  class DAEMON_ENGINE_API Log {
  public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };

}

// Core log Macros
#define DE_CORE_TRACE(...)   ::DaemonEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DE_CORE_INFO(...)    ::DaemonEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DE_CORE_WARN(...) ::DaemonEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DE_CORE_ERROR(...)   ::DaemonEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DE_CORE_CRIT(...)   ::DaemonEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log Macros
#define DE_TRACE(...)   ::DaemonEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DE_INFO(...)    ::DaemonEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define DE_WARN(...) ::DaemonEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DE_ERROR(...)   ::DaemonEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define DE_CRIT(...)   ::DaemonEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
