//
// Created by Dean on 24/09/2023.
//

#include "Log.h"
#include <memory>

namespace BlackEngine::Logging {

std::shared_ptr<Logger> Log::CoreLogger;
std::shared_ptr<Logger> Log::ClientLogger;

void Log::Init() {

  CoreLogger = std::make_shared<Logger>("BlackEngine", true);
  ClientLogger = std::make_shared<Logger>("SandBox", false);
}

std::shared_ptr<Logger> &Log::GetCoreLogger() { return CoreLogger; }

std::shared_ptr<Logger> &Log::GetClientLogger() { return ClientLogger; }

} // namespace BlackEngine::Logging
