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

  Texture& load_from_file(Renderer& renderer, const std::string& path);
  Texture& create_from_surface(Renderer& renderer, const Surface& surface);
  Texture& update_text(Renderer& renderer, Font& font, std::string text, SDL_Color& color);
  void destroy();
  SDL_Texture* get_texture() const;
  int get_width() const;
  int get_height() const;

  void lock();
  void unlock();
  void* get_pixels();
  void copy_pixels(void* pixels);
  int get_pitch();

private:
  SDL_Texture* texture_;
};

} // namespace SDLWrap

#endif // TEXTURE_H_
