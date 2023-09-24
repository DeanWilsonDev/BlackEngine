//
// Created by Dean Wilson on 14/7/2023.
//

#pragma once

#ifdef DE_PLATFORM_WINDOWS
  #ifdef DE_BUILD_DLL
    #define DAEMON_ENGINE_API __declspec(dllexport)
  #else
    #define DAEMON_ENGINE_API __declspec(dllimport)
  #endif
#else
  #error Daemon Engine only supports windows
#endif

namespace DaemonEngine {

  class Core {
  public:
    Core();

    virtual ~Core();

  };
}