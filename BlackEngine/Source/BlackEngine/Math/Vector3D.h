#include <cmath>

namespace BlackEngine::Math {

struct Vector3D {
  float x, y, z;

  Vector3D() = default;

  Vector3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z){};

  float &operator[](int i) { return ((&x)[i]); }

  const float &operator[](int i) const { return ((&x)[i]); }

  explicit Vector3D(float defaultValue = float())
      : x(defaultValue), y(defaultValue), z(defaultValue){};

  Vector3D &operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
  }

  Vector3D &operator/=(float s) {
    x /= s;
    y /= s;
    z /= s;
    return *this;
  }

  Vector3D &operator+=(const Vector3D &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  Vector3D &operator-=(const Vector3D &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  Vector3D(const Vector3D &v) : x(v.x), y(v.y), z(v.z){};
  explicit Vector3D(const float v[3]) : x(v[0]), y(v[1]), z(v[2]){};
};

inline Vector3D operator*(const Vector3D &v, float s) {
  return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator/(const Vector3D &v, float s) {
  s = 1.0F / s;
  return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator-(const Vector3D &v) {
  return (Vector3D(-v.x, -v.y, -v.z));
}

inline Vector3D operator+(const Vector3D &v1, const Vector3D &v2) {
  return (Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

inline Vector3D operator-(const Vector3D &v1, const Vector3D &v2) {
  return (Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

inline float Magnitude(const Vector3D &v) {
  return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Normalize(const Vector3D &v) { return (v / Magnitude(v)); }

} // namespace BlackEngine::Math
