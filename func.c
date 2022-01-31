#include "func.h"
#include <SDL2/SDL_render.h>

void drawTexture(SDL_Renderer *renderer, int x, int y, int w, int h, SDL_Texture *tex) {
  SDL_Rect rect;
  rect.h = h;
  rect.w = w;
  rect.x = x;
  rect.y = y;
  SDL_RenderCopy(renderer, tex, NULL, &rect);
} 

void drawTextureRotated(SDL_Renderer *renderer, int x, int y, int w, int h, SDL_Texture *tex) {
  SDL_Rect rect;
  rect.h = h;
  rect.w = w;
  rect.x = x;
  rect.y = y;
  SDL_RenderCopyEx(renderer, tex, NULL, &rect, 0.0, NULL, SDL_FLIP_VERTICAL);
} 

void drawImgRect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Texture *tex) {
  SDL_RenderCopy(renderer, tex, NULL, &rect);
} 

void drawImgRectRotated(SDL_Renderer *renderer, SDL_Rect rect, SDL_Texture *tex) {
  SDL_RenderCopyEx(renderer, tex, NULL, &rect, 0.0, NULL, SDL_FLIP_VERTICAL);
} 

void drawRect(SDL_Renderer *renderer, int x, int y, int w, int h, int r, int g, int b) {
  SDL_Rect rect;
  rect.h = h;
  rect.w = w;
  rect.x = x;
  rect.y = y;

  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderFillRect(renderer, &rect);
}

int getmid(int w) {
  return WIDTH/2-w/2;
}

int generate_random_int(int range) {
  return rand()%range;
} 

int generate_random_negative_int(int range) {
  int a = rand()%range;
  return a-a*2;
} 
