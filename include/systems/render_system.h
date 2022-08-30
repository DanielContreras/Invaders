#ifndef RENDER_SYSTEM_H_
#define RENDER_SYSTEM_H_

#include <memory>

#include "core/system.h"

class RenderSystem : public System {
public:
  void init();
  void update(float dt);

private:
};

#endif // RENDER_SYSTEM_H_
