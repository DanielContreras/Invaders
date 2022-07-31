#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

namespace Utils {

class LTimer {
 public:
  LTimer();

  void Start();
  void Stop();
  void Pause();
  void Unpause();

  uint32_t GetTicks();

  bool IsStarted();
  bool IsPaused();

 private:
  uint32_t start_ticks_;
  uint32_t paused_ticks_;
  bool paused_;
  bool started_;
};

}  // namespace utils

#endif  // UTILS_H
