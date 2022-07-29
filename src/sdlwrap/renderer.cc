#include "sdlwrap/renderer.h"

#include "sdlwrap/window.h"
// #include "spdlog/spdlog.h"

namespace SDLWrap {

Renderer::Renderer(Window& window, int index, Uint32 flags) : renderer_(nullptr) {
  renderer_ = SDL_CreateRenderer(window.Get(), index, flags);
  if (renderer_ == nullptr) {
    // spdlog::error("Renderer failed to init. Error {}", SDL_GetError());
  }
  // spdlog::info("Renderer successfully initialized");
}

Renderer::~Renderer() {
  if (renderer_ != nullptr) SDL_DestroyRenderer(renderer_);
  // spdlog::info("Renderer successfully destroyed");
}

SDL_Renderer* Renderer::Get() const { return renderer_; }

Renderer& Renderer::Clear() {
  SDL_RenderClear(renderer_);
  return *this;
}

Renderer& Renderer::Copy() { return *this; }

Renderer& Renderer::Present() {
  SDL_RenderPresent(renderer_);
  return *this;
}

}  // namespace SDLWrap
