#include <SDL2/SDL_timer.h>

#include <exception>
#include <iostream>

#include "sdlwrap/sdlwrap.h"
#include "spdlog/spdlog.h"
#include "utils.h"

int main(int argc, char* args[]) {
  try {
    SDLWrap::SDL sdl(SDL_INIT_VIDEO);
    SDLWrap::Window window("GAME v0.0.1", 1280, 720, SDL_WINDOW_SHOWN);
    SDLWrap::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    spdlog::info("Current refresh rate: {}", window.GetRefreshRate());

    bool app_running = true;

    SDL_Event event;

    utils::Timestep dt(0.01f, 0.0f);

    while (app_running) {
      dt.start();
      while (dt.GetAccumulator() >= dt.GetTimeStep()) {
        while (SDL_PollEvent(&event)) {
          if (event.type == SDL_QUIT) app_running = false;
        }
        dt.SetAccumulator(dt.GetAccumulator() - dt.GetTimeStep());
      }
      // Get our controls and events
      renderer.Clear();
      renderer.Copy();
      renderer.Present();

      dt.SetFrameTicks(SDL_GetTicks() - dt.GetStartTicks());
      if (dt.GetFrameTicks() < 1000 / window.GetRefreshRate()) {
        SDL_Delay(1000 / window.GetRefreshRate() - dt.GetFrameTicks());
      }
      // spdlog::info("Current refresh rate: {}", dt.GetFPS());
    }
    return 0;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}
