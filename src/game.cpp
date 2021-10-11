#include <stdio.h>
#include <string>
#include <list>

#include "actor.h"
#include "game_core.h"
#include "graphics_manager.h"

GameCore gGameCore;
GraphicsManager gGraphicsManager;

int main( int argc, char* args[] )
{
	gGraphicsManager.startUp();

	std::list<Actor> actors = {};
	actors.push_back(Actor(0,0));

	gGameCore.setActors(actors);
	gGameCore.run();

	gGraphicsManager.shutDown();

	return 0;
}
