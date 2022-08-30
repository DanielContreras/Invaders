#ifndef GAME_H_
#define GAME_H_

#include <memory>

#include "systems/render_system.h"
#include "core/coordinator.h"
#include "sdlwrap/renderer.h"

using namespace SDLWrap;

class Game {
public:
  Game();
  ~Game();

  void init();

  void handle_events(SDL_Event& event);
  void update(float dt);

  inline bool is_running() { return is_running_; }

private:
  bool is_running_ = true;
  Coordinator coordinator_;
  std::shared_ptr<RenderSystem> render_system_;
};

#endif // GAME_H_
