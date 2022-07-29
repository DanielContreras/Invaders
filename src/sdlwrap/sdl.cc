#include "sdlwrap/sdl.h"

#include "log.h"

namespace SDLWrap {

SDL::SDL(Uint32 flags) {
  if (SDL_Init(flags) != 0) CORE_ERROR("SDL_Init has failed. Error: {}", SDL_GetError());
  CORE_DEBUG("SDL successfully initialized");
}

SDL::~SDL() {
  SDL_Quit();
  CORE_DEBUG("SDL successfully destroyed");
}

}  // namespace SDLWrap
