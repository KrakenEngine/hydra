#ifndef KRHELPERS_H
#define KRHELPERS_H

#if defined(KRAKEN_USE_OPENGL)

#if defined(_WIN32) || defined(_WIN64)
#include <GL/glew.h>
#elif defined(__linux__) || defined(__unix__) || defined(__posix__)
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>
#elif defined(__APPLE__)
#include <OpenGL/gl3.h>
#include <OpenGL/gl3ext.h>
#endif

#endif // defined(KRAKEN_USE_OPENGL)

#include "../include/hydra.h"

#define KRMIN(x,y) ((x) < (y) ? (x) : (y))
#define KRMAX(x,y) ((x) > (y) ? (x) : (y))
#define KRCLAMP(x, min, max) (KRMAX(KRMIN(x, max), min))
#define KRALIGN(x) ((x + 3) & ~0x03)

float const PI = 3.141592653589793f;
float const D2R = PI * 2 / 360;

#if defined(KRAKEN_USE_OPENGL)
namespace kraken {
  void SetUniform(GLint location, const Vector2 &v);
  void SetUniform(GLint location, const Vector3 &v);
  void SetUniform(GLint location, const Vector4 &v);
  void SetUniform(GLint location, const Matrix4 &v);
} // namespace kraken
#endif // defined(KRAKEN_USE_OPENGL)

#endif
