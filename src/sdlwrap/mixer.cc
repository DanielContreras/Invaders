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
    CORE_CRITICAL("SDL_mixer failed to initialize. Error: {}", Mix_GetError());
    return;
  }
  CORE_DEBUG("SDL_mixer successfully initialized");
}

Mixer::~Mixer() { Mix_CloseAudio(); }

int Mixer::PlayChannel(int channel, const Chunk& chunk, int loops) {
  int chan = Mix_PlayChannel(channel, chunk.GetChunk(), loops);
  if (chan == -1) {
    CORE_ERROR("Failed to play chunk. Error: {}", Mix_GetError());
    // TODO: Throw exception?
  }
  return chan;
}

void Mixer::PauseChannel(int channel) { Mix_Pause(channel); }

void Mixer::ResumeChannel(int channel) { Mix_Resume(channel); }

void Mixer::HaltChannel(int channel) { Mix_HaltChannel(channel); }

int Mixer::ChannelPaused(int channel) const { return Mix_Paused(channel); }

int Mixer::ChannelPlaying(int channel) const { return Mix_Paused(channel); }

void Mixer::PlayMusic(const Music& music, int loops) {
  if (Mix_PlayMusic(music.GetMusic(), loops) == -1) {
    CORE_ERROR("Failed to play music. Error: {}", Mix_GetError());
    // TODO: Throw exception?
  }
}

bool Mixer::PlayingMusic() const { return Mix_PlayingMusic() > 0; }

bool Mixer::IsMusicPaused() const { return Mix_PausedMusic() > 0; }

void Mixer::PauseMusic() { Mix_PauseMusic(); }

void Mixer::ResumeMusic() { Mix_ResumeMusic(); }

void Mixer::RewindMUsic() { Mix_RewindMusic(); }

void Mixer::HaltMusic() { Mix_HaltMusic(); }

}  // namespace SDLWrap
