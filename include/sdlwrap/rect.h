#ifndef RECT_H_
#define RECT_H_

#include <SDL2/SDL.h>

namespace SDLWrap {

class Rect : public SDL_Rect {
 public:
  constexpr Rect() : SDL_Rect{0, 0, 0, 0} {}
  constexpr Rect(int x, int y, int w, int h) : SDL_Rect{x, y, w, h} {}
  virtual ~Rect();

  constexpr int GetX() const { return x; }

 private:
};

}  // namespace SDLWrap

#endif  // RECT_H_
