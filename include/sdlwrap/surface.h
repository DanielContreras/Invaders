#ifndef SURFACE_H_
#define SURFACE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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
