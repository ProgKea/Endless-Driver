#ifndef VARS_H
#define VARS_H
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
extern SDL_Window *win;
extern SDL_Renderer *renderer;

extern SDL_Texture *car;
extern int car_x;
extern int car_mid;

extern TTF_Font *score_font;
extern SDL_Surface *scoreSurface;
extern SDL_Texture *scoreTexture;

extern float score;
extern float score_rate;
extern float jerry_rate;

extern SDL_Rect jerry_rect_arr[10];
extern SDL_Texture *jerry_can;
extern float jerry;
#endif
