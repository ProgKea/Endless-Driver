#include "func.h"

SDL_Surface *scoreSurface;
SDL_Texture *scoreTexture;
extern TTF_Font *font;

void render_score(SDL_Renderer *renderer, float score) {
  char score_char[5];
  SDL_Color font_color = {255, 255, 255};
  sprintf(score_char, "%.0f", score);
  scoreSurface = TTF_RenderText_Solid(font, score_char, font_color);
  scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
  drawTexture(getmid(FONT_SIZE), FONT_SIZE, FONT_SIZE, FONT_SIZE, scoreTexture, renderer, false);
  SDL_FreeSurface(scoreSurface);
  SDL_DestroyTexture(scoreTexture);
}
