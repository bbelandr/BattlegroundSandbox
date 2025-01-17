#pragma once
#include <vector>
#include "Object.h"
#include "SDL.h"
#include <chrono>

enum Flags {
	DEBUG_INPUT		= 1 << 0,
	DEBUG_UPDATE	= 1 << 1,
	DEBUG_RENDERER	= 1 << 2
};

class Game {

public:
	Game(const int flags);						// Initializes the screen as well as the initial placements for spawners
	~Game();
	int handleEvents();
	int update();
	int render();
	void setBackgroundColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	bool isRunning();

private:
	Color backgroundColor;						// The default color for the background is black
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<Object> objects;

	std::chrono::steady_clock::time_point endOfLastUpdate;
	float deltaTime;							// Deltatime is measured in seconds

	int flags;
	bool running;
};

