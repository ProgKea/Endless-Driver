#include "func.h"
#include "vars.h"

// TODO: create logic for spawning objects
// TODO: create highscore saving system 
// TODO: create game over screen with a restart button
// TODO: add function jerry_overflow_speed that checks if the jerry is over the limit and if it is than give the car a speed based on the overflowing jerry lol

const int fps = 60;
const int desiredDelta = 1000 / fps;
int startLoop;

int WinMain(int argc, char *argv[]) {
  init_everything();

  // game loop
  while (1) {
    startLoop = SDL_GetTicks();
    if (is_in_game) {

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
      render_jerry_bar();
      drawImgRectRotated(renderer, car_rect, car); // car
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
        } else if (jerry_rect_arr[0].y > HEIGHT+jerry_rect_arr[i].h) {
          spawn_jerry(0);
        }
      }
      // cones
      for (int i=0; i<(sizeof(cone_rect_arr)/sizeof(cone_rect_arr[0])); i++) {
        cone_rect_arr[i].y+=speed;
        if (check_collision(cone_rect_arr[i], car_rect)) {
          Mix_PlayChannel(-1, explosion, 0);
          end_game();
        } else if (cone_rect_arr[0].y > HEIGHT+cone_rect_arr[i].h) {
          spawn_cone(0);
        }
      }

      // ending game if jerry is empty or car collides with obstacle
      if (jerry <= 0) 
        end_game();

      if (jerry > jerry_max)
        jerry_overflow_speed();
      else speed = DEFAULT_SPEED;
    } 

    else if (is_main_menu) {
      SDL_Event e;
      if (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT)
          break;
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
          break;
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && item_index == 0)
          start_game();
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN && item_index == 3)
          quit_game();
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_DOWN)
          move_down();
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP)
          move_up();
      }
      SDL_RenderClear(renderer);
      SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // background colour
      SDL_RenderPresent(renderer);
    }
    int delta = SDL_GetTicks() - startLoop;
    if (delta < desiredDelta)
      SDL_Delay(desiredDelta-delta);
  }
  free_resources();
  return 0;
}
