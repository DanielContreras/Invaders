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
  CORE_DEBUG("Chunk successfully unloaded");
}

Mix_Chunk* Chunk::get_chunk() const { return chunk_; }

} // namespace SDLWrap
