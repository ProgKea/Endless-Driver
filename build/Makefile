CC=gcc
CC_CROSS=x86_64-w64-mingw32-gcc
LIBS=`pkg-config --cflags --libs sdl2` -lSDL2_image -lSDL2_mixer -lSDL2_ttf
CFLAGS=-Wall -pedantic -Wshadow -Werror
CFLAGS_CROSS=-mwindows
DEPENDENCIES=../src/main.c ../src/func.c ../src/game_elements.c
PROJECT=endless-driver

endless-driver: ${DEPENDENCIES}
	${CC} ${CFLAGS} ${DEPENDENCIES} -o ${PROJECT} ${LIBS}

cross: ${DEPENDENCIES}
	${CC_CROSS} ${CFLAGS} ${CFLAGS_CROSS} ${DEPENDENCIES} -o windows/${PROJECT} ${LIBS}

release: ${DEPENDENCIES}
	${CC} ${CFLAGS} -O4 ../src/*.c -o ${PROJECT} ${LIBS} && ${CC_CROSS} ${CFLAGS} ${CFLAGS_CROSS} -O4 ${DEPENDENCIES} -o windows/${PROJECT} ${LIBS}

run: 
	make && ./endless-driver

