#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>

namespace SDLWrap {

class Window {
 public:
  Window(const char* title, int w, int h, uint32_t flags);
  ~Window();

  SDL_Window* GetWindow() const;

  int GetRefreshRate();
  int GetWidth() const;
  int GetHeight() const;

 private:
  SDL_Window* window_;
};

}  // namespace SDLWrap

#endif  // WINDOW_H_
