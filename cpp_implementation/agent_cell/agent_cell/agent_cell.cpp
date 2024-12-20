#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateGrid(int row, int collumn) {
    vector<vector<int>> genedGrid(row, vector<int>(collumn, 0));


    return genedGrid;
}

void printGrid(vector<vector<int>> &grid) {
    for (auto i : grid) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Running Game of Life...\n";

    int row = 5;
    int col = 5;

    vector<vector<int>> grid = generateGrid(row, col);

    printGrid(grid);
}
