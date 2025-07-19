#pragma once
#include <raylib.h>
#include <string>
#include <map>

constexpr int WINDOW_WIDTH = 1200;
constexpr int WINDOW_HEIGHT = 960;

// Currently unused - Delete in the future
constexpr int GRID_WIDTH = 1000;
constexpr int GRID_HEIGHT = 500;

constexpr int GRID_ROW_COUNT = 10; // x
constexpr int GRID_COLUMN_COUNT = 20; // y

constexpr int TARGET_FPS = 12;

constexpr Color CUSTOM_GREY = { 55, 55, 55, 255 };
constexpr Color CUSTOM_GREEN = { 0, 255, 0, 255 };

enum CellType {
	EMPTYCELL,
	BUNNY,
	FOX,
	FOOD
};

static std::map<CellType, std::string> MappedCellType = {
	{EMPTYCELL, "Empty"},
	{BUNNY, "Bunny"},
	{FOX, "Fox"},
	{FOOD, "Food"},
};
