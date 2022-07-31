#include <exception>
#include <iostream>

#include "log.h"
#include "sdlwrap/sdlwrap.h"
#include "sdlwrap/texture.h"
#include "utils.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;

int main(int argc, char* args[]) {
  Poopy::Logger::Init();
  try {
    SDLWrap::SDL sdl(SDL_INIT_VIDEO);
    SDLWrap::Window window("GAME v0.0.1", WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDLWrap::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDLWrap::Texture bg(renderer, "res/gfx/bg.png");

    CORE_INFO("Window refresh rate: {}", window.GetRefreshRate());

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
      renderer.Copy(bg, SDL_Rect{0, 0, WIDTH, HEIGHT}, SDL_Rect{0, 0, WIDTH, HEIGHT});
      renderer.Present();

      dt.SetFrameTicks(SDL_GetTicks() - dt.GetStartTicks());
      if (dt.GetFrameTicks() < 1000 / window.GetRefreshRate()) {
        SDL_Delay(1000 / window.GetRefreshRate() - dt.GetFrameTicks());
      }
      // CORE_DEBUG("FPS: {}", dt.GetFPS() / 1000);
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
