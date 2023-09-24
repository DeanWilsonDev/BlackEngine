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

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
  private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
  };

}
