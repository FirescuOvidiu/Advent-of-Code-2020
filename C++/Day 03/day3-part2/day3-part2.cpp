#include "../../AOCHeaders/stdafx.h"


int countTrees(const std::vector<std::string>& map, const int right, const int down)
{
	int x{ 0 }, y{ 0 }, rows{ (int)map.size() }, columns{ (int)map[0].size() }, countTrees{ 0 };

	while (x < rows)
	{
		if (map[x][y] == '#')
		{
			countTrees++;
		}
		x = x + down;
		y = (y + right) % columns;
	}

	return countTrees;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<std::string> map(std::istream_iterator<std::string>{in}, {});
	long long multiply{ 1 };

	multiply *= countTrees(map, 1, 1);
	multiply *= countTrees(map, 3, 1);
	multiply *= countTrees(map, 5, 1);
	multiply *= countTrees(map, 7, 1);
	multiply *= countTrees(map, 1, 2);

	out << multiply;

	in.close();
	out.close();
}