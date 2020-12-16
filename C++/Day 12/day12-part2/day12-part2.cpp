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


Coordinate rotateRight(Coordinate waypoint, const int degrees)
{
	for (int it = 0; it < degrees / 90; it++)
	{
		waypoint.x = -waypoint.x;
		std::swap(waypoint.x, waypoint.y);
	}

	return waypoint;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	Coordinate start, waypoint(-1, 10);
	int value{ 0 };
	char action{};

	while (in >> action >> value)
	{
		switch (action)
		{
		case 'E':
			waypoint.y += value;
			break;

		case 'N':
			waypoint.x -= value;
			break;

		case 'W':
			waypoint.y -= value;
			break;

		case 'S':
			waypoint.x += value;
			break;

		case 'L':
			waypoint = rotateRight(waypoint, 360 - value);
			continue;

		case 'R':
			waypoint = rotateRight(waypoint, value);
			continue;

		case 'F':
			start.x += value * std::abs(waypoint.x) * (waypoint.x > 0 ? -1 : 1);
			start.y += value * std::abs(waypoint.y) * (waypoint.y > 0 ? -1 : 1);
			continue;
		}
	}

	out << Coordinate::manhattenDistance((0, 0), start);

	in.close();
	out.close();
}