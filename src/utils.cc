#include "utils.h"

namespace utils {

LTimer::LTimer() {
  start_ticks_ = 0;
  paused_ticks_ = 0;
  paused_ = false;
  started_ = false;
}

void LTimer::start() {
  started_ = true;
  paused_ = false;
  start_ticks_ = SDL_GetTicks();
  paused_ticks_ = 0;
}

void LTimer::stop() {
  started_ = false;
  paused_ = false;
  start_ticks_ = 0;
  paused_ticks_ = 0;
}

void LTimer::pause() {
  if (started_ && !paused_) {
    paused_ = true;
    paused_ticks_ = SDL_GetTicks() - start_ticks_;
    start_ticks_ = 0;
  }
}

void LTimer::unpause() {
  if (started_ && paused_) {
    paused_ = false;
    start_ticks_ = SDL_GetTicks() - paused_ticks_;
    paused_ticks_ = 0;
  }
}

uint32_t LTimer::get_ticks() {
  uint32_t time = 0;
  if (started_) {
    if (paused_) {
      time = paused_ticks_;
    } else {
      time = SDL_GetTicks() - start_ticks_;
    }
  }
  return time;
}

bool LTimer::is_started() { return started_; }

bool LTimer::is_paused() { return paused_ && started_; }

} // namespace utils
