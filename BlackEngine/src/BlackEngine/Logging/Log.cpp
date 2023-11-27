//
// Created by Dean on 24/09/2023.
//

#include "Log.h"

namespace BlackEngine::Logging {

std::shared_ptr<Logger> Log::CoreLogger;
std::shared_ptr<Logger> Log::ClientLogger;

void Log::Init() {
  CoreLogger = std::make_shared<Logger>("BlackEngine", true);
  ClientLogger = std::make_shared<Logger>("Client", false);
}

} // namespace BlackEngine::Logging
