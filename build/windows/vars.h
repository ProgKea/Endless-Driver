#ifndef VARS_H
#define VARS_H
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_mixer.h>
extern SDL_Window *win;
extern SDL_Renderer *renderer;
extern bool is_in_game;

// Menu values
extern SDL_Surface *textSurface;
extern SDL_Texture *textTexture;
extern SDL_Color selected_item_color;
extern SDL_Color font_color;
extern bool is_main_menu;
extern const char *menu_items[2];
extern int item_index;

// car values
extern SDL_Texture *car;
extern SDL_Rect car_rect;
extern int car_x;
extern int car_mid;
extern int speed;

// score values
extern SDL_Surface *scoreSurface;
extern SDL_Texture *scoreTexture;
extern float score;
extern float score_rate;

// jerry values
extern float jerry_rate;
extern SDL_Rect jerry_rect_arr[10];
extern SDL_Texture *jerry_can;
extern float jerry;
extern float jerry_max;
extern float jerry_content;

// cone values
extern SDL_Texture *cone;
extern SDL_Rect cone_rect_arr[10];

// audio values
extern Mix_Chunk *collect_sound_effect;
extern Mix_Chunk *explosion;
extern Mix_Music *main_music;
extern Mix_Music *menu_music;
#endif
