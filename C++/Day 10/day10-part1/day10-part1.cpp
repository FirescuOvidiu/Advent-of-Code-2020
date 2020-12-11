#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<int> ratings(std::istream_iterator<int>{in}, {});
	int countOneJolt{ 0 }, countThreeJolt{ 1 };

	ratings.push_back(0);
	std::sort(std::begin(ratings), std::end(ratings));

	for (auto it = std::begin(ratings); std::next(it) != std::end(ratings); it++)
	{
		if (*std::next(it) - *it == 1)
		{
			countOneJolt++;
			continue;
		}
		if (*std::next(it) - *it == 3)
		{
			countThreeJolt++;
		}
	}

	out << countOneJolt * countThreeJolt;

	in.close();
	out.close();
}