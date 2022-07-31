#include "sdlwrap/sdl.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "log.h"

namespace SDLWrap {

SDL::SDL(uint32_t flags) {
  if (SDL_Init(flags) != 0) {
    CORE_CRITICAL("SDL_Init has failed. Error: {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
    return;
  }
  CORE_DEBUG("SDL successfully initialized");
}

SDL::~SDL() {
  if (TTF_Init() == 0) {
    TTF_Quit();
    CORE_DEBUG("SDL_TTF successfully destroyed");
  }
  SDL_Quit();
  CORE_DEBUG("SDL successfully destroyed");
}

void SDL::InitTTF() {
  if (TTF_Init() != 0) {
    CORE_ERROR("TTF Failed to initialize. Error: {}", TTF_GetError());
    return;
    // TODO: Throw exception?
  }
  CORE_DEBUG("SDL_TTF successfully iniitalized");
}

void SDL::InitSubsystems(uint32_t flags) {
  if (SDL_InitSubSystem(flags) != 0) {
    CORE_CRITICAL("SDL has failed to init subsystems. Error: {}", SDL_GetError());
    return;
  }
  CORE_DEBUG("SDL has successfully initialized its subsystems");
}

void SDL::QuitSubsystems(uint32_t flags) {
  SDL_QuitSubSystem(flags);
  CORE_DEBUG("SDL has successfully destroyed the subsystems");
}

}  // namespace SDLWrap
