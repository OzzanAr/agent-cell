#include "utils.hpp"

namespace utils {
	std::string EnumToString(CellType type)
	{
		return MappedCellType[type];
	}
}
