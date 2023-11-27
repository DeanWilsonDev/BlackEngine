
#pragma once

#if BLACK_ENGINE_PLATFORM_MACOS || BLACK_ENGINE_PLATFORM_WINDOWS
#include "Application.h"
#include "Core.h"
#include "Logging/Log.h"
#include "blkpch.h"
extern BlackEngine::Application *BlackEngine::CreateApplication();

int main(int argc, char **argv) {
  BlackEngine::Logging::Log::Init();
  LOG_CORE_INFO("Initialized Log");
  LOG_DEBUG("Welcome to the Sandbox!");

  std::cout << "Hello World" << std::endl;
  auto app = BlackEngine::CreateApplication();
  app->Run();
  delete app;
}
#endif
