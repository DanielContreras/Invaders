#include <exception>
#include <iostream>
#include <string>

#include "game/game.h"
#include "log.h"
#include "sdlwrap/sdlwrap.h"
#include "utils.h"

using namespace SDLWrap;

int main(int argc, char* args[]) {
  poopy::Logger::init();
  try {
    SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    sdl.init_TTF();
    Window window("Space Invaders", utils::width, utils::height, SDL_WINDOW_SHOWN);
    CORE_INFO("Window refresh rate: {}", window.get_refresh_rate());
    Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

    Game game;
    game.init();

    SDL_Event event;

    utils::LTimer fps_timer;
    utils::LTimer cap_timer;
    int counted_frames = 0;
    fps_timer.start();

    while (game.is_running()) {
      cap_timer.start();
      game.handle_events(event);

      // fps calculation
      int avg_fps = counted_frames / (fps_timer.get_ticks() / 1000.f);
      if (avg_fps > 2000000)
        avg_fps = 0;

      game.update();
      game.render(renderer);

      ++counted_frames;

      // If frame finishes early
      int frame_ticks = cap_timer.get_ticks();
      if (frame_ticks < utils::screen_tick_per_frame)
        SDL_Delay(utils::screen_tick_per_frame - frame_ticks);
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
