#include "func.h"

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
float jerry;
float jerry_rate;
int jerry_pos[3] = {WIDTH/3, -WIDTH/3, 0};

// car values
int car_x, car_mid;
SDL_Texture *car;

void init_jerry_can() {
  jerry = 150;
  jerry_rate = 0.05;
  jerry_can = IMG_LoadTexture(renderer, "data/jerrycan.png");
}

void init_score() {
  score = 0;
  score_rate = 0.025;
  score_font = TTF_OpenFont("data/teletactile-font.ttf", FONT_SIZE);
}

void init_car() {
  car = IMG_LoadTexture(renderer, IMG_PATH);
  car_x = getmid(60);
  car_mid = getmid(60);
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
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  win = SDL_CreateWindow("Endless Driver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(win, -1, 0);

  // Game elements
  init_car();
  init_jerry_can();
  init_score();

  check_sdl_errors();
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


void spawn_jerry(int index) {
  srand(time(NULL));
  SDL_Rect jerry_rect;
  jerry_rect.w = 40;
  jerry_rect.h = 50;
  jerry_rect.x = (WIDTH/2-jerry_rect.w/2) + jerry_pos[rand()%3];
  jerry_rect.y = -jerry_rect.h;
  jerry_rect_arr[index] = jerry_rect;
}
