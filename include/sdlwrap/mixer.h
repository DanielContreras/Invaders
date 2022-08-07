#ifndef MIXER_H_
#define MIXER_H_

#include <stdint.h>

namespace SDLWrap {

class Chunk;
class Music;

class Mixer {
public:
  Mixer(int frequency, uint16_t format, int channels, int chunksize);
  ~Mixer();

  int play_channel(int channel, const Chunk& chunk, int loops = 0);
  void pause_channel(int channel = -1);
  void resume_channel(int channel = -1);
  void halt_channel(int channel = -1);
  int channel_paused(int channel) const;
  int channel_playing(int channel = -1) const;

  void play_music(const Music& music, int loops = -1);
  bool playing_music() const;
  bool is_music_paused() const;
  void pause_music();
  void resume_music();
  void rewind_music();
  void halt_music();

private:
  bool audio_open_;
};

} // namespace SDLWrap

#endif // MIXER_H_
