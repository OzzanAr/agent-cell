#include "grass.hpp"
#include "grid.hpp"

void Grass::prepare(Grid& grid) {
	targetSpawn = grid.GetRandomEmptyCell();
}

void Grass::execute(Grid& grid) {
	grid.CreateGrass(targetSpawn.first, targetSpawn.second);
}