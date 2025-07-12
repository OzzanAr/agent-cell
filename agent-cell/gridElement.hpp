#pragma once
#include "raylib.h"
#include "globals.hpp"

class GridElement {
public:
	GridElement() : color(CUSTOM_GREY), value(0) {}

	Color GetColor() const { return color; }
	int GetValue() const { return value; }

	void SetValue(int v) { value = v; }

protected:
	Color color;
	int value;
};