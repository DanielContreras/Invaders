#ifndef RENDERER_H_
#define RENDERER_H_

#include <SDL2/SDL.h>

#include "sdlwrap/window.h"

namespace SDLWrap {

class Renderer {
 public:
  Renderer(Window& window, int index, Uint32 flags);
  virtual ~Renderer();

  SDL_Renderer* GetRenderer() const;

  Renderer& Clear();
  Renderer& Copy();
  Renderer& Present();

 private:
  SDL_Renderer* renderer_;
};

}  // namespace SDLWrap

#endif  // RENDERER_H_
