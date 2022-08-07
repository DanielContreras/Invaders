#include "sdlwrap/font.h"

#include "log.h"
#include "sdlwrap/surface.h"

namespace SDLWrap {

Font::Font(const std::string& path, int font_size, long index) {
  font_ = TTF_OpenFontIndex(path.c_str(), font_size, index);
  if (font_ == nullptr) {
    CORE_ERROR("Failed to load font. Error: {}", TTF_GetError());
    // TODO: Exception?
    return;
  }
  CORE_DEBUG("Font was successfully loaded");
}

Font::~Font() {
  if (font_ != nullptr) {
    TTF_CloseFont(font_);
    CORE_DEBUG("Font successfully unloaded");
  }
}

bool Font::load_from_file(std::string path, int font_size, long index) {
  font_ = TTF_OpenFontIndex(path.c_str(), font_size, index);
  if (font_ == nullptr) {
    CORE_ERROR("Failed to load font. Error: {}", TTF_GetError());
    // TODO: Exception?
    return 0;
  }
  CORE_DEBUG("Font was successfully loaded");
  return 1;
}

TTF_Font* Font::get_font() const { return font_; }

int Font::get_style() const { return TTF_GetFontStyle(font_); }

Font& Font::set_style(int style) {
  TTF_SetFontStyle(font_, style);
  return *this;
}

Surface Font::render_text_solid(const std::string& text, SDL_Color fg) {
  SDL_Surface* surface = TTF_RenderText_Solid(font_, text.c_str(), fg);
  if (surface == nullptr) {
    CORE_ERROR("Failed to render surface. Error: {}", TTF_GetError());
    // TODO: Exception?
  }
  return Surface(surface);
}

Surface Font::render_text_blended(const std::string& text, SDL_Color fg) {
  SDL_Surface* surface = TTF_RenderText_Blended(font_, text.c_str(), fg);
  if (surface == nullptr) {
    CORE_ERROR("Failed to render surface. Error: {}", TTF_GetError());
    // TODO: Exception?
  }
  return Surface(surface);
}

} // namespace SDLWrap
