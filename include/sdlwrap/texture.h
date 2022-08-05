#ifndef TEXTURE_H_
#define TEXTURE_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL.h>
#elif __linux__
#include <SDL2/SDL.h>
#else
#error "Unknown compiler"
#endif

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
