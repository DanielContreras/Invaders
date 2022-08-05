#include "sdlwrap/surface.h"

#include <SDL2/SDL_image.h>

#include <cassert>

#include "log.h"

namespace SDLWrap {

Surface::Surface(SDL_Surface* surface) : surface_(surface) { assert(surface); }

Surface::Surface(const std::string& path) {
  surface_ = IMG_Load(path.c_str());
  if (surface_ == nullptr) {
    CORE_ERROR("Failed to load surface. Error: {}", SDL_GetError());
    // TODO: exception?
  }
  CORE_DEBUG("Surface successfully loaded");
}

Surface::~Surface() {
  if (surface_ != nullptr) SDL_FreeSurface(surface_);
}

SDL_Surface* Surface::GetSurface() const { return surface_; }

}  // namespace SDLWrap
