//
// Created by Dean on 24/09/2023.
//

#pragma once

#include <BlackEngine.h>

class Sandbox: public BlackEngine::Application {
public:
  Sandbox();

  ~Sandbox();
};


BlackEngine::Application* BlackEngine::CreateApplication(){
  return new Sandbox();
}