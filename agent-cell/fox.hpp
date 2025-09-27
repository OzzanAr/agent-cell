#pragma once
#include "gridElement.hpp"

class Fox : public GridElement {
public:
	Fox(int row, int column) {
		color = RED;
		isSeen = false;
		SetCoordinates(row, column);
	}

	void prepare(Grid&) override {
		// Skip for now
	}

	void execute(Grid&) override {
		// Skip for now
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
