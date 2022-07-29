#include "sdlwrap/window.h"

#include <SDL2/SDL_error.h>

// #include "spdlog/spdlog.h"

namespace SDLWrap {

Window::Window(const char* title, int w, int h, Uint32 flags) : window_(nullptr) {
  window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);
  if (window_ == nullptr) {
    // spdlog::error("Window failed to init. Error {}", SDL_GetError());
  }
  // spdlog::info("Window successfully initialized");
}

Window::~Window() {
  if (window_ != nullptr) SDL_DestroyWindow(window_);
  // spdlog::info("Window successfully destroyed");
}

SDL_Window* Window::Get() const { return window_; }

int Window::GetRefreshRate() {
  int display_index = SDL_GetWindowDisplayIndex(window_);

  SDL_DisplayMode mode;
  SDL_GetDisplayMode(display_index, 0, &mode);
  return mode.refresh_rate;
}

}  // namespace SDLWrap
