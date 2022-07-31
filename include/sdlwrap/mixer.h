#ifndef MIXER_H_
#define MIXER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

namespace SDLWrap {

class Chunk;
class Music;

class Mixer {
 public:
  Mixer(int frequency, uint16_t format, int channels, int chunksize);
  ~Mixer();

  int PlayChannel(int channel, const Chunk& chunk, int loops = 0);
  void PauseChannel(int channel = -1);
  void ResumeChannel(int channel = -1);
  void HaltChannel(int channel = -1);
  int ChannelPaused(int channel) const;
  int ChannelPlaying(int channel = -1) const;

  void PlayMusic(const Music& music, int loops = -1);
  bool PlayingMusic() const;
  bool IsMusicPaused() const;
  void PauseMusic();
  void ResumeMusic();
  void RewindMUsic();
  void HaltMusic();

 private:
};

}  // namespace SDLWrap

#endif  // MIXER_H_
