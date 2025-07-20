#pragma once
#include "gridElement.hpp"

class Grid;

class Bunny : public GridElement {
public:
	Bunny(int row, int column) {
		value = 1;
		color = PINK;
		isSeen = false;
		SetCoordinates(row, column);
	}

	void prepare(Grid&) override {
		// Skip for now
	}

	void execute(Grid& grid) override;

	std::unique_ptr<GridElement> clone() const override {
		return std::make_unique<Bunny>(*this);
	}

	CellType GetType() const override {
		return CellType::BUNNY;
	}

private:
	bool isSeen;
};