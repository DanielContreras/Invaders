#ifndef RENDERER_H_
#define RENDERER_H_

#include <SDL2/SDL.h>

namespace SDLWrap {

class Window;
class Texture;

class Renderer {
 public:
  Renderer(Window& window, int index, Uint32 flags);
  virtual ~Renderer();

  SDL_Renderer* GetRenderer() const;

  Renderer& Clear();
  Renderer& Copy(Texture& texture, const SDL_Rect& src, const SDL_Rect& dst);
  Renderer& Copy(Texture& texture);
  Renderer& Present();

 private:
  SDL_Renderer* renderer_;
};

}  // namespace SDLWrap

#endif  // RENDERER_H_
