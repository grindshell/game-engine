#include <string>

#include <SDL2/SDL.h>

#include "graphics_manager.h"

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gSurface = NULL;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool GraphicsManager::startUp () {
	GraphicsManager::initializeSDL();
	GraphicsManager::createWindow();
	GraphicsManager::loadAssets();

	return true;
}

bool GraphicsManager::initializeSDL() {
	bool success = true;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}

	return success;
}

bool GraphicsManager::createWindow() {
	bool success = true;

	gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( gWindow == NULL )
	{
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		gScreenSurface = SDL_GetWindowSurface( gWindow );
	}

	return success;
}

bool GraphicsManager::render() {
	SDL_UpdateWindowSurface( gWindow );

	return true;
}

bool GraphicsManager::loadAssets() {
	bool success = true;

	gSurface = loadSurface( "stretch.bmp" );
	if( gSurface == NULL )
	{
		printf( "Failed to load stretching image!\n" );
		success = false;
	}

	return success;
}

SDL_Surface* GraphicsManager::loadSurface( std::string path )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

void GraphicsManager::shutDown()
{
	SDL_FreeSurface( gSurface );
	gSurface = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}
