//
//  krhelpers.cpp
//  Kraken Engine / Hydra
//
//  Copyright 2018 Kearwood Gilbert. All rights reserved.
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

#include "krhelpers.h"

#if defined(KRAKEN_USE_OPENGL)

#if defined(DEBUG) || defined(_DEBUG)
#define GLDEBUG(x) \
x; \
{ \
GLenum e; \
while( (e=glGetError()) != GL_NO_ERROR) \
{ \
fprintf(stderr, "Error at line number %d, in file %s. glGetError() returned %i for call %s\n",__LINE__, __FILE__, e, #x ); \
} \
}
#else
#define GLDEBUG(x) x;
#endif

namespace kraken {

void SetUniform(GLint location, const Vector2 &v)
{
  if (location != -1) GLDEBUG(glUniform2f(location, v.x, v.y));
}

void SetUniform(GLint location, const Vector3 &v)
{
  if (location != -1) GLDEBUG(glUniform3f(location, v.x, v.y, v.z));
}

void SetUniform(GLint location, const Vector4 &v)
{
  if (location != -1) GLDEBUG(glUniform4f(location, v.x, v.y, v.z, v.w));
}

void SetUniform(GLint location, const Matrix4 &v)
{
  if (location != -1) GLDEBUG(glUniformMatrix4fv(location, 1, GL_FALSE, v.c));
}

} // namespace kraken

#endif // defined(KRAKEN_USE_OPENGL)