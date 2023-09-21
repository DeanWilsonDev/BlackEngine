//
// Created by Dean Wilson on 14/7/2023.
//

#ifndef DAEMON_3D_GAME_ENGINE_DE_CORE_H
#define DAEMON_3D_GAME_ENGINE_DE_CORE_H

#include <string>

using namespace std;

namespace DaemonEngine {

  class Core {
  public:
    Core();

    virtual ~Core();

    // User Override Interfaces
    /// Called once on application startup, use to load your resources
    virtual bool OnUserCreate();

    /// Called every frame, and provides you with deltaTime
    virtual bool OnUserUpdate(float deltaTime);

    /// Called on application termination for code cleanup
    virtual bool OnUserDestroy();


  protected:
    std::wstring m_appName;
    int m_screenWidth{};
    int m_screenHeight{};

  private:
    float m_blendFactor = 1.0f;
  };

}// Engine::Core

#endif //DAEMON_3D_GAME_ENGINE_DE_CORE_H
