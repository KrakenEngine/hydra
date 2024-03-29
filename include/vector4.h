//
//  Vector4.h
//  Kraken Engine / Hydra
//
//  Copyright 2024 Kearwood Gilbert. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without modification, are
//  permitted provided that the following conditions are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//  conditions and the following disclaimer.
//
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//  of conditions and the following disclaimer in the documentation and/or other materials
//  provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY KEARWOOD GILBERT ''AS IS'' AND ANY EXPRESS OR IMPLIED
//  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
//  FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL KEARWOOD GILBERT OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
//  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//  The views and conclusions contained in the software and documentation are those of the
//  authors and should not be interpreted as representing official policies, either expressed
//  or implied, of Kearwood Gilbert.
//

#pragma once

#include <functional> // for hash<>

namespace hydra {

class Vector3;

class Vector4
{

public:
  union
  {
    struct
    {
      float x, y, z, w;
    };
    float c[4];
  };

  void init();
  void init(float X, float Y, float Z, float W);
  void init(float v);
  void init(float* v);
  void init(const Vector4& v);
  void init(const Vector3& v, float W);
  static Vector4 Create();
  static Vector4 Create(float X, float Y, float Z, float W);
  static Vector4 Create(float v);
  static Vector4 Create(float* v);
  static Vector4 Create(const Vector4& v);
  static Vector4 Create(const Vector3& v, float W);

  Vector4 operator +(const Vector4& b) const;
  Vector4 operator -(const Vector4& b) const;
  Vector4 operator +() const;
  Vector4 operator -() const;
  Vector4 operator *(const float v) const;
  Vector4 operator /(const float v) const;

  Vector4& operator +=(const Vector4& b);
  Vector4& operator -=(const Vector4& b);
  Vector4& operator *=(const float v);
  Vector4& operator /=(const float v);

  bool operator ==(const Vector4& b) const;
  bool operator !=(const Vector4& b) const;

  // Comparison operators are implemented to allow insertion into sorted containers such as std::set
  bool operator >(const Vector4& b) const;
  bool operator <(const Vector4& b) const;

  float& operator[](unsigned i);
  float operator[](unsigned i) const;

  float sqrMagnitude() const; // calculate the square of the magnitude (useful for comparison of magnitudes without the cost of a sqrt() function)
  float magnitude() const;

  void normalize();
  static Vector4 Normalize(const Vector4& v);

  static float Dot(const Vector4& v1, const Vector4& v2);
  static Vector4 Min(const Vector4& v1, const Vector4& v2);
  static Vector4 Max(const Vector4& v1, const Vector4& v2);

  static Vector4 Min();
  static Vector4 Max();
  static Vector4 Zero();
  static Vector4 One();
  static Vector4 Forward();
  static Vector4 Backward();
  static Vector4 Up();
  static Vector4 Down();
  static Vector4 Left();
  static Vector4 Right();
  static Vector4 Lerp(const Vector4& v1, const Vector4& v2, float d);
  static Vector4 Slerp(const Vector4& v1, const Vector4& v2, float d);
  static void OrthoNormalize(Vector4& normal, Vector4& tangent); // Gram-Schmidt Orthonormalization
};
static_assert(std::is_pod<Vector4>::value, "hydra::Vector4 must be a POD type.");

} // namespace hydra

namespace std {
template<>
struct hash<hydra::Vector4>
{
public:
  size_t operator()(const hydra::Vector4& s) const
  {
    size_t h1 = hash<float>()(s.x);
    size_t h2 = hash<float>()(s.y);
    size_t h3 = hash<float>()(s.z);
    size_t h4 = hash<float>()(s.w);
    return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
  }
};
} // namespace std
