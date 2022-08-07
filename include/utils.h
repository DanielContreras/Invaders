#ifndef UTILS_H_
#define UTILS_H_

#include <SDL2/SDL.h>

namespace utils {

const int width = 224 * 4;
const int height = 256 * 4;
const int screen_fps = 60;
const int screen_tick_per_frame = 1000 / screen_fps;

class LTimer {
public:
  LTimer();

  void start();
  void stop();
  void pause();
  void unpause();

  uint32_t get_ticks();

  bool is_started();
  bool is_paused();

private:
  uint32_t start_ticks_;
  uint32_t paused_ticks_;
  bool paused_;
  bool started_;
};

} // namespace utils

#endif // UTILS_H_
