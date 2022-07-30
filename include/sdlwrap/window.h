#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>

namespace SDLWrap {

class Window {
 public:
  Window(const char* title, int w, int h, Uint32 flags);
  virtual ~Window();

  SDL_Window* GetWindow() const;

  int GetRefreshRate();

 private:
  SDL_Window* window_;
};

}  // namespace SDLWrap

#endif  // WINDOW_H_
