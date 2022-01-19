#include "func.h"
#include "vars.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

// TODO: create logic for spawning jerrycans
// TODO: create obstacles
// TODO: refill jerry bar when picking up jerry cans
// TODO: end the game when hitting a obstacle
// TODO: refactor

const int fps = 60;
const int desiredDelta = 1000 / fps;

int main()
{
  init_everything();

  // game loop
  while (1) {
    int startLoop = SDL_GetTicks();
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
	      break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
	      break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT)
        car_x = move(LEFT, car_x, car_mid); 
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT)
        car_x = move(RIGHT, car_x, car_mid);
    }

    // Render game
    SDL_RenderClear(renderer);
    drawRect(renderer, ROAD_X, 0, ROAD_WIDTH, HEIGHT, 80, 80, 80); // Road
    drawRect(renderer, 10, 225, (int)jerry, 20, 100, 25, 0); // Jerry bar
    drawTextureRotated(renderer, car_x, 600, 60, 110, car);   // Car
    render_score(renderer, score);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderPresent(renderer);

    // update score and jerry
    score += score_rate;
    jerry -= jerry_rate;

    int delta = SDL_GetTicks() - startLoop;
    if (delta < desiredDelta)
      SDL_Delay(desiredDelta-delta);
  }
  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(car);
  SDL_DestroyTexture(jerry_can);
  SDL_DestroyTexture(scoreTexture);
  return 0;
}
