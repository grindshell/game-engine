#include <stdio.h>
#include <string>

#include "game_core.h"
#include "graphics_manager.h"

GameCore gGameCore;
GraphicsManager gGraphicsManager;

int main( int argc, char* args[] )
{
	gGraphicsManager.startUp();

	gGameCore.run();

	gGraphicsManager.shutDown();

	return 0;
}
