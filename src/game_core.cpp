#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "actor.h"
#include "game_core.h"
#include "graphics_manager.h"

void GameCore::setActors(std::list<Actor> actors)
{
	this->actors = actors;
}

void GameCore::run ()
{
    running = true;

    SDL_Event e;
	std::list<Actor>::iterator ait;

    while(running) {
		for (ait = actors.begin(); ait != actors.end(); ++ait){
			std::cout << ait->to_string() << "\n" << std::flush;
		}

		while( SDL_PollEvent( &e ) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				running = false;
			}
		}
    }
}
