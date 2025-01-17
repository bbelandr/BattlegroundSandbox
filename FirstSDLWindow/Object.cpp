#include "Object.h"

Object::Object(float x, float y) {
	this->x = x;
	this->y = y;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
	isVisible = true;
	type = FOOTMAN;
}