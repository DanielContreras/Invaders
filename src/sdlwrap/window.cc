#include "sdlwrap/window.h"

#include "log.h"

namespace SDLWrap {

Window::Window(const char* title, int w, int h, uint32_t flags) : window_(nullptr) {
  window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags);
  if (window_ == nullptr) {
    CORE_CRITICAL("Window failed to init. Error {}", SDL_GetError());
    // TODO: Should throw an exception here and not allow application to continue running
  }
  CORE_DEBUG("Window successfully initialized");
}

Window::~Window() {
  if (window_ != nullptr) {
    SDL_DestroyWindow(window_);
    CORE_DEBUG("Window successfully destroyed");
  }
}

SDL_Window* Window::GetWindow() const { return window_; }

int Window::GetWidth() const {
  int width;
  SDL_GetWindowSize(window_, &width, nullptr);
  return width;
}

int Window::GetHeight() const {
  int height;
  SDL_GetWindowSize(window_, nullptr, &height);
  return height;
}

int Window::GetRefreshRate() {
  int display_index = SDL_GetWindowDisplayIndex(window_);

  SDL_DisplayMode mode;
  SDL_GetDisplayMode(display_index, 0, &mode);
  return mode.refresh_rate;
}

}  // namespace SDLWrap
