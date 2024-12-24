#include <iostream>
#include <vector>

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

void updateGrid() {


    
}

int main()
{
    cout << "Running Game of Life...\n\n";

    int row = 5;
    int col = 5;
    int gens = 5;

    vector<vector<int>> grid = generateGrid(row, col);

    for (int i = 0; i < gens; i++) {
        printf("Generation #%d", i + 1);
        printGrid(grid);
        updateGrid(grid);
    }

    return 0;
}
