#include "sdlwrap/surface.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL_image.h>
#elif __linux__
#include <SDL2/SDL_image.h>
#endif

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
