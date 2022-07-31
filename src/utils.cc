#include "utils.h"

namespace Utils {

LTimer::LTimer() {
  start_ticks_ = 0;
  paused_ticks_ = 0;
  paused_ = false;
  started_ = false;
}

void LTimer::Start() {
  started_ = true;
  paused_ = false;
  start_ticks_ = SDL_GetTicks();
  paused_ticks_ = 0;
}

void LTimer::Stop() {
  started_ = false;
  paused_ = false;
  start_ticks_ = 0;
  paused_ticks_ = 0;
}

void LTimer::Pause() {
  if (started_ && !paused_) {
    paused_ = true;
    paused_ticks_ = SDL_GetTicks() - start_ticks_;
    start_ticks_ = 0;
  }
}

void LTimer::Unpause() {
  if (started_ && paused_) {
    paused_ = false;
    start_ticks_ = SDL_GetTicks() - paused_ticks_;
    paused_ticks_ = 0;
  }
}

uint32_t LTimer::GetTicks() {
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

bool LTimer::IsStarted() { return started_; }

bool LTimer::IsPaused() { return paused_ && started_; }

}  // namespace Utils
