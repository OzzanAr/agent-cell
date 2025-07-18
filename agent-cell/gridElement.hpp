#pragma once
#include "raylib.h"
#include "globals.hpp"
#include <memory>
#include <vector>

class GridElement {
public:
	virtual std::unique_ptr<GridElement> clone() const = 0;

	virtual ~GridElement() = default;

	Color GetColor() const { return color; }
	int GetValue() const { return value; }

	void SetValue(int v) { value = v; }

	std::pair<int, int> GetCoordinates();

protected:
	Color color;
	int value;
};