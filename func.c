#include "func.h"

void drawTexture(int x, int y, int w, int h, SDL_Texture *tex, SDL_Renderer *renderer, bool rotate) {
  SDL_Rect rect;
  rect.h = h;
  rect.w = w;
  rect.x = x;
  rect.y = y;
  if (!rotate) 
    SDL_RenderCopy(renderer, tex, NULL, &rect);
  else {
    SDL_RenderCopyEx(renderer, tex, NULL, &rect, 0.0, NULL, SDL_FLIP_VERTICAL);
  } 
} 

int getmid(int w) {
  return WIDTH/2-w/2;
}

int move(int dir, int cord, int mid) {
  if (dir == LEFT)
    cord -= cord<=mid-(WIDTH/3)? 0:WIDTH/3;
  if (dir == RIGHT)
    cord += cord>=mid+(WIDTH/3)? 0:WIDTH/3;
  return cord;
}
