#pragma once

enum UNIT_TYPE {
	FOOTMAN,
	BARRIERMAN,
	COMMANDER,
	BUILDER,
	SPAWNPOINT
};

struct Color {
	unsigned char r, g, b, a;	// RGB and alpha for opacity
};

class Object {	// I'm making all of this public for ease
public:
	int x, y;
	UNIT_TYPE type;
	bool isVisible;
	Color color;

	Object(int x, int y);
};
