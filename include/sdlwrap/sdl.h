#ifndef SDL_H_
#define SDL_H_

#include <stdint.h>

namespace SDLWrap {

class SDL {
public:
  SDL(uint32_t flags);
  ~SDL();

  void init_TTF();

  void init_subsystems(uint32_t flags);
  void quit_subsystems(uint32_t flags);
};

} // namespace SDLWrap

#endif // SDL_H_
