#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string>

namespace SDLWrap {

class Renderer;
class Surface;
class Font;

class Texture {
 public:
  Texture(Renderer& renderer, const std::string& path);
  Texture(Renderer& renderer, const Surface& surface);
  ~Texture();

  SDL_Texture* GetTexture() const;
  int GetWidth() const;
  int GetHeight() const;

 private:
  SDL_Texture* texture_;
};

}  // namespace SDLWrap

#endif  // TEXTURE_H_
