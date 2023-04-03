/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
//	//The window we'll be rendering to
//	SDL_Window* window = NULL;
//
//	//The surface contained by the window
//	SDL_Surface* screenSurface = NULL;
//
//	//Initialize SDL
//	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
//	{
//		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
//	}
//	else
//	{
//		//Create window
//		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//		if( window == NULL )
//		{
//			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
//		}
//		else
//		{
//			//Get window surface
//			screenSurface = SDL_GetWindowSurface( window );
//
//			//Fill the surface white
//			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
//
//			//Update the surface
//			SDL_UpdateWindowSurface( window );
//
//			//Wait two seconds
//			//SDL_Delay( 2000 );
//		}
//	}
//
//	//Destroy window
//	//SDL_DestroyWindow( window );
//
//	//Quit SDL subsystems
//	//SDL_Quit();
    SDL_Window * window = nullptr;

        SDL_Surface * window_surface = nullptr;
        SDL_Surface * image_surface = nullptr;

        SDL_Init(SDL_INIT_VIDEO);

        window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

        window_surface = SDL_GetWindowSurface(window);
        image_surface = SDL_LoadBMP("image.bmp");

        SDL_BlitSurface(image_surface, NULL, window_surface, NULL);

        SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }
    }


        SDL_DestroyWindow(window);
        SDL_FreeSurface(image_surface);
        SDL_Quit();
	return 0;
}
