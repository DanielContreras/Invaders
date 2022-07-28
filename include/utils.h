#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

namespace utils {

inline float HireTimeInSeconds() {
  float t = SDL_GetTicks();
  t *= 0.001f;
  return t;
}

class Timestep {
 private:
  float time_step_;
  float accumulator_;
  float current_time_;
  int start_ticks_;
  float new_time_;
  float frame_time_;
  int frame_ticks_;

 public:
  inline Timestep(float time_step, float accumulator) {
    time_step_ = time_step;
    accumulator_ = accumulator;
    current_time_ = utils::HireTimeInSeconds();
  }
  inline void start() {
    start_ticks_ = SDL_GetTicks();
    new_time_ = utils::HireTimeInSeconds();
    frame_time_ = new_time_ - current_time_;
    current_time_ = new_time_;
    accumulator_ += frame_time_;
  }
  inline float GetTimeStep() { return time_step_; }
  inline float GetAccumulator() { return accumulator_; }
  inline float GetCurrentTime() { return current_time_; }
  inline int GetStartTicks() { return start_ticks_; }
  inline float GetNewTime() { return new_time_; }
  inline float GetFrameTime() { return frame_time_; }
  inline int GetFrameTicks() { return frame_ticks_; }
  inline int GetFPS() { return (frame_time_ > 0) ? 1000.0f / frame_time_ : 0.0f; }
  inline float GetAlpha() { return accumulator_ / time_step_; }

  inline void SetAccumulator(float accumulator) { accumulator_ = accumulator; }
  inline void SetCurrentTime(float current_time) { current_time_ = current_time; }
  inline void SetStartTicks(float start_ticks) { start_ticks_ = start_ticks; }
  inline void SetNewTime(float new_time) { new_time_ = new_time; }
  inline void SetFrameTime(float frame_time) { frame_time_ = frame_time; }
  inline void SetFrameTicks(float frame_ticks) { frame_ticks_ = frame_ticks; }
};

}  // namespace utils

#endif  // UTILS_H
