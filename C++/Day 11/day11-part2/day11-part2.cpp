#include "../../AOCHeaders/stdafx.h"


std::vector<std::string> readInput(std::fstream& in)
{
	std::vector<std::string> grid;
	std::string line;

	while (std::getline(in, line))
	{
		grid.push_back(line);
	}

	return grid;
}


int countOccupiedSeats(const std::vector<std::string>& grid, const int startX, const int startY, const std::vector<int>& dx, const std::vector<int>& dy)
{
	int newX{ 0 }, newY{ 0 }, occupiedSeats{ 0 };

	for (int it = 0; it < 8; it++)
	{
		newX = startX + dx[it];
		newY = startY + dy[it];
		while ((newX >= 0) && (newY >= 0) && (newX < grid.size()) && (newY < grid[0].size()) && grid[newX][newY] != 'L')
		{
			if (grid[newX][newY] == '#')
			{
				occupiedSeats++;
				break;
			}
			newX += dx[it];
			newY += dy[it];
		}
	}

	return occupiedSeats;
}

int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<int> dx{ 0,1,1,1,0,-1,-1,-1 }, dy{ -1,-1,0,1,1,1,0,-1 };
	std::vector<std::string> grid = readInput(in), newGrid(grid);
	int occupiedSeats{ 0 };

	do
	{
		grid = newGrid;
		for (int x = 0; x < grid.size(); x++)
		{
			for (int y = 0; y < grid[0].size(); y++)
			{
				occupiedSeats = countOccupiedSeats(grid, x, y, dx, dy);
				if ((grid[x][y] == 'L') && (occupiedSeats == 0))
				{
					newGrid[x][y] = '#';
				}
				if ((grid[x][y] == '#') && (occupiedSeats >= 5))
				{
					newGrid[x][y] = 'L';
				}
			}
		}
	} while (grid != newGrid);

	out << std::accumulate(std::begin(grid), std::end(grid), 0, [](int total, const auto& row) {
		return total + std::count(std::begin(row), std::end(row), '#');
		});

	in.close();
	out.close();
}