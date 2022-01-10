#include "func.h"
#include <SDL2/SDL_error.h>
#include <stdio.h>

const int fps = 60;
const int desiredDelta = 1000 / fps;

SDL_Window *win;
SDL_Renderer *renderer;
SDL_Texture *car;

TTF_Font *font;

int car_x;
int mid;
float score;

void init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  win = SDL_CreateWindow("Endless Driver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(win, -1, 0);
  car = IMG_LoadTexture(renderer, IMG_PATH);
  score = 0;
  font = TTF_OpenFont("data/teletactile-font.ttf", FONT_SIZE);

  // Error printing 
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("SDL_Init failed %s\n", SDL_GetError());
  }
  if (win == NULL) {
    printf("SDL_CreateWindow failed %s\n", SDL_GetError());
  }
  if (renderer == NULL) {
    printf("SDL_CreateRenderer failed %s\n", SDL_GetError());
  }
  if (car == NULL) {
    printf("IMG_LoadTexture failed %s\n", SDL_GetError());
  }

  mid = getmid(60);
  car_x = mid;
}

int main()
{
  init();

  while (1) {
    int startLoop = SDL_GetTicks();
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
	      break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
	      break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT)
        car_x = move(LEFT, car_x, mid); 
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT)
        car_x = move(RIGHT, car_x, mid);
    }
    SDL_RenderClear(renderer);
    drawTexture(car_x, 600, 60, 110, car, renderer, true);
    render_score(renderer, score);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderPresent(renderer);

    score += 0.05;

    int delta = SDL_GetTicks() - startLoop;
    if (delta < desiredDelta)
      SDL_Delay(desiredDelta-delta);
  }
  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
  return 0;
}
