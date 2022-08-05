#ifndef CHUNK_H_
#define CHUNK_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL_mixer.h>
#elif __linux__
#include <SDL2/SDL_mixer.h>
#else
#error "Unknown compiler"
#endif

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
