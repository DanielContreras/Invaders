#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <set>

#include "types.h"

class System {
public:
  std::set<Entity> entities_;
};

#endif // SYSTEM_H_
