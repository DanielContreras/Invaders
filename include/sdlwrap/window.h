#ifndef WINDOW_H_
#define WINDOW_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#else
#error "Unknown compiler"
#endif

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
