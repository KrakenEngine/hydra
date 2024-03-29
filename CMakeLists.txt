cmake_minimum_required (VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(hydra)

set(PUBLIC_HEADERS
  include/aabb.h
  include/hitinfo.h
  include/hydra.h
  include/matrix2.h
  include/matrix2x3.h
  include/matrix4.h
  include/quaternion.h
  include/scalar.h
  include/triangle3.h
  include/vector2.h
  include/vector3.h
  include/vector4.h
  include/vector2i.h
  include/vector3i.h
)

set(SRCS
  src/aabb.cpp
  src/hitinfo.cpp
  src/matrix2.cpp
  src/matrix2x3.cpp
  src/matrix4.cpp
  src/quaternion.cpp
  src/scalar.cpp
  src/triangle3.cpp
  src/vector2.cpp
  src/vector3.cpp
  src/vector4.cpp
  src/vector2i.cpp
  src/vector3i.cpp
)

add_library(hydra ${SRCS} ${PUBLIC_HEADERS})
SET_TARGET_PROPERTIES(
  hydra
PROPERTIES
  VERSION 0.1.0
  SOVERSION 0.1
  PUBLIC_HEADER "${PUBLIC_HEADERS}"
)

install(
  TARGETS hydra
    LIBRARY
      DESTINATION lib
    ARCHIVE 
      DESTINATION lib
    PUBLIC_HEADER
      DESTINATION include/hydra
)
