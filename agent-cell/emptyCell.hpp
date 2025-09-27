#pragma once
#include "gridElement.hpp"

class EmptyCell : public GridElement {
public:
	EmptyCell() {
		color = CUSTOM_GREY;
	}

	void prepare(Grid&) override {
		// Skip for now
	}

	void execute(Grid&) override {
		// Skip for now
	}

	std::unique_ptr<GridElement> clone() const override {
		return std::make_unique<EmptyCell>(*this);
	}

	CellType GetType() const override {
		return CellType::EMPTYCELL;
	}
};