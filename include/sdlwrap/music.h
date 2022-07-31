#ifndef MUSIC_H_
#define MUSIC_H_

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

namespace SDLWrap {

class Music {
 public:
  Music(const std::string& path);
  ~Music();

  Mix_Music* GetMusic() const;
  Mix_MusicType GetType() const;

 private:
  Mix_Music* music_ = nullptr;
};

}  // namespace SDLWrap

#endif  // MUSIC_H_
