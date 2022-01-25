#include "func.h"
#include <SDL2/SDL_image.h>

SDL_Window *win;
SDL_Renderer *renderer;

// Font values;
SDL_Color font_color = {255, 255, 255};
TTF_Font *score_font;

// Score values
float score;
float score_rate;
SDL_Surface *scoreSurface;
SDL_Texture *scoreTexture;

// jerry values
SDL_Texture *jerry_can;
SDL_Rect jerry_rect_arr[10];
float jerry, jerry_max, jerry_rate, jerry_content;

// cone values
SDL_Texture *cone;
SDL_Rect cone_rect_arr[10];

// spawn values for cone and jerry
int spawn_pos[3] = {WIDTH/3, -WIDTH/3, 0};

// car values
int car_x, car_mid, speed;
SDL_Texture *car;
SDL_Rect car_rect;

void init_jerry_can() {
  jerry = jerry_max = 120;
  jerry_content = 20;
  jerry_rate = 0.1;
  jerry_can = IMG_LoadTexture(renderer, "data/jerrycan.png");
  spawn_jerry(0);
}

void init_score() {
  score = 0;
  score_rate = 0.025;
  score_font = TTF_OpenFont("data/teletactile-font.ttf", FONT_SIZE);
}

void init_cone() {
  cone = IMG_LoadTexture(renderer, "data/barrier.png");
  spawn_cone(0);
}

void init_car() {
  car = IMG_LoadTexture(renderer, "data/car5.png");
  car_rect.w = 60;
  car_rect.h = 110;
  car_rect.x = getmid(60);
  car_rect.y = 600;
  car_mid = getmid(car_rect.w);
  speed = 5;
}

void check_sdl_errors() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("SDL_Init failed %s\n", SDL_GetError());
    exit(1);
  }
  if (win == NULL) {
    printf("SDL_CreateWindow failed %s\n", SDL_GetError());
    exit(1);
  }
  if (renderer == NULL) {
    printf("SDL_CreateRenderer failed %s\n", SDL_GetError());
    exit(1);
  }
  if (car == NULL) {
    printf("IMG_LoadTexture failed %s\n", SDL_GetError());
    exit(1);
  }
}

void init_everything() {
  // set seed for random values
  srand(time(NULL));
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  win = SDL_CreateWindow("Endless Driver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(win, -1, 0);

  // Game elements
  init_car();
  init_jerry_can();
  init_cone();
  init_score();

  check_sdl_errors();
}

void end_game() {
  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(car);
  SDL_DestroyTexture(jerry_can);
  SDL_DestroyTexture(scoreTexture);
  exit(0);
}

void render_score(SDL_Renderer *Renderer, float score_int) {
  char score_char[5];
  sprintf(score_char, "%.0f", score);
  scoreSurface = TTF_RenderText_Solid(score_font, score_char, font_color);
  scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
  drawTexture(renderer, getmid(FONT_SIZE), FONT_SIZE, FONT_SIZE, FONT_SIZE, scoreTexture);
  SDL_FreeSurface(scoreSurface);
  SDL_DestroyTexture(scoreTexture);
}

// Game logic
void spawn_jerry(int index) {
  SDL_Rect jerry_rect;
  jerry_rect.w = 40;
  jerry_rect.h = 50;
  jerry_rect.x = (WIDTH/2-jerry_rect.w/2) + spawn_pos[rand()%3];
  jerry_rect.y = -jerry_rect.h;
  jerry_rect_arr[index] = jerry_rect;
}

void spawn_cone(int index) {
  SDL_Rect cone_rect;
  cone_rect.w = 50;
  cone_rect.h = 50;
  cone_rect.x = (WIDTH/2-cone_rect.w/2) + spawn_pos[rand()%3];
  cone_rect.y = -cone_rect.h;
  cone_rect_arr[index] = cone_rect;
}

bool check_collision(SDL_Rect rect_a, SDL_Rect rect_b) {
  if (rect_a.x > rect_b.x && rect_a.x < rect_b.x + rect_b.w && rect_a.y+rect_b.h/2-speed > rect_b.y && rect_a.y < rect_b.y+rect_b.h)
    return true;
  return false;
}
