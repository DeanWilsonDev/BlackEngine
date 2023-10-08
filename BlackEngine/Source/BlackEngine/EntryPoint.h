//
// Created by Dean on 24/09/2023.
//

#pragma once

#ifdef DE_PLATFORM_WINDOWS

extern BlackEngine::Application* BlackEngine::CreateApplication();

int main(int argc, char** argv) {

  BlackEngine::Log::Init();
  DE_CORE_WARN("Initialized Log");
  int a = 5;
  DE_INFO("Welcome to the Sandbox! Var={0}", a);

  auto app = BlackEngine::CreateApplication();
  app->Run();
  delete app;
}

#endif
