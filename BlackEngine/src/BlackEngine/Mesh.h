//
// Created by Dean Wilson on 16/7/2023.
//

#pragma once

#include "Math/Vector3D.h"
#include "blkpch.h"

using namespace BlackEngine::Math;

namespace BlackEngine::Mesh {

  struct Triangle {
    Vector3D vertices[3];

    explicit Triangle(const Vector3D _vertices[3]) {
      for(int i = 0; i < 3; i++){
        vertices[i] = _vertices[i];
      }
    };

    Triangle(const Vector3D v0, const Vector3D v1, const Vector3D v2){
      vertices[0] = v0;
      vertices[1] = v1;
      vertices[2] = v2;
    }
  };

  struct Mesh {
    vector<Triangle> triangles;

    Mesh() = default;

    explicit Mesh(const vector<Triangle>& _triangles): triangles(_triangles) {};
  };

};
