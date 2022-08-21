#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <Eigen/Eigen>

using namespace Eigen;

struct Transforms {
  Vector3f position;
  Vector3f rotation;
  Vector3f scale;
};

#endif // TRANSFORM_H_
