#include <SDL2/SDL_timer.h>

#include <cstdint>
#include <exception>
#include <iostream>

#include "log.h"
#include "sdlwrap/sdl.h"
#include "sdlwrap/sdlwrap.h"
#include "utils.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;
const int SCREEN_FPS = 100;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

int main(int argc, char* args[]) {
  poopy::Logger::Init();
  try {
    SDLWrap::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    sdl.InitTTF();
    SDLWrap::Window window("GAME v0.0.1", WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    CORE_INFO("Window refresh rate: {}", window.GetRefreshRate());
    SDLWrap::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDLWrap::Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

    // Test texture
    SDLWrap::Texture bg(renderer, "res/gfx/gradient.jpg");
    SDL_Rect src_rect{0, 0, bg.GetWidth(), bg.GetHeight()};
    SDL_Rect dst_rect{0, 0, window.GetWidth(), window.GetHeight()};
    SDL_Rect dst_rect1{-window.GetWidth(), 0, window.GetWidth(), window.GetHeight()};

    // Test fonts
    SDLWrap::Font font("res/fonts/lazy.ttf", 28);

    // Test audio
    SDLWrap::Music music("res/sounds/beat.wav");
    SDLWrap::Chunk chunk("res/sounds/scratch.wav");

    bool app_running = true;

    SDL_Event event;

    utils::LTimer fps_timer;
    utils::LTimer cap_timer;
    int counted_frames = 0;
    std::stringstream time_text;
    fps_timer.Start();

    // Scrolling speed of test background
    int scrolling_speed = 10;

    while (app_running) {
      cap_timer.Start();
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
              break;
            case SDLK_SPACE:
              if (scrolling_speed != 0)
                scrolling_speed = 0;
              else
                scrolling_speed = 10;
              break;
          }
        }
      }

      // Frame rate calculation
      int avg_fps = counted_frames / (fps_timer.GetTicks() / 1000.f);
      if (avg_fps > 2000000) {
        avg_fps = 0;
      }

      // FPS texture creation
      time_text.str("");
      time_text <<  avg_fps << " FPS";
      SDLWrap::Texture* text = new SDLWrap::Texture(
          renderer, font.RenderText_Solid(time_text.str(), SDL_Color{255, 255, 255, 255}));
      SDL_Rect src_txt{0, 0, text->GetWidth(), text->GetHeight()};
      SDL_Rect dst_txt{5, 5, text->GetWidth(), text->GetHeight()};

      // Scrolling background test stuff
      dst_rect1.x += scrolling_speed;
      if (dst_rect1.x >= 0) dst_rect1.x = -WIDTH;

      dst_rect.x += scrolling_speed;
      if (dst_rect.x >= WIDTH) dst_rect.x = 0;

      renderer.Clear();
      renderer.Copy(bg, src_rect, dst_rect);
      renderer.Copy(bg, src_rect, dst_rect1);
      renderer.Copy(*text, src_txt, dst_txt);
      renderer.Present();

      // Delete FPS texture object
      delete text;

      ++counted_frames;

      // If frame finishes early
      int frame_ticks = cap_timer.GetTicks();
      if (frame_ticks < SCREEN_TICK_PER_FRAME) {
        SDL_Delay(SCREEN_TICK_PER_FRAME - frame_ticks);
      }
    }
    // sdl.QuitTTF();
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
