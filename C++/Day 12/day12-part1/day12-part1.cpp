#include "../../AOCHeaders/stdafx.h"


class Coordinate
{
public:
	Coordinate(const int x = 0, const int y = 0) : x(x), y(y) {}

	static int manhattenDistance(const Coordinate& first, const Coordinate& second)
	{
		return std::abs(first.x - second.x) + std::abs(first.y - second.y);
	}

public:
	int x, y;
};


int rotateRight(int dir, const int degrees)
{
	for (int it = 0; it < degrees / 90; it++)
	{
		dir = (dir + 3) % 4;
	}

	return dir;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<int> dx{ 0,-1,0,1 }, dy{ 1,0,-1,0 };
	Coordinate start;
	int value{ 0 }, facing{ 0 };
	char action{};

	while (in >> action >> value)
	{
		switch (action)
		{
		case 'E':
			start.y += value;
			break;

		case 'N':
			start.x -= value;
			break;

		case 'W':
			start.y -= value;
			break;

		case 'S':
			start.x += value;
			break;

		case 'L':
			facing = rotateRight(facing, 360 - value);
			continue;

		case 'R':
			facing = rotateRight(facing, value);
			continue;

		case 'F':
			start.x += dx[facing] * value;
			start.y += dy[facing] * value;
			break;
		}
	}

	out << Coordinate::manhattenDistance((0, 0), start);

	in.close();
	out.close();
}