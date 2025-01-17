#include "Object.h"

Object::Object(int x, int y) {
	this->x = x;
	this->y = y;
	color.r = 0;
	color.g = 255;
	color.b = 0;
	color.a = 255;
	isVisible = true;
	type = FOOTMAN;
}