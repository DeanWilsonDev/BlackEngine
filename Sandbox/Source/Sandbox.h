//
// Created by Dean on 24/09/2023.
//

#pragma once

#include <DaemonEngine.h>

class Sandbox: public DaemonEngine::Application {
public:
  Sandbox();

  ~Sandbox();
};


DaemonEngine::Application* DaemonEngine::CreateApplication(){
  return new Sandbox();
}