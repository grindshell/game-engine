#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics_manager.h"

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool GraphicsManager::startUp () {
	this->initializeSDL();
	this->createWindow();
	this->render();

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

	//Set texture filtering to linear
	if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
	{
		printf( "Warning: Linear texture filtering not enabled!" );
	}

	gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( gWindow == NULL )
	{
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create renderer for window
        gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
        if( gRenderer == NULL )
        {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Initialize renderer color
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
        }
	}

	return success;
}

bool GraphicsManager::render() {
	//Clear screen
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( gRenderer );

	SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0x00 );		

	// 0, 0 is top left
	SDL_Rect leftPaddle = {
		0, // X
		0, // Y
		SCREEN_WIDTH / 32, // width
		SCREEN_HEIGHT / 4 // height
	};

	SDL_Rect rightPaddle = {
		SCREEN_WIDTH - (SCREEN_WIDTH / 32),
		0,
		SCREEN_WIDTH / 32,
		SCREEN_HEIGHT / 4
	};

	SDL_RenderFillRect( gRenderer, &leftPaddle );
	SDL_RenderFillRect( gRenderer, &rightPaddle );

	//Update screen
	SDL_RenderPresent( gRenderer );

	return true;
}

void GraphicsManager::shutDown()
{
    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
