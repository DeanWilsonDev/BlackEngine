//
// Created by Dean on 24/09/2023.
//
#pragma once

#include "Core.h"

namespace DaemonEngine {

  class DAEMON_ENGINE_API Application {
  public:
    Application();

    virtual ~Application();

    void Run();
  };

  // To be defined in the Client
  Application* CreateApplication();

} // DaemonEngine
