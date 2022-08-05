#ifndef SURFACE_H_
#define SURFACE_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#else
#error "Unknown compiler"
#endif

#include <string>

namespace SDLWrap {

class Renderer;

class Surface {
 public:
  Surface(SDL_Surface* surface);
  Surface(const std::string& path);
  ~Surface();

  SDL_Surface* GetSurface() const;

 private:
  SDL_Surface* surface_;
};

}  // namespace SDLWrap

#endif  // SURFACE_H_
