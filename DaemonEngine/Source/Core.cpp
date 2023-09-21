

#include "Core.h"
namespace DaemonEngine {

  Core::Core() = default;

  Core::~Core() = default;

  bool Core::OnUserCreate() {
    return false;
  }

  bool Core::OnUserUpdate(float deltaTime) {
    return false;
  }

  bool Core::OnUserDestroy() {
    return false;
  }
}