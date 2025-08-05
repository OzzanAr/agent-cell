#include "bunny.hpp"
#include "grid.hpp"

void Bunny::prepare(Grid& grid) {
	age++;
	energy--;

	if (energy <= 0) {
		return;
	}
}

void Bunny::execute(Grid& grid) {
	if (energy <= 0 || age > 9) {
		grid.RemoveElement(coordinates.first, coordinates.second);
		return;
	}

	int row = coordinates.first;
	int col = coordinates.second;
	int newCol = col + 1;

	if (newCol >= grid.GetColumns()) return;

	GridElement* target = grid.GetAgentAt(row, newCol);
	if (target->GetType() == CellType::EMPTYCELL) {
		grid.MoveElement(row, col, row, newCol);
		coordinates = { row, newCol };
	}
}
