#pragma once
#include <vector>
#include "Object.h"
#include "SDL.h"

class Game {

public:
	Game();						// Initializes the screen as well as the initial placements for spawners
	~Game();
	int getInput();
	int update();
	int render();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<Object> objects;
};

