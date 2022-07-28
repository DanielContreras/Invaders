#ifndef SDL_H_
#define SDL_H_

#include <SDL2/SDL.h>

namespace SDLWrap {

class SDL {
 public:
  SDL(Uint32 flags);
  virtual ~SDL();
};

}  // namespace SDLWrap

#endif  // SDL_H_
