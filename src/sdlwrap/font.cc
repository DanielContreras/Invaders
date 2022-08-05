#include "sdlwrap/font.h"

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

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

bool Font::LoadFromFile(std::string path, int font_size, long index) {
  font_ = TTF_OpenFontIndex(path.c_str(), font_size, index);
  if (font_ == nullptr) {
    CORE_ERROR("Failed to load font. Error: {}", TTF_GetError());
    // TODO: Exception?
    return 0;
  }
  CORE_DEBUG("Font was successfully loaded");
  return 1;
}

TTF_Font* Font::GetFont() const { return font_; }

int Font::GetStyle() const { return TTF_GetFontStyle(font_); }

Font& Font::SetStyle(int style) {
  TTF_SetFontStyle(font_, style);
  return *this;
}

Surface Font::RenderText_Solid(const std::string& text, SDL_Color fg) {
  SDL_Surface* surface = TTF_RenderText_Solid(font_, text.c_str(), fg);
  if (surface == nullptr) {
    CORE_ERROR("Failed to render surface. Error: {}", TTF_GetError());
    // TODO: Exception?
  }
  return Surface(surface);
}

Surface Font::RenderText_Blended(const std::string& text, SDL_Color fg) {
  SDL_Surface* surface = TTF_RenderText_Blended(font_, text.c_str(), fg);
  if (surface == nullptr) {
    CORE_ERROR("Failed to render surface. Error: {}", TTF_GetError());
    // TODO: Exception?
  }
  return Surface(surface);
}

}  // namespace SDLWrap
