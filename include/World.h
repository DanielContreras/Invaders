#ifndef WORLD_H_
#define WORLD_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "controls.h"
#include "render_window.h"
#include "system.h"

class World {
  // TODO: implement Game
  System system;
  RenderWindow window;
  Controls controls;

 public:
  // bool HandleInput(RenderWindow& window, Simulation& simulation)
  inline void Run() {
    while (controls.HandleInput(window, system)) {
      system.Update();
      window.Render();
    }
  }
};

#endif  // WORLD_H_
