#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "globals.hpp"

namespace utils {
	std::string EnumToString(CellType type);
	std::vector<std::pair<int, int>> GetFacingDirection(Direction);
}

#endif // !UTILS_H
