#include "sdlwrap/sdl.h"

#include "log.h"

namespace SDLWrap {

SDL::SDL(Uint32 flags) {
  if (SDL_Init(flags) != 0) {
    CORE_CRITICAL("SDL_Init has failed. Error: {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
    return;
  }
  CORE_DEBUG("SDL successfully initialized");
}

SDL::~SDL() {
  SDL_Quit();
  CORE_DEBUG("SDL successfully destroyed");
}

}  // namespace SDLWrap
