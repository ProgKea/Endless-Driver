#ifndef FUNC_H
#define FUNC_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define FONT_SIZE 75

#define HEIGHT 750
#define WIDTH 700

#define ROAD_WIDTH 620
#define ROAD_X 40

#define LEFT 0
#define RIGHT 1

#define IMG_PATH "data/car.png" 
#define FONT_PATH "data/teletactile-font.ttf"

int getmid(int w);
int move(int dir, int cord, int mid);

// Drawing
void drawTexture(SDL_Renderer *renderer, int x, int y, int h, int w, SDL_Texture *img);
void drawTextureRotated(SDL_Renderer *renderer, int x, int y, int h, int w, SDL_Texture *img);
void drawImgRect(SDL_Renderer *renderer, SDL_Rect rect, SDL_Texture *tex);
void drawImgRectRotated(SDL_Renderer *renderer, SDL_Rect rect, SDL_Texture *tex);
void drawRect(SDL_Renderer *renderer, int x, int y, int w, int h, int r, int g, int b);

// Game elements
void init_jerry_can();
void init_score();
void init_car();
void init_everything();

void render_score(SDL_Renderer *renderer, float score);
void spawn_jerry(int index);
#endif
