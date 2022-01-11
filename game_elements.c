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
  drawTexture(renderer, getmid(FONT_SIZE), FONT_SIZE, FONT_SIZE, FONT_SIZE, scoreTexture, false);
  SDL_FreeSurface(scoreSurface);
  SDL_DestroyTexture(scoreTexture);
}

SDL_Rect jerry_rect_arr[10];

void spawn_jerry(int index) {
  srand(time(NULL));
  SDL_Rect jerry_rect;
  jerry_rect.w = 40;
  jerry_rect.h = 50;
  jerry_rect.x = getmid(jerry_rect.w); 
  jerry_rect.y = 100;//-jerry_rect.h;
  jerry_rect_arr[index] = jerry_rect;
}
