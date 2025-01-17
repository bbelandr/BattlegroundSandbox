#include "Game.h"
#include <iostream>

Game::Game() {
	// SDL init
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	// Board init
	Object* test = new Object(10, 10);
	objects.push_back(*test);
}

Game::~Game() {
	// Removing all Objects from the object vector
	for (size_t i = 0; i < objects.size(); i++) {
		delete objects[i];
	}
}

int Game::getInput() {
	std::cout << "Reading Input!" << std::endl;
	return 0;
}

int Game::update() {
	std::cout << "Calculating Object Updates!" << std::endl;
	return 0;
}

int Game::render() {
	std::cout << "Rendering to the Screen!" << std::endl;
	return 0;
}
