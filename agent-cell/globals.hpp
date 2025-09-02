#pragma once
#include <raylib.h>
#include <string>
#include <map>
#include <vector>

constexpr int WINDOW_WIDTH = 1200;
constexpr int WINDOW_HEIGHT = 960;

// Currently unused - Delete in the future
constexpr int GRID_WIDTH = 1000;
constexpr int GRID_HEIGHT = 500;

constexpr int GRID_ROW_COUNT = 10; // x
constexpr int GRID_COLUMN_COUNT = 20; // y

constexpr int TARGET_FPS = 10;

constexpr Color CUSTOM_GREY = { 55, 55, 55, 255 };
constexpr Color CUSTOM_GREEN = { 0, 255, 0, 255 };

enum CellType {
	EMPTYCELL,
	BUNNY,
	FOX,
	GRASS
};

static std::map<CellType, std::string> MappedCellType = {
	{EMPTYCELL, "Empty"},
	{BUNNY, "Bunny"},
	{FOX, "Fox"},
	{GRASS, "Grass"},
};

enum Direction {
	NORTH, // x-axis static; y-axis minus 
	SOUTH, // x-axis static; y-axis add 
	EAST, // x-axis add; y-axis static
	WEST // x-axis minus; y-axis static
};

static std::vector<std::pair<int, int>> neighborOffsets = {
        {-1, 0},  // Above
        {1, 0},   // Below
        {0, -1},  // Left
        {0, 1},   // Right
        {-1, -1}, // Upper left
        {-1, 1},  // Upper right
        {1, -1},  // Lower Left
        {1, 1},   // Lower right
    };

static std::vector<std::pair<int, int>> northOffsets = {
        {-1, 0},  // Above
        {-1, -1}, // Upper left
        {-1, 1},  // Upper right
        {-2, 0},  // Two above 
        {-2, -1}, // Two Upper left
        {-2, 1},  // Two Upper right
    };

static std::vector<std::pair<int, int>> southOffsets = {
        {1, 0},   // Below
        {1, -1},  // Lower Left
        {1, 1},   // Lower right
        {2, 0},   // Two Below
        {2, -1},  // Two Lower Left
        {2, 1},   // Two Lower right
    };
