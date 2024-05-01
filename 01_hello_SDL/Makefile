#OBJS specifies which files to compile as a part of the project
OBJS = 01_hello_SDL.cpp

CC = g++

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2

#OBJS_NAME specifies the name of executable
OBJS_NAME = hello_sdl 

all:$(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJS_NAME)
