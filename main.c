#include "func.h"
#include "vars.h"

// TODO: create losing logic
// TODO: create logic for spawning jerrycans
// TODO: create obstacles
// TODO: end the game when hitting a obstacle

const int fps = 60;
const int desiredDelta = 1000 / fps;

int main()
{
  init_everything();

  // game loop
  while (1) {
    int startLoop = SDL_GetTicks();

    // user input
    SDL_Event e;
    if (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
	      break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
	      break;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT)
        car_rect.x = move(LEFT, car_rect.x, car_mid); 
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT)
        car_rect.x = move(RIGHT, car_rect.x, car_mid);
    }

    // Render game
    SDL_RenderClear(renderer);
    drawRect(renderer, ROAD_X, 0, ROAD_WIDTH, HEIGHT, 80, 80, 80); // Road
    for (int i=0; i<(sizeof(jerry_rect_arr)/sizeof(jerry_rect_arr[0])); i++) {
      drawImgRect(renderer, jerry_rect_arr[i], jerry_can); // jerry_can
    }
    drawRect(renderer, 10, 225, (int)jerry, 20, 100, 25, 0); // Jerry bar
    drawImgRectRotated(renderer, car_rect, car); // car
    render_score(renderer, score); 
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // background colour
    SDL_RenderPresent(renderer);

    // update score and jerry
    score += score_rate;
    jerry -= jerry_rate;

    // driving (moving objects)
    for (int i=0; i<(sizeof(jerry_rect_arr)/sizeof(jerry_rect_arr[0])); i++) {
      jerry_rect_arr[i].y+=speed;
      if (check_collision(jerry_rect_arr[i], car_rect)) {
        spawn_jerry(i);
        jerry += jerry_content;
      }
    }

    // ending game if jerry is empty or car collides with obstacle
    if (jerry <= 0) 
      end_game();

    // limit jerry
    if (jerry > jerry_max)
      jerry = jerry_max;

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
