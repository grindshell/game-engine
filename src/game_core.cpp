#include <stdio.h>
#include <SDL2/SDL.h>

#include "game_core.h"

void GameCore::run () {
    running = true;

    SDL_Event e;

    while(running) {
		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				running = false;
			}
		}
    }
}

