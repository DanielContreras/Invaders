#include <exception>
#include <iostream>

#include "log.h"
#include "sdlwrap/sdlwrap.h"
#include "utils.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;

int main(int argc, char* args[]) {
  Poopy::Logger::Init();
  try {
    SDLWrap::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDLWrap::Window window("GAME v0.0.1", WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    CORE_INFO("Window refresh rate: {}", window.GetRefreshRate());
    SDLWrap::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDLWrap::Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

    // Test texture
    SDLWrap::Texture bg(renderer, "res/gfx/gradient.jpg");
    SDL_Rect src_rect{0, 0, bg.GetWidth(), bg.GetHeight()};
    SDL_Rect dst_rect{0, 0, window.GetWidth(), window.GetHeight()};
    SDL_Rect dst_rect1{-window.GetWidth(), 0, window.GetWidth(), window.GetHeight()};

    // Test audio
    SDLWrap::Music music("res/sounds/beat.wav");
    SDLWrap::Chunk chunk("res/sounds/scratch.wav");

    bool app_running = true;

    SDL_Event event;

    utils::Timestep dt(0.01f, 0.0f);

    int scrolling_speed = 25;

    while (app_running) {
      dt.start();
      while (dt.GetAccumulator() >= dt.GetTimeStep()) {
        while (SDL_PollEvent(&event)) {
          if (event.type == SDL_QUIT) {
            app_running = false;
          } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
              case SDLK_1:
                mixer.PlayChannel(-1, chunk, 0);
                break;
              case SDLK_2:
                if (mixer.PlayingMusic() == 0) {
                  mixer.PlayMusic(music, -1);
                } else {
                  if (mixer.IsMusicPaused()) {
                    mixer.ResumeMusic();
                  } else {
                    mixer.PauseMusic();
                  }
                }
                break;
              case SDLK_0:
                mixer.HaltMusic();
            }
          }
        }
        dt.SetAccumulator(dt.GetAccumulator() - dt.GetTimeStep());
      }
      // Get our controls and events

      dst_rect1.x += scrolling_speed;
      if (dst_rect1.x >= 0) dst_rect1.x = -WIDTH;

      dst_rect.x += scrolling_speed;
      if (dst_rect.x >= WIDTH) dst_rect.x = 0;

      renderer.Clear();
      renderer.Copy(bg, src_rect, dst_rect);
      renderer.Copy(bg, src_rect, dst_rect1);
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
