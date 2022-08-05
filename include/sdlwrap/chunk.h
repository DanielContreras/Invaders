#ifndef CHUNK_H_
#define CHUNK_H_

#include <SDL2/SDL_mixer.h>

#include <string>

namespace SDLWrap {

class Chunk {
 public:
  Chunk(const std::string& path);
  ~Chunk();

  Mix_Chunk* GetChunk() const;

 private:
  Mix_Chunk* chunk_;
};

}  // namespace SDLWrap

#endif  // CHUNK_H_
