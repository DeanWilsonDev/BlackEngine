//
// Created by Dean Wilson on 14/7/2023.
//

#ifndef DAEMON_3D_GAME_ENGINE_DE_MATH_H
#define DAEMON_3D_GAME_ENGINE_DE_MATH_H

#include <vector>
#include <cstdint>

namespace BlackEngine::Math {

  template<class T = double>
  struct Vector2D {
    T x = 0;
    T y = 0;

    Vector2D(): x(0), y(0) {}

    Vector2D(T _x, T _y): x(_x), y(_y) {}

    Vector2D(const Vector2D<T>& v): x(v.x), y(v.y) {}

    Vector2D<T>& operator=(const Vector2D<T>& v) = default;

    explicit operator Vector2D<float>() const { return { static_cast<float>(this->x), static_cast<float>(this->y) }; }

    explicit operator Vector2D<double>() const {
      return { static_cast<double>(this->x), static_cast<double>(this->y) };
    }

    explicit operator Vector2D<int32_t>() const {
      return { static_cast<int32_t>(this->x), static_cast<int32_t>(this->y) };
    }
  };

  template<class T = float>
  struct Vector3D {
    T x, y, z;

    explicit Vector3D(T defaultValue = T()): x(defaultValue), y(defaultValue), z(defaultValue) {};

    Vector3D(T _x, T _y, T _z): x(_x), y(_y), z(_z) {};

    Vector3D(const Vector3D<T>& v): x(v.x), y(v.y), z(v.z) {};
    explicit Vector3D(const T v[3]): x(v[0]), y(v[1]), z(v[2]) {};
};
} // Engine::Math

#endif //DAEMON_3D_GAME_ENGINE_DE_MATH_H
