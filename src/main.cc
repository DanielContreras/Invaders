#include <exception>
#include <iostream>
#include <string>

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
    Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

    Font font("res/fonts/arcade.TTF", 28);
    SDL_Color color{255, 255, 255, 255};
    Texture text(renderer, font.render_text_solid("oh", color));
    SDL_Rect src_txt{0, 0, text.get_width(), text.get_height()};
    SDL_Rect dst_txt{5, 5, text.get_width(), text.get_height()};

    // Test audio
    SDLWrap::Music music("res/sfx/si/ufo_lowpitch.ogg");
    SDLWrap::Chunk chunk("res/sfx/si/explosion.ogg");

    bool app_running = true;

    SDL_Event event;

    utils::LTimer fps_timer;
    utils::LTimer cap_timer;
    int counted_frames = 0;
    fps_timer.start();

    while (app_running) {
      cap_timer.start();
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
          app_running = false;
        } else if (event.type == SDL_KEYDOWN) {
          switch (event.key.keysym.sym) {
          case SDLK_1:
            mixer.play_channel(-1, chunk, 0);
            break;
          case SDLK_2:
            if (mixer.playing_music() == 0) {
              mixer.play_music(music, -1);
            } else {
              if (mixer.is_music_paused()) {
                mixer.resume_music();
              } else {
                mixer.pause_music();
              }
            }
            break;
          case SDLK_0:
            mixer.halt_music();
            break;
          }
        }
      }

      // Frame rate calculation
      int avg_fps = counted_frames / (fps_timer.get_ticks() / 1000.f);
      if (avg_fps > 2000000)
        avg_fps = 0;

      std::string fps = std::to_string(avg_fps).append("  FPS");

      // Update FPS counter texture
      text.update_text(renderer, font, fps, color);
      src_txt.h = text.get_height();
      src_txt.w = text.get_width();
      dst_txt.h = text.get_height();
      dst_txt.w = text.get_width();

      renderer.clear();
      renderer.copy(text, src_txt, dst_txt);
      renderer.present();

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
