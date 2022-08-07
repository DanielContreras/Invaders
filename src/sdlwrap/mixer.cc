#include "sdlwrap/mixer.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL_mixer.h>
#elif __linux__
#include <SDL2/SDL_mixer.h>
#endif

#include "log.h"
#include "sdlwrap/chunk.h"
#include "sdlwrap/music.h"

namespace SDLWrap {

Mixer::Mixer(int frequency, uint16_t format, int channels, int chunksize) {
  if (Mix_OpenAudio(frequency, format, channels, chunksize) < 0) {
    CORE_ERROR("SDL_mixer failed to initialize. Error: {}", Mix_GetError());
    return;
  }
  CORE_DEBUG("SDL_mixer successfully opened");
}

Mixer::~Mixer() {
  Mix_CloseAudio();
  CORE_DEBUG("SDL_Mixer successfully closed");
}

int Mixer::play_channel(int channel, const Chunk& chunk, int loops) {
  int chan = Mix_PlayChannel(channel, chunk.get_chunk(), loops);
  if (chan == -1) {
    CORE_ERROR("Failed to play chunk. Error: {}", Mix_GetError());
    // TODO: Throw exception?
  }
  return chan;
}

void Mixer::pause_channel(int channel) { Mix_Pause(channel); }

void Mixer::resume_channel(int channel) { Mix_Resume(channel); }

void Mixer::halt_channel(int channel) { Mix_HaltChannel(channel); }

int Mixer::channel_paused(int channel) const { return Mix_Paused(channel); }

int Mixer::channel_playing(int channel) const { return Mix_Playing(channel); }

void Mixer::play_music(const Music& music, int loops) {
  if (Mix_PlayMusic(music.get_music(), loops) == -1) {
    CORE_ERROR("Failed to play music. Error: {}", Mix_GetError());
    // TODO: Throw exception?
  }
}

bool Mixer::playing_music() const { return Mix_PlayingMusic() > 0; }

bool Mixer::is_music_paused() const { return Mix_PausedMusic() > 0; }

void Mixer::pause_music() { Mix_PauseMusic(); }

void Mixer::resume_music() { Mix_ResumeMusic(); }

void Mixer::rewind_music() { Mix_RewindMusic(); }

void Mixer::halt_music() { Mix_HaltMusic(); }

} // namespace SDLWrap
