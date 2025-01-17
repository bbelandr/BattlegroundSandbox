#include "Game.h"
#include <iostream>
#include <cstdio>

Game::Game(const int flags) {
	this->flags = flags;
	
	// SDL init
	SDL_Init(SDL_INIT_EVERYTHING);
	running = true;
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	backgroundColor.r = 0;
	backgroundColor.g = 0;
	backgroundColor.b = 0;
	backgroundColor.a = 255;

	// Board init
	Object* test = new Object(10, 10);
	objects.push_back(*test);
	endOfLastUpdate = std::chrono::steady_clock::now();		// For deltatime calculations
	deltaTime = 0;
}

Game::~Game() {
	// Removing all Objects from the object vector
	for (size_t i = 0; i < objects.size(); i++) {
		delete &objects[i];
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int Game::handleEvents() {
	if (DEBUG_INPUT & flags)
		std::cout << "Reading Input!" << std::endl;
	SDL_Event event;
	SDL_PollEvent(&event);
	
	switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
	}
	return 0;
}

int Game::update() {
	// Deltatime
	auto start = std::chrono::steady_clock::now();
	deltaTime = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(start - endOfLastUpdate).count() / 1000;
	if (DEBUG_UPDATE & flags) std::cout << "Deltatime = " << deltaTime << " seconds" << std::endl;
	
	// Update objects
	if (DEBUG_UPDATE & flags) std::cout << "Calculating Object Updates!" << std::endl;
	objects[0].x = objects[0].x + 20 * deltaTime;

	endOfLastUpdate = std::chrono::steady_clock::now();
	return 0;
}

int Game::render() {
	SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
	SDL_RenderClear(renderer);
	if (DEBUG_RENDERER & flags) {
		std::cout << "Rendering to the Screen!" << std::endl;
		std::cout << "Number of Objects in object vector = " << objects.size() << std::endl;
	}

	for (auto i = 0; i < objects.size(); i++) {
		if (DEBUG_RENDERER & flags) std::cout << "\tDrawing object " << i << std::endl;
		if (DEBUG_RENDERER & flags) printf("\t\tColor = (%d, %d, %d, %d)\n", objects[i].color.r, objects[i].color.g, objects[i].color.b, objects[i].color.a);
		if (DEBUG_RENDERER & flags) printf("\t\tCoordinate = (%f, %f)\n", objects[i].x, objects[i].y);
		SDL_SetRenderDrawColor(renderer, objects[i].color.r, objects[i].color.g, objects[i].color.b, objects[i].color.a);
		SDL_RenderDrawPoint(renderer, (int)objects[i].x, (int)objects[i].y);
	}

	SDL_RenderPresent(renderer);
	return 0;
}

void Game::setBackgroundColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
	backgroundColor.r = r;
	backgroundColor.g = g;
	backgroundColor.b = b;
	backgroundColor.a = a;
}

bool Game::isRunning() {
	return running;
}