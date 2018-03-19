cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(kraken-math)

set(PUBLIC_HEADERS
  include/aabb.h
  include/hitinfo.h
  include/kraken-math.h
  include/matrix4.h
  include/quaternion.h
  include/scalar.h
  include/triangle3.h
  include/vector2.h
  include/vector3.h
  include/vector4.h
)

set(SRCS
  src/aabb.cpp
  src/hitinfo.cpp
  src/krhelpers.cpp
  src/matrix4.cpp
  src/quaternion.cpp
  src/scalar.cpp
  src/triangle3.cpp
  src/vector2.cpp
  src/vector3.cpp
  src/vector4.cpp
)

add_library(krakenmath STATIC ${SRCS} ${PUBLIC_HEADERS})