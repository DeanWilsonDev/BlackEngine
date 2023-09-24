//
// Created by Dean on 24/09/2023.
//

#pragma once

#include "Application.h"

#ifdef DE_PLATFORM_WINDOWS

extern DaemonEngine::Application* DaemonEngine::CreateApplication();

int main(int argc, char** argv) {
  auto app = DaemonEngine::CreateApplication();
  app->Run();
  delete app;
  return 0;
}

#endif
