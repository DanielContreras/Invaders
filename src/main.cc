#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_timer.h>

#include <vector>

#include "entity.h"
#include "render_window.h"
#include "spdlog/spdlog.h"
#include "utils.h"

int main(int argc, char* args[]) {
  if (SDL_Init(SDL_INIT_VIDEO) > 0)
    SDL_Log("SDL_Init has failed. Error: %s", SDL_GetError());

  if (!(IMG_Init(IMG_INIT_PNG)))
    SDL_Log("IMG_init has failed. Error: %s", SDL_GetError());

  RenderWindow window("GAME v0.0.1", 1280, 720);
  spdlog::info("Current refresh rate: {}", window.GetRefreshRate());

  bool game_running = true;

  SDL_Event event;

  // time_step is refresh rate (0.01 is 100 fps)
  const float time_step = 0.01f;
  // This is the counter in between steps
  float accumulator = 0.0f;
  float current_time = utils::HireTimeInSeconds();

  while (game_running) {
    int start_ticks = SDL_GetTicks();
    float new_time = utils::HireTimeInSeconds();
    float frame_time = new_time - current_time;
    current_time = new_time;
    accumulator += frame_time;
    while (accumulator >= time_step) {
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) game_running = false;
      }
      accumulator -= time_step;
    }
    // const float alpha = accumulator / time_step;
    // Get our controls and events
    window.Clear();
    window.Render();
    window.Display();

    int frame_ticks = SDL_GetTicks() - start_ticks;
    if (frame_ticks < 1000 / window.GetRefreshRate()) {
      SDL_Delay(1000 / window.GetRefreshRate() - frame_ticks);
    }
  }

  window.CleanUp();
  SDL_Quit();

  return 0;
}
