#ifndef RENDERER_H_
#define RENDERER_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#else
#error "Unknown compiler"
#endif

namespace SDLWrap {

class Window;
class Texture;

class Renderer {
public:
  Renderer(Window& window, int index, uint32_t flags);
  ~Renderer();

  SDL_Renderer* get_renderer() const;

  Renderer& clear();
  Renderer& copy(Texture& texture, const SDL_Rect& src, const SDL_Rect& dst);
  Renderer& copy(Texture& texture);
  Renderer& present();

private:
  SDL_Renderer* renderer_;
};

} // namespace SDLWrap

#endif // RENDERER_H_
