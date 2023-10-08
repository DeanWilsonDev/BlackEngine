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
#elif DE_PLATFORM_MACOS
  #define DAEMON_ENGINE_API __attribute__((visibility("default")))
#else
  #error Black Engine only supports Windows and MacOS
#endif

namespace BlackEngine {

  class Core {
  public:
    Core();

    virtual ~Core();

  };
}