#include "sdlwrap/music.h"

#include "log.h"

namespace SDLWrap {

Music::Music(const std::string& path) {
  music_ = Mix_LoadMUS(path.c_str());
  if (music_ == nullptr) {
    CORE_ERROR("Failed to load music. Error: {}", Mix_GetError());
    // TODO: Throw exception?
    return;
  }
  CORE_DEBUG("Music successfully loaded");
}

Music::~Music() {
  Mix_FreeMusic(music_);
  CORE_DEBUG("Music successfully unloaded");
}

Mix_Music* Music::get_music() const { return music_; }

Mix_MusicType Music::get_type() const { return Mix_GetMusicType(music_); }

} // namespace SDLWrap
