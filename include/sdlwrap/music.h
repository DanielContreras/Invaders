#ifndef MUSIC_H_
#define MUSIC_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL_mixer.h>
#elif __linux__
#include <SDL2/SDL_mixer.h>
#else
#error "Unknown compiler"
#endif

#include <string>

namespace SDLWrap {

class Music {
public:
  Music(const std::string& path);
  ~Music();

  Mix_Music* get_music() const;
  Mix_MusicType get_type() const;

private:
  Mix_Music* music_ = nullptr;
};

} // namespace SDLWrap

#endif // MUSIC_H_
