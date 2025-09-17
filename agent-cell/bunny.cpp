#include "bunny.hpp"
#include "grid.hpp"

void Bunny::prepare(Grid& grid) {
	age++;
	energy--;

	if (energy <= 0) return;

	if (age >= 1) wantsToReproduce = true;

	if (reproductionCooldown > 0) {
		reproductionCooldown--;
	}

	DetermineMove(grid);
}

void Bunny::execute(Grid& grid) {
	if (energy <= 0 || age > 9) {
		grid.RemoveElement(coordinates.first, coordinates.second);
		return;
	}

	// Handling the behaviors
	// Reproduce(grid);

	grid.MoveElement(coordinates.first, coordinates.second, targetMove.first, targetMove.second);
	SetCoordinates(targetMove.first, targetMove.second);
}

void Bunny::DetermineMove(Grid& grid)
{
	std::vector<std::pair<int, int>> validMoves;
	int newRow, newColumn; 

	for (const auto& offset : utils::GetFacingDirection(facing)) {
		newRow = coordinates.first + offset.first;
		newColumn = coordinates.second + offset.second;

		if (!grid.IsCellEmpty(newRow, newColumn)) continue;

		validMoves.push_back({ newRow, newColumn });
	}

	if (!validMoves.empty()) {
		int index = GetRandomValue(0, validMoves.size() - 1);
		std::pair<int, int> move = validMoves[index];

		targetMove = move;
	}
}

void Bunny::Reproduce(Grid& grid)
{
	if (wantsToReproduce && reproductionCooldown != 0) {
		auto emptyNeighbor = grid.FindEmptyNeighbour(coordinates);

		if (emptyNeighbor) {
			grid.SetCell(emptyNeighbor->first, emptyNeighbor->second, std::make_unique<Bunny>(emptyNeighbor->first, emptyNeighbor->second));
			energy -= 2;
			reproductionCooldown = 6;
		}
	}
}
