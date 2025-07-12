#pragma once
#include "raylib.h"
#include "globals.hpp"

class GridElement {
public:
	GridElement() : color(CUSTOM_GREY), value(0) {}

	Color GetColor() { return color; }
	void SetValue(int v) { value = v; }
	int GetValue() { return value; }

protected:
	Color color;
	int value;
};