#include <stdio.h>
#include <string>

#include "game_core.h"
#include "graphics_manager.h"

bool loadMedia();

//Frees media and shuts down SDL
void close();

GameCore gGameCore;
GraphicsManager gGraphicsManager;

int main( int argc, char* args[] )
{
	gGraphicsManager.startUp();

	gGameCore.run();

	gGraphicsManager.shutDown();

	return 0;
}
