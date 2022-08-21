#ifndef RIGID_BODY_H_
#define RIGID_BODY_H_

#include <Eigen/Eigen>

using namespace Eigen;

struct RigidBody {
  Vector3f velocity;
  Vector3f acceleration;
};

#endif // RIGID_BODY_H_
