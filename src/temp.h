#ifndef TEMP_H_
#define TEMP_H_

#include <SDL2/SDL.h>

class Dot {
 public:
  static const int DOT_WIDTH = 20;
  static const int DOT_HEIGHT = 20;
  static const int DOT_VEL_ = 10;

  inline Dot() {
    pos_x_ = 0;
    pos_y_ = 0;
    vel_x_ = 0;
    vel_y_ = 0;
  }

  inline void HandleEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          vel_y_ -= DOT_VEL_;
          break;
        case SDLK_DOWN:
          vel_y_ += DOT_VEL_;
          break;
        case SDLK_LEFT:
          vel_x_ -= DOT_VEL_;
          break;
        case SDLK_RIGHT:
          vel_x_ += DOT_VEL_;
          break;
      }
    } else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          vel_y_ += DOT_VEL_;
          break;
        case SDLK_DOWN:
          vel_y_ -= DOT_VEL_;
          break;
        case SDLK_LEFT:
          vel_x_ += DOT_VEL_;
          break;
        case SDLK_RIGHT:
          vel_x_ -= DOT_VEL_;
          break;
      }
    }
  }
  inline void move() {
    pos_x_ += vel_x_;
    if ((pos_x_ < 0) || (pos_x_ + DOT_WIDTH > 1280)) {
      pos_x_ -= vel_x_;
    }
    pos_y_ += vel_y_;
    if ((pos_y_ < 0) || (pos_y_ + DOT_HEIGHT > 720)) {
      pos_x_ -= vel_x_;
    }
  }
  inline void render() {}

 private:
  int pos_x_;
  int pos_y_;
  int vel_x_;
  int vel_y_;
};

#endif  // TEMP_H_
