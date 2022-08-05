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
  Texture();
  Texture(Renderer& renderer, const std::string& path);
  Texture(Renderer& renderer, const Surface& surface);
  ~Texture();

  Texture& LoadFromFile(Renderer& renderer, const std::string& path);
  Texture& CreateFromSurface(Renderer& renderer, const Surface& surface);
  Texture& UpdateText(Renderer& renderer, Font& font, std::string text, SDL_Color& color);
  // Texture& UpdateText(Renderer& renderer, Font& font, const char* text, SDL_Color& color);
  void Destroy();
  SDL_Texture* GetTexture() const;
  int GetWidth() const;
  int GetHeight() const;

  void Lock();
  void Unlock();
  void* GetPixels();
  void CopyPixels(void* pixels);
  int GetPitch();

 private:
  SDL_Texture* texture_;
};

}  // namespace SDLWrap

#endif  // TEXTURE_H_
