#pragma once
#include "raylib.h"

class GridElement {
public:
	GridElement();
	Color GetColor() { return color; }
	int GetValue() { return value; }

protected:
	Color color = GRAY;
	int value = 0;
};