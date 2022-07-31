#ifndef SDL_H_
#define SDL_H_

#include <SDL2/SDL.h>

namespace SDLWrap {

class SDL {
 public:
  SDL(uint32_t flags);
  ~SDL();

  void InitSubsystems(uint32_t flags);
  void QuitSubsystems(uint32_t flags);
};

}  // namespace SDLWrap

#endif  // SDL_H_
