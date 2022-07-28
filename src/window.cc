#include "sdlwrap/window.h"

namespace SDLWrap {

Window::Window(const char* title, int w, int h, Uint32 flags) : window_(nullptr) {
  window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);
  if (window_ == nullptr) {
    SDL_Log("Window failed to init. Error: %s", SDL_GetError());
    // TODO(Daniel): Throw an exception here
  }
}

Window::~Window() {
  if (window_ != nullptr) SDL_DestroyWindow(window_);
}

SDL_Window* Window::Get() const { return window_; }

int Window::GetRefreshRate() {
  int display_index = SDL_GetWindowDisplayIndex(window_);

  SDL_DisplayMode mode;
  SDL_GetDisplayMode(display_index, 0, &mode);
  return mode.refresh_rate;
}

}  // namespace SDLWrap
