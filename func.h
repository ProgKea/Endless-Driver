#ifndef FUNC_H
#define FUNC_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_mixer.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define HEIGHT 750
#define WIDTH 1260

#define FONT_SIZE HEIGHT/10

#define ROAD_X 40
#define ROAD_WIDTH WIDTH-ROAD_X*2

#define LEFT 0
#define RIGHT 1

#define DEFAULT_SPEED 8

#define FONT_PATH "data/teletactile-font.ttf"

void free_resources();
int getmid(int w);

/* Random numbers */
int generate_random_int(int range);
int generate_random_negative_int(int range);

/* Drawing */
void drawTexture(SDL_Renderer *renderer, int x, int y, int h, int w, SDL_Texture *img);
void drawTextureRotated(SDL_Renderer *renderer, int x, int y, int h, int w, SDL_Texture *img);
void drawImgRect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Texture *tex);
void drawImgRectRotated(SDL_Renderer *renderer, SDL_Rect rect, SDL_Texture *tex);
void drawRect(SDL_Renderer *renderer, int x, int y, int w, int h, int r, int g, int b);

/* Game elements */
// init
void init_jerry_can();
void init_score();
void init_car();
void init_everything();

// rendering
void render_jerry_bar();
void render_score(float score);
void render_text_mid(const char *text, int y, int w, int h, SDL_Color color);
void render_text_mid_list(const char *text[], int y, int w, int h, SDL_Color color);

// Game logic
int move(int dir, int cord, int mid);
void spawn_jerry(int index);
void spawn_cone(int index);
bool check_collision(SDL_Rect rect_a, SDL_Rect rect_b);
void jerry_overflow_speed();
void end_game();
// Menu functions
// void render_text(const char *text, int x, int y, int w, int h);
void start_game();
void quit_game();
void move_up();
void move_down();
#endif
