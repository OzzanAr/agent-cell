#include "bunny.hpp"
#include "grid.hpp"

void Bunny::execute(Grid& grid) {
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
