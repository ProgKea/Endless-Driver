CC=gcc
SDL2FLAGS=$(shell pkg-config sdl2 --cflags --libs) -lSDL2_image -lSDL2_ttf -lSDL2_mixer
CFLAGS=-Wall -pedantic -Werror -Wshadow

endless-driver: main.c
	${CC} ${CFLAGS} -O2 -o endless-driver main.c func.c game_elements.c ${SDL2FLAGS}
