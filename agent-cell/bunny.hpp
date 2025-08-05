#pragma once
#include "gridElement.hpp"

class Grid;

class Bunny : public GridElement {
public:
	Bunny(int row, int column) : age(0), energy(10), reproductionCooldown(0),
		facing(Direction::NORTH), wantsToReproduce(false) {
		value = 1;
		color = PINK;
		SetCoordinates(row, column);
	}

	void prepare(Grid&) override;

	void execute(Grid& grid) override;

	std::unique_ptr<GridElement> clone() const override {
		return std::make_unique<Bunny>(*this);
	}

	CellType GetType() const override {
		return CellType::BUNNY;
	}

private:
	int age;
	int energy;
	int reproductionCooldown;
	Direction facing;
	bool wantsToReproduce;

};