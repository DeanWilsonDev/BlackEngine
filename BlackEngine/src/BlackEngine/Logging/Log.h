//
// Created by Dean on 24/09/2023.
//
#pragma once

#include <memory>

#include "../Core.h"
#include "Logger.h"

namespace BlackEngine::Logging {
class Log {
public:
  BLACK_ENGINE_API static void Init();
  BLACK_ENGINE_API inline static std::shared_ptr<Logger> &GetCoreLogger() {
    return CoreLogger;
  };
  BLACK_ENGINE_API inline static std::shared_ptr<Logger> &GetClientLogger() {
    return ClientLogger;
  };

private:
  static std::shared_ptr<Logger> CoreLogger;
  static std::shared_ptr<Logger> ClientLogger;
};
} // namespace BlackEngine::Logging

// Core Log Macros
#define LOG_CORE_TRACE(...)                                                    \
  BlackEngine::Logging::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_DEBUG(...)                                                    \
  BlackEngine::Logging::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define LOG_CORE_INFO(...)                                                     \
  BlackEngine::Logging::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARN(...)                                                     \
  BlackEngine::Logging::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...)                                                    \
  BlackEngine::Logging::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...)                                                    \
  BlackEngine::Logging::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define LOG_TRACE(...)                                                         \
  BlackEngine::Logging::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)                                                         \
  BlackEngine::Logging::Log::GetClientLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...)                                                          \
  BlackEngine::Logging::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)                                                          \
  BlackEngine::Logging::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)                                                         \
  BlackEngine::Logging::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)                                                         \
  BlackEngine::Logging::Log::GetClientLogger()->fatal(__VA_ARGS__)
