#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> generateGrid(int row, int column) {
    vector<vector<int>> genedGrid(row, vector<int>(column, 0));

    genedGrid.at(2).at(2) = 1;
    genedGrid.at(2).at(1) = 1;
    genedGrid.at(2).at(3) = 1;

    return genedGrid;
}

void printGrid(vector<vector<int>> &grid) {
    for (auto i : grid) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
	cout << endl;
}

int countNeighbours(const vector<vector<int>>& grid, int row, int col) {
    int count = 0;
    int currentRow = 1, currentCol = 1;
    vector<pair<int, int>> neighbors = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1},
    };

    for (const auto& neighbor : neighbors) {
        int deltaRow = neighbor.first;
        int deltaCol = neighbor.second;
        int r = row + deltaRow;
        int c = col + deltaCol;

        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
            count += grid[r][c];
        }
    }

    return count;
}


vector<vector<int>> updateGrid(vector<vector<int>> grid) {
    int aliveNeighbors = 0;
    vector<vector<int>> newGrid = grid;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            aliveNeighbors = countNeighbours(grid, i, j);

            if (grid.at(i).at(j) == 1) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newGrid.at(i).at(j) = 0;
                }
            }
            else {
                if (aliveNeighbors == 3) {
                    newGrid.at(i).at(j) = 1;
                }
            }
        }
    }

    return newGrid;
}

int main()
{
    cout << "Running Game of Life...\n\n";

    int row = 5;
    int col = 5;
    int gens = 5;

    vector<vector<int>> grid = generateGrid(row, col);

    for (int i = 0; i < gens; i++) {
        printf("Generation #%d\n", i + 1);
        printGrid(grid);
        grid = updateGrid(grid);
    }

    return 0;
}
