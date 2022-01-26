#include "func.h"
#include "vars.h"
#include <SDL2/SDL_mixer.h>

// TODO: create logic for spawning objects
// TODO: add main menu

const int fps = 60;
const int desiredDelta = 1000 / fps;

int main()
{
  init_everything();

  // start main music
  Mix_PlayMusic(main_music, -1);

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
    for (int i=0; i<(sizeof(cone_rect_arr)/sizeof(cone_rect_arr[0])); i++) {
      drawImgRect(renderer, cone_rect_arr[i], cone); // cone
    }
    drawRect(renderer, 10, 225, (int)jerry, 20, 100, 25, 0); // Jerry bar
    drawImgRectRotated(renderer, car_rect, car); // car
    render_score(renderer, score); 
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // background colour
    SDL_RenderPresent(renderer);

    // update score and jerry
    score += score_rate;
    jerry -= jerry_rate;

    /* driving (moving objects) */
    // jerry cans
    for (int i=0; i<(sizeof(jerry_rect_arr)/sizeof(jerry_rect_arr[0])); i++) {
      jerry_rect_arr[i].y+=speed;
      if (check_collision(jerry_rect_arr[i], car_rect)) {
        Mix_PlayChannel(-1, collect_sound_effect, 0);
        spawn_jerry(i);
        jerry += jerry_content;
      }
    }

    // cones
    for (int i=0; i<(sizeof(cone_rect_arr)/sizeof(cone_rect_arr[0])); i++) {
      cone_rect_arr[i].y+=speed;
      if (check_collision(cone_rect_arr[i], car_rect)) {
        Mix_PlayChannel(-1, explosion, 0);
        end_game();
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
  SDL_DestroyTexture(cone);
  SDL_DestroyTexture(scoreTexture);
  Mix_FreeChunk(collect_sound_effect);
  Mix_FreeChunk(explosion);
  Mix_FreeMusic(main_music);
  return 0;
}
