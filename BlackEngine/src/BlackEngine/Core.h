//
// Created by Dean Wilson on 14/7/2023.
//

#pragma once

#ifdef BLACK_ENGINE_PLATFORM_WINDOWS
#ifdef BLACK_ENGINE_BUILD_DLL
#define BLACK_ENGINE_API __declspec(dllexport)
#else
#define BLACK_ENGINE_API __declspec(dllimport)
#endif
#elif BLACK_ENGINE_PLATFORM_MACOS
#define BLACK_ENGINE_API __attribute__((visibility("default")))
#else
#pragma message("Platform unspecified. Defaulting to Mac build")
#define BLACK_ENGINE_PLATFORM_MACOS = 1
#define BLACK_ENGINE_API __attribute__((visibility("default")))
#endif

namespace BlackEngine {

class Core {
public:
  Core();

  virtual ~Core();
};
} // namespace BlackEngine
