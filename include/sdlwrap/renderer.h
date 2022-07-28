#ifndef RENDERER_H_
#define RENDERER_H_

#include <SDL2/SDL.h>

#include "sdlwrap/window.h"

namespace SDLWrap {

class Renderer {
 private:
  SDL_Renderer* renderer_;

 public:
  Renderer(Window& window, int index, Uint32 flags);
  virtual ~Renderer();

  SDL_Renderer* Get() const;

  Renderer& Clear();
  Renderer& Copy();
  Renderer& Present();
};

}  // namespace SDLWrap

#endif  // RENDERER_H_
