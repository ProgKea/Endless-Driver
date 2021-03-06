#include "func.h"

SDL_Window *win;
SDL_Renderer *renderer;

// game state
bool is_in_game = false;
bool is_main_menu;
bool is_game_over = false;

/* Menu values */
SDL_Surface *textSurface;
SDL_Texture *textTexture;
SDL_Color selected_item_color = {20, 20, 20};
const char *menu_items[4];
int item_index;
int item_length;

// Font values;
SDL_Color font_color = {255, 255, 255};
TTF_Font *font;

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

/* audio values */
// sound effects
Mix_Chunk *collect_sound_effect;
Mix_Chunk *explosion;
Mix_Chunk *enter;
Mix_Chunk *menuing;

// Music
Mix_Music *main_music;
Mix_Music *menu_music;

void init_jerry_can() {
  jerry = jerry_max = 120;
  jerry_content = 20;
  jerry_rate = 0.1;
  jerry_can = IMG_LoadTexture(renderer, "data/jerrycan.png");
  spawn_jerry(0);
}

void init_score() {
  score = 0;
  score_rate = (float)speed / 320;
  font = TTF_OpenFont("data/teletactile-font.ttf", FONT_SIZE);
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
  speed = DEFAULT_SPEED;
}

void init_menu() {
  is_main_menu = true;
  menu_items[0] = "Play";
  menu_items[1] = "Cars";
  menu_items[2] = "Options";
  menu_items[3] = "Exit";
  item_index = 0;
  item_length = sizeof(menu_items)/sizeof(menu_items[0]);
}

void init_audio() {
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2043);
  collect_sound_effect = Mix_LoadWAV("data/jerry.wav");
  Mix_VolumeChunk(collect_sound_effect, 50);
  explosion = Mix_LoadWAV("data/explo.wav");
  main_music = Mix_LoadMUS("data/mainmusic.mp3");
  menu_music = Mix_LoadMUS("data/menu_music.mp3");
  menuing = Mix_LoadWAV("data/menu.mp3");
  enter = Mix_LoadWAV("data/enter.mp3");
  Mix_PlayMusic(menu_music, -1);
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
  init_menu();
  init_audio();

  check_sdl_errors();
}

void free_resources() {
  SDL_DestroyWindow(win);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(car);
  SDL_DestroyTexture(jerry_can);
  SDL_DestroyTexture(cone);
  SDL_DestroyTexture(scoreTexture);
  Mix_FreeChunk(collect_sound_effect);
  Mix_FreeChunk(explosion);
  Mix_FreeChunk(menuing);
  Mix_FreeChunk(enter);
  Mix_FreeMusic(main_music);
  Mix_FreeMusic(menu_music);
}

void quit_game() {
  free_resources();
  exit(0);
}

void enter_main_menu() {
  Mix_PlayChannel(-1, enter, 0);
  is_game_over = false;
  is_in_game = false;
  is_main_menu = true;
}

void end_game() {
  init_car();
  init_jerry_can();
  init_cone();
  init_score();
  Mix_PlayMusic(menu_music, -1);
  is_main_menu = false;
  is_game_over = true;
  is_in_game = false;
}

void start_game() {
  Mix_PlayChannel(-1, enter, 0);
  Mix_PlayMusic(main_music, -1);
  is_main_menu = false;
  is_game_over = false;
  is_in_game = true;
}

void render_score(float score_int) {
  char score_char[5];
  sprintf(score_char, "%.0f", score);
  scoreSurface = TTF_RenderText_Solid(font, score_char, font_color);
  scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
  drawTexture(renderer, getmid(FONT_SIZE), FONT_SIZE, FONT_SIZE, FONT_SIZE, scoreTexture);
  SDL_FreeSurface(scoreSurface);
  SDL_DestroyTexture(scoreTexture);
}

void render_jerry_bar() {
  if (jerry < jerry_max)
    drawRect(renderer, 10, 225, (int)jerry, 20, 100, 25, 0);
  else drawRect(renderer, 10, 225, (int)jerry, 20, 5, 195, 221);
}

// Game logic
void jerry_overflow_speed() {
  score_rate = (float)speed / 320;
  speed = DEFAULT_SPEED + jerry/20;
}

int move(int dir, int cord, int mid) {
  if (dir == LEFT)
    cord -= cord<=mid-(WIDTH/3)? 0:WIDTH/3;
  if (dir == RIGHT)
    cord += cord>=mid+(WIDTH/3)? 0:WIDTH/3;
  return cord;
}

SDL_Rect create_rect(int width, int height, int x, int y) {
  SDL_Rect rectangle;
  rectangle.w = width;
  rectangle.h = height;
  rectangle.x = x;
  rectangle.y = y;
  return rectangle;
}

void spawn_jerry(int index) {
  SDL_Rect jerry_rect = create_rect(40, 50, (WIDTH/2-40/2) + spawn_pos[rand()%3], generate_random_negative_int(500));
  jerry_rect_arr[index] = jerry_rect;
}

void spawn_cone(int index) {
  SDL_Rect cone_rect = create_rect(50, 50, (WIDTH/2-50/2) + spawn_pos[rand()%3], generate_random_negative_int(500));
  cone_rect_arr[index] = cone_rect;
}

bool check_collision(SDL_Rect rect_a, SDL_Rect rect_b) {
  if (rect_a.x > rect_b.x && rect_a.x < rect_b.x + rect_b.w && rect_a.y+rect_b.h/2-speed > rect_b.y && rect_a.y < rect_b.y+rect_b.h)
    return true;
  return false;
}

// Menu functions
void render_text(const char *text, int x, int y, int w, int h) {
  textSurface = TTF_RenderText_Solid(font, text, font_color);
  textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  drawTexture(renderer, x, y, w*strlen(text), h, textTexture);
  SDL_FreeSurface(textSurface);
  SDL_DestroyTexture(textTexture);
}

void render_text_mid_list(const char *text[], int y, int w, int h, SDL_Color color) {
  for (int i=0; i<item_length; i++) {
    if (item_index == i) {
      textSurface = TTF_RenderText_Solid(font, text[i], color);
    }
    else textSurface = TTF_RenderText_Solid(font, text[i], font_color);
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    drawTexture(renderer, getmid(w*strlen(text[i])), y, w*strlen(text[i]), h, textTexture);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    y+=h;
  }
}

void render_text_mid(const char *text, int y, int w, int h, SDL_Color color) {
  textSurface = TTF_RenderText_Solid(font, text, color);
  textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  drawTexture(renderer, getmid(w*strlen(text)), y, w*strlen(text), h, textTexture);
  SDL_FreeSurface(textSurface);
  SDL_DestroyTexture(textTexture);
}

void move_up() {
  if (item_index > 0) {
    Mix_PlayChannel(-1, menuing, 0);
    item_index--;
  }
}

void move_down() {
  if (item_index < item_length-1) {
    Mix_PlayChannel(-1, menuing, 0);
    item_index++;
  }
}
