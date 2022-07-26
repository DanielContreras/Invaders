#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "system.h"
#include "render_window.h"
#include "controls.h"

class World {
  // TODO: implement Game
  System system;
  RenderWindow window;
  Controls controls;
 public:
   // bool HandleInput(RenderWindow& window, Simulation& simulation)
  inline void Run() {
    while(controls.HandleInput(window, system)) {
      system.Update();
      window.Render();
    }
  } 
};

#endif  // GAME_H_
