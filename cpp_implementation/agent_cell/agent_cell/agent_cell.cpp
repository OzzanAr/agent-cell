#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateGrid(int row, int collumn) {
    vector<vector<int>> genedGrid;

    return genedGrid;
}

void printGrid(vector<vector<int>> grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
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

    
    
}
