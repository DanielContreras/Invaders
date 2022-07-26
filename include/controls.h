#ifndef CONTROLS_H_
#define CONTROLS_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "render_window.h"
#include "system.h"

class Controls {
  // TODO: implement controls
 public:
  // bool HandleInput(RenderWindow& window, Simulation& simulation)
  bool HandleInput(RenderWindow& window, System& system);
};

#endif  // CONTROLS_H_
