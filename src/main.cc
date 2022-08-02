#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include <cstdint>
#include <exception>
#include <iostream>
#include <string>

#include "log.h"
#include "sdlwrap/sdlwrap.h"
#include "utils.h"

const int WIDTH = 1920;
const int HEIGHT = 1080;
const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

int main(int argc, char* args[]) {
  try {
    poopy::Logger::Init();
    SDLWrap::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    sdl.InitTTF();
    SDLWrap::Window window("Space Invaders", WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    CORE_INFO("Window refresh rate: {}", window.GetRefreshRate());
    SDLWrap::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDLWrap::Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

    SDLWrap::Font font("res/fonts/arcade.TTF", 22);
    SDL_Color color{255, 255, 255, 255};
    SDLWrap::Texture text(renderer, font.RenderText_Solid("Hello", color));
    SDL_Rect src_txt{0, 0, text.GetWidth(), text.GetHeight()};
    SDL_Rect dst_txt{5, 5, text.GetWidth(), text.GetHeight()};

    bool app_running = true;

    SDL_Event event;

    utils::LTimer fps_timer;
    utils::LTimer cap_timer;
    int counted_frames = 0;
    std::stringstream fps;
    fps_timer.Start();

    while (app_running) {
      cap_timer.Start();
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
          app_running = false;
        }
      }

      // Frame rate calculation
      int avg_fps = counted_frames / (fps_timer.GetTicks() / 1000.f);
      if (avg_fps > 2000000) avg_fps = 0;

      std::string s = std::to_string(avg_fps).append(" FPS");

      // Update FPS counter texture
      // text.UpdateText(renderer, font, fps.str().c_str(), color);
      text.UpdateText(renderer, font, s, color);

      renderer.Clear();
      renderer.Copy(text, src_txt, dst_txt);
      renderer.Present();

      ++counted_frames;

      // If frame finishes early
      int frame_ticks = cap_timer.GetTicks();
      if (frame_ticks < SCREEN_TICK_PER_FRAME) {
        SDL_Delay(SCREEN_TICK_PER_FRAME - frame_ticks);
      }
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
