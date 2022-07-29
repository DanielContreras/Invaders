#include "sdlwrap/sdl.h"

// #include "spdlog/spdlog.h"

namespace SDLWrap {

SDL::SDL(Uint32 flags) {
  if (SDL_Init(flags) != 0) {
    // spdlog::error("SDL_Init has failed. Error: {}", SDL_GetError());
  }
  // spdlog::info("SDL successfully initialized");
}

SDL::~SDL() {
  SDL_Quit();
  // spdlog::info("SDL successfully destroyed");
}

}  // namespace SDLWrap
