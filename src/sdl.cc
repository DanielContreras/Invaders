#include "sdlwrap/sdl.h"

namespace SDLWrap {

SDL::SDL(Uint32 flags) {
  if (SDL_Init(flags) != 0) SDL_Log("SDL_Init has failed. Error: %s", SDL_GetError());
}

SDL::~SDL() { SDL_Quit(); }

}  // namespace SDLWrap
