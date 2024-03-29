//
//  Matrix4.h
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


#include "vector3.h"
#include "vector4.h"

#pragma once

namespace hydra {

enum class AXIS
{
  X_AXIS,
  Y_AXIS,
  Z_AXIS
};

class Quaternion;

class Matrix4
{
public:

  union
  {
    struct
    {
      Vector4 axis_x, axis_y, axis_z, transform;
    };
    // Matrix components, in column-major order
    float c[16];
  };

  // Default initializer - Creates an identity matrix
  void init();

  void init(float* pMat);
  void init(const Vector3& new_axis_x, const Vector3& new_axis_y, const Vector3& new_axis_z, const Vector3& new_transform);
  void init(const Matrix4& m);

  static Matrix4 Create(float* pMat);
  static Matrix4 Create(const Vector3& new_axis_x, const Vector3& new_axis_y, const Vector3& new_axis_z, const Vector3& new_transform);

  // Overload comparison operator
  bool operator==(const Matrix4& m) const;

  // Overload compound multiply operator
  Matrix4& operator*=(const Matrix4& m);

  float& operator[](unsigned i);
  float operator[](unsigned i) const;

  // Overload multiply operator
  //Matrix4& operator*(const Matrix4 &m);
  Matrix4 operator*(const Matrix4& m) const;

  float* getPointer();

  void perspective(float fov, float aspect, float nearz, float farz);
  void ortho(float left, float right, float top, float bottom, float nearz, float farz);
  void translate(float x, float y, float z);
  void translate(const Vector3& v);
  void scale(float x, float y, float z);
  void scale(const Vector3& v);
  void scale(float s);
  void rotate(float angle, AXIS axis);
  void rotate(const Quaternion& q);
  void bias();
  bool invert();
  void transpose();

  static Vector3 DotNoTranslate(const Matrix4& m, const Vector3& v); // Dot product without including translation; useful for transforming normals and tangents
  static Matrix4 Invert(const Matrix4& m);
  static Matrix4 Transpose(const Matrix4& m);
  static Vector3 Dot(const Matrix4& m, const Vector3& v);
  static Vector4 Dot4(const Matrix4& m, const Vector4& v);
  static float DotW(const Matrix4& m, const Vector3& v);
  static Vector3 DotWDiv(const Matrix4& m, const Vector3& v);

  static Matrix4 LookAt(const Vector3& cameraPos, const Vector3& lookAtPos, const Vector3& upDirection);

  static Matrix4 Translation(const Vector3& v);
  static Matrix4 Rotation(const Vector3& v);
  static Matrix4 Scaling(const Vector3& v);
  static Matrix4 Identity();
};
static_assert(std::is_pod<Matrix4>::value, "hydra::Matrix4 must be a POD type.");

} // namespace hydra

namespace std {
template<>
struct hash<hydra::Matrix4>
{
public:
  size_t operator()(const hydra::Matrix4& s) const
  {
    size_t h1 = hash<hydra::Vector4>()(s.axis_x);
    size_t h2 = hash<hydra::Vector4>()(s.axis_y);
    size_t h3 = hash<hydra::Vector4>()(s.axis_z);
    size_t h4 = hash<hydra::Vector4>()(s.transform);
    return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
  }
};
} // namespace std
