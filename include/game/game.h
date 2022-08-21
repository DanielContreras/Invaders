#ifndef GAME_H_
#define GAME_H_

#include "core/coordinator.h"
#include "sdlwrap/renderer.h"

using namespace SDLWrap;

class Game {
public:
  Game();
  ~Game();

  void init();

  void handle_events(SDL_Event& event);
  void update();
  void render(Renderer& renderer);

  inline bool is_running() { return is_running_; }

private:
  bool is_running_ = true;
  Coordinator coordinator_;
};

#endif // GAME_H_
