#include "utils.hpp"

namespace utils {
	std::string EnumToString(CellType type)
	{
		return MappedCellType[type];
	}

	std::vector<std::pair<int, int>> GetFacingDirection(Direction direction)
	{
		return MappedDirections[direction];
	}
}
