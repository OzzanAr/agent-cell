#include "bunny.hpp"
#include "grid.hpp"

void Bunny::execute(Grid& grid) {
	int row = coordinates.first;
	int col = coordinates.second;
	int newCol = col + 1;

	// Check bounds
	if (newCol >= grid.GetColumns()) return;

	// Check if right cell is empty
	GridElement* target = grid.GetAgentAt(row, newCol);
	if (target->GetType() == CellType::EMPTYCELL) {
		// Move: place a new Bunny in the right cell
		grid.SetCell(row, newCol, std::move(grid.cells[row][col]));
		// Replace old cell with Empty
		grid.SetCell(row, col, std::make_unique<EmptyCell>());
		coordinates = { row, newCol };
	}
}
