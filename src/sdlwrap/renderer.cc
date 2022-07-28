#include "sdlwrap/renderer.h"

#include "sdlwrap/window.h"

namespace SDLWrap {

Renderer::Renderer(Window& window, int index, Uint32 flags) : renderer_(nullptr) {
  renderer_ = SDL_CreateRenderer(window.Get(), index, flags);
  if (renderer_ == nullptr) {
    SDL_Log("Renderer failed to init. Error: %s", SDL_GetError());
  }
}

Renderer::~Renderer() {
  if (renderer_ != nullptr) SDL_DestroyRenderer(renderer_);
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
