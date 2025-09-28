#pragma once
#include <vector>
#include "gridElement.hpp"

struct Cell
{
	std::vector<GridElement*> agents;
};