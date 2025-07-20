#pragma once
#include "gridElement.hpp"

class Food : public GridElement {
public:
	Food(int row, int column) {
		value = 3;
		color = GREEN;
		SetCoordinates(row, column);
	}

	void prepare(Grid&) override {
		// Skip for now
	}

	void execute(Grid&) override {
		// Skip for now
	}

	std::unique_ptr<GridElement> clone() const override {
		return std::make_unique<Food>(*this);
	}

	CellType GetType() const override {
		return CellType::FOOD;
	}
};
