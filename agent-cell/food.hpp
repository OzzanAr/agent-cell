#pragma once
#include "gridElement.hpp"

class Food : public GridElement {
public:
	Food() {
		value = 3;
		color = GREEN;
	}

	std::unique_ptr<GridElement> clone() const override {
		return std::make_unique<Food>(*this);
	}

	CellType GetType() const override {
		return CellType::FOOD;
	}
};
