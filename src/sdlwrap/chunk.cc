#include <SDL2/SDL_mixer.h>
#include <sdlwrap/chunk.h>

#include "log.h"

namespace SDLWrap {

Chunk::Chunk(const std::string& path) {
  chunk_ = Mix_LoadWAV(path.c_str());
  if (chunk_ == nullptr) {
    CORE_ERROR("Failed to load chunk. Error: {}", Mix_GetError());
    // TODO: Throw exception?
    return;
  }
  CORE_DEBUG("Chunk successfully loaded");
}

Chunk::~Chunk() {
  Mix_FreeChunk(chunk_);
  CORE_DEBUG("Chunk successfully destroyed");
}

Mix_Chunk* Chunk::GetChunk() const { return chunk_; }

}  // namespace SDLWrap
