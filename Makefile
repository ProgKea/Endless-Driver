CC=gcc
SDL2FLAGS=$(shell pkg-config sdl2 --cflags --libs) -lSDL2_image -lSDL2_ttf
CFLAGS=-Wall -pedantic -Werror -Wshadow

endless-driver: main.c
	${CC} ${CFLAGS} -O2 -o endless-driver main.c func.c score.c ${SDL2FLAGS}
