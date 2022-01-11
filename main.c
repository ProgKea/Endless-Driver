#include "func.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

// TODO: put jerry bar in a seperate file

const int fps = 60;
const int desiredDelta = 1000 / fps;

SDL_Window *win;
SDL_Renderer *renderer;
SDL_Texture *car;
TTF_Font *font;

int car_x;
int mid;
float score;
float score_rate;
float jerry_rate;

extern SDL_Rect jerry_rect_arr[10];
SDL_Texture *jerry_can;
float jerry;

void init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  win = SDL_CreateWindow("Endless Driver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(win, -1, 0);

  // Game elements
  car = IMG_LoadTexture(renderer, IMG_PATH);

  score = 0;
  score_rate = 0.025;

  spawn_jerry(0);
  jerry = 150;
  jerry_rate = 0.05;
  jerry_can = IMG_LoadTexture(renderer, "data/jerrycan.png");

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
    drawRect(renderer, ROAD_X, 0, ROAD_WIDTH, HEIGHT, 80, 80, 80); // Road
    drawImgRect(renderer, jerry_rect_arr[0], jerry_can, false); // Jerry can
    drawRect(renderer, 10, 225, (int)jerry, 20, 100, 25, 0); // Jerry bar
    drawTexture(renderer, car_x, 600, 60, 110, car, true);   // Car
    render_score(renderer, score);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderPresent(renderer);

    score += score_rate;
    jerry -= jerry_rate;

    int delta = SDL_GetTicks() - startLoop;
    if (delta < desiredDelta)
      SDL_Delay(desiredDelta-delta);
  }
  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
  return 0;
}
