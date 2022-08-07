#ifndef FONT_H_
#define FONT_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <SDL_ttf.h>
#elif __linux__
#include <SDL2/SDL_ttf.h>
#else
#error "Unknown compiler"
#endif

#include <string>

namespace SDLWrap {

class Renderer;
class Surface;

class Font {
public:
  Font(const std::string& path, int font_size, long index = 0);
  ~Font();

  bool load_from_file(std::string path, int font_size, long index = 0);
  TTF_Font* get_font() const;
  int get_style() const;
  Font& set_style(int style = TTF_STYLE_NORMAL);
  Surface render_text_solid(const std::string& text, SDL_Color fg);
  Surface render_text_blended(const std::string& text, SDL_Color fg);

private:
  TTF_Font* font_;
};

} // namespace SDLWrap

#endif // FONT_H_
