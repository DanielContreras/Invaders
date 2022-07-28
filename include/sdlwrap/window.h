#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>

namespace SDLWrap {

class Window {
 private:
  SDL_Window* window_;

 public:
  Window(const char* title, int w, int h, Uint32 flags);
  virtual ~Window();

  SDL_Window* Get() const;

  int GetRefreshRate();
};

}  // namespace SDLWrap

#endif  // WINDOW_H_
