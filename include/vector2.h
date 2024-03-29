//
//  vector2.h
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
#include <limits> // for std::numeric_limits<>
#include <math.h> // for sqrtf

namespace hydra {

class Vector2
{

public:
  union
  {
    struct
    {
      float x, y;
    };
    float c[2];
  };

  void init();
  void init(float X, float Y);
  void init(float v);
  void init(float* v);
  void init(const Vector2& v);
  static Vector2 Create();
  static Vector2 Create(float X, float Y);
  static Vector2 Create(float v);
  static Vector2 Create(float* v);
  static Vector2 Create(const Vector2& v);

  // Vector2 swizzle getters
  Vector2 yx() const;

  // Vector2 swizzle setters
  void yx(const Vector2& v);

  Vector2 operator +(const Vector2& b) const;
  Vector2 operator -(const Vector2& b) const;
  Vector2 operator +() const;
  Vector2 operator -() const;
  Vector2 operator *(const float v) const;
  Vector2 operator /(const float v) const;

  Vector2& operator +=(const Vector2& b);
  Vector2& operator -=(const Vector2& b);
  Vector2& operator *=(const float v);
  Vector2& operator /=(const float v);

  // Comparison operators are implemented to allow insertion into sorted containers such as std::set
  bool operator >(const Vector2& b) const;
  bool operator <(const Vector2& b) const;

  bool operator ==(const Vector2& b) const;
  bool operator !=(const Vector2& b) const;

  float& operator[](unsigned i);
  float operator[](unsigned i) const;

  float sqrMagnitude() const;
  float magnitude() const;

  void normalize();
  static Vector2 Normalize(const Vector2& v);

  static float Cross(const Vector2& v1, const Vector2& v2);
  static float Dot(const Vector2& v1, const Vector2& v2);
  static Vector2 Min(const Vector2& v1, const Vector2& v2);
  static Vector2 Max(const Vector2& v1, const Vector2& v2);
  static Vector2 Min();
  static Vector2 Max();
  static Vector2 Zero();
  static Vector2 One();
};
static_assert(std::is_pod<Vector2>::value, "hydra::Vector2 must be a POD type.");

} // namespace hydra

namespace std {
template<>
struct hash<hydra::Vector2>
{
public:
  size_t operator()(const hydra::Vector2& s) const
  {
    size_t h1 = hash<float>()(s.x);
    size_t h2 = hash<float>()(s.y);
    return h1 ^ (h2 << 1);
  }
};
} // namespace std
