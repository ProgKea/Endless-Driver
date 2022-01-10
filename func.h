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

#define FONT_SIZE 75

#define HEIGHT 750
#define WIDTH 700

#define LEFT 0
#define RIGHT 1

#define IMG_PATH "data/car.png" 
#define FONT_PATH "data/teletactile-font.ttf"

int getmid(int w);
int move(int dir, int cord, int mid);

void drawTexture(int x, int y, int h, int w, SDL_Texture *img, SDL_Renderer *renderer, bool rotate);

// Score
void render_score(SDL_Renderer *renderer, float score);
#endif
