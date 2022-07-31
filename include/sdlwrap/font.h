#ifndef FONT_H_
#define FONT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

namespace SDLWrap {

class Renderer;
class Surface;

class Font {
 public:
  Font(const std::string& path, int font_size, long index = 0);
  ~Font();

  TTF_Font* GetFont() const;
  int GetStyle() const;
  Font& SetStyle(int style = TTF_STYLE_NORMAL);
  Surface RenderText_Solid(const std::string& text, SDL_Color fg);
  Surface RenderText_Blended(const std::string& text, SDL_Color fg);

 private:
  TTF_Font* font_;
};

}  // namespace SDLWrap

#endif  // FONT_H_
