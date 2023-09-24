//
// Created by Dean on 24/09/2023.
//

#pragma once

#ifdef DE_PLATFORM_WINDOWS

extern DaemonEngine::Application* DaemonEngine::CreateApplication();

int main(int argc, char** argv) {

  DaemonEngine::Log::Init();

  DaemonEngine::Log::GetCoreLogger()->warn("Initialized Log");
  DaemonEngine::Log::GetClientLogger()->info("Hello!");

  auto app = DaemonEngine::CreateApplication();
  app->Run();
  delete app;

  return 0;
}

#endif
