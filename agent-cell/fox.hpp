#pragma once
#include "gridElement.hpp"

class Fox : public GridElement {
public:
	Fox() {
		value = 2;
		color = RED;
		isSeen = false;
	}

	std::unique_ptr<GridElement> clone() const override {
		return std::make_unique<Fox>(*this);
	}

	CellType GetType() const override {
		return CellType::FOX;
	}

private:
	bool isSeen;
};
