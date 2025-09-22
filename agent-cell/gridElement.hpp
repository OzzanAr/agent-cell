#pragma once
#include "raylib.h"
#include "globals.hpp"
#include "utils.hpp"
#include <memory>
#include <vector>

class Grid;

class GridElement {
public:
	virtual ~GridElement() = default;

	virtual std::unique_ptr<GridElement> clone() const = 0;
	virtual CellType GetType() const = 0;

	virtual void prepare(Grid& grid) = 0;
	virtual void execute(Grid& grid) = 0;

	Color GetColor() const { return color; }
	int GetValue() const { return value; }

	std::pair<int, int> GetCoordinates() const { return coordinates; }
	void SetCoordinates(int row, int col) { coordinates = std::make_pair(row, col);	}

	void SetValue(int v) { value = v; }

protected:
	Color color;
	int value;
	std::pair<int, int> coordinates;
};