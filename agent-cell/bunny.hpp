#pragma once
#include "gridElement.hpp"

class Bunny : public GridElement {
public:
	Bunny() {
		value = 1;
		color = PINK;
		bool isSeen = false;
	}

	std::unique_ptr<GridElement> clone() const override {
		return std::make_unique<Bunny>(*this);
	}

private:
	bool isSeen;
};