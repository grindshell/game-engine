#include <SDL2/SDL.h>

#ifndef GRAPHICS_MANAGER_H
#define GRAPHICS_MANAGER_H
class GraphicsManager {
public:
	bool startUp();
	void shutDown();
	bool render();
private:
	bool initializeSDL();
	bool loadAssets();
	bool createWindow();
	SDL_Surface* loadSurface( std::string path );
};
#endif
