#include <SDL2/SDL.h>

const int SCREEN_WIDTH=480;
const int SCREEN_HEIGHT=640;

int main(int argc, char* args[]){
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	// do stuff with surface
	// update surface
	
	//run until stopped
	SDL_Event e;
	bool quit = false;
	int color= 50;
	while(!quit){
		//keep runnning
		surface = SDL_GetWindowSurface(window);
		int R = (color+2)%255;
		int G = (color +10)%255;
		int B = (color +18)%255;
		color = (color +1)%255;
		printf("colors: %d, %d, %d", R, G, B);
		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, R, G, B));
		SDL_UpdateWindowSurface(window);
		if(SDL_PollEvent(&e) && e.type==SDL_QUIT){
			quit=true;
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
