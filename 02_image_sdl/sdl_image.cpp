#include <SDL2/SDL.h>

const int SCREEN_WIDTH=800;
const int SCREEN_HEIGHT=800;

SDL_Window*  window =NULL;
SDL_Surface* surface=NULL;
SDL_Surface* imgSurface=NULL;

bool init(){

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Image Loader", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//keep runnning
	surface = SDL_GetWindowSurface(window);
	return true;
}

bool loadImage(){
	imgSurface = SDL_LoadBMP("img.bmp");
	return true;
}

void close(){
	SDL_FreeSurface(imgSurface);
	imgSurface = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}

int main(int argc, char* args[]){

	init();
	// do stuff with surface
	// update surface
	
	//run until stopped
	SDL_Event e;
	bool quit = false;
	int color= 0xFF;
	while(!quit){
		//keep runnning
		loadImage();
		surface = SDL_GetWindowSurface(window);
		int R = (color);
		int G = (color);
		int B = (color);
		
		//printf("colors: %d, %d, %d", R, G, B);
		//SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, R, G, B));
		SDL_BlitSurface(imgSurface, NULL, surface, NULL);
		SDL_UpdateWindowSurface(window);
		if(SDL_PollEvent(&e) && e.type==SDL_QUIT){
			quit=true;
		}
	}
	close();
	return 0;
}
