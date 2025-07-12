#pragma once
#include "gridElement.hpp"

class EmptyCell : public GridElement {
public:
	EmptyCell() {
		value = 0;
		color = CUSTOM_GREY;
	}

	std::unique_ptr<GridElement> clone() const override {
		return std::make_unique<EmptyCell>(*this);
	}
};