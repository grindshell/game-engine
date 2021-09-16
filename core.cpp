#include <stdio.h>
#include <SDL2/SDL.h>

#include "core.h"

void Core::run () {
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

