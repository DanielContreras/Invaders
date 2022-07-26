#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

namespace utils {
inline float HireTimeInSeconds() {
  float t = SDL_GetTicks();
  t *= 0.001f;
  return t;
}
}  // namespace utils

#endif  // UTILS_H
