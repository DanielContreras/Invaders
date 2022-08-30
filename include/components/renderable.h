#ifndef RENDERABLE_H_
#define RENDERABLE_H_

#include <Eigen/Eigen>

using namespace Eigen;

struct Renderable {
  Vector3f velocity;
  Vector3f acceleration;
};

#endif // RENDERABLE_H_
