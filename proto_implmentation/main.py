import numpy as np


def generateGrid(rows, columns):
    return np.random.randint(1, size=(rows, columns))


def setGridValues(grid):
    grid[2][2] = 1
    grid[2][1] = 1
    grid[2][3] = 1


def countNeighbors(grid, row, col):
    neighbors = [
        (-1, -1), (-1, 0), (-1, 1),
        (0, -1), (0, 1),
        (1, -1), (1, 0), (1, 1)
    ]
    count = 0
    for deltaRow, deltaColumn in neighbors:
        r = row + deltaRow
        c = col + deltaColumn
        if 0 <= r < grid.shape[0] and 0 <= c < grid.shape[1]:
            count += grid[r, c]
    return count


def update_grid(grid):
    new_grid = np.copy(grid)
    for row in range(grid.shape[0]):  # based on the size of the rows
        for col in range(grid.shape[1]):  # based on the size of the columns
            alive_neighbors = countNeighbors(grid, row, col)
            if grid[row, col] == 1:  # Cell is alive
                if alive_neighbors < 2 or alive_neighbors > 3:
                    new_grid[row, col] = 0  # Dies
            else:  # Cell is dead
                if alive_neighbors == 3:
                    new_grid[row, col] = 1  # Becomes alive
    return new_grid


def runGameOfLife(rows, columns, generations):
    grid = generateGrid(rows, columns)
    setGridValues(grid)
    for gen in range(generations):
        print(f"Generation #{gen + 1}:")
        print(grid)
        grid = update_grid(grid)


runGameOfLife(5, 6, 2)