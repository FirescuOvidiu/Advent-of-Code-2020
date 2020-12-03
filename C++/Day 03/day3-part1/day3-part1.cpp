#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<std::string> map(std::istream_iterator<std::string>{in}, {});
	int x{ 0 }, y{ 0 }, rows{ (int)map.size() }, columns{ (int)map[0].size() }, countTrees{ 0 };

	while (x < rows)
	{
		if (map[x][y] == '#')
		{
			countTrees++;
		}
		x++;
		y = (y + 3) % columns;
	}

	out << countTrees;

	in.close();
	out.close();
}