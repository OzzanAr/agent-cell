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

	DetermineMove(grid);
}

void Bunny::DetermineMove(Grid& grid)
{
	std::vector<std::pair<int, int>> validMoves;
	int newRow, newColumn;

	for (const auto& offset : neighborOffsets) {
		newRow = coordinates.first + offset.first;
		newColumn = coordinates.second + offset.second;

		if (!grid.IsCellEmpty(newRow, newColumn)) continue;

		validMoves.push_back({ newRow, newColumn });
	}

	if (!validMoves.empty()) {
		int index = GetRandomValue(0, validMoves.size() - 1);
		std::pair<int, int> move = validMoves[index];

		grid.MoveElement(coordinates.first, coordinates.second, move.first, move.second);
		SetCoordinates(move.first, move.second);
	}
}
