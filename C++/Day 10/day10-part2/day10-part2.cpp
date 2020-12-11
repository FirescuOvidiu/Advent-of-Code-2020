#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<int> ratings(std::istream_iterator<int>{in}, {});
	std::vector<long long> result(*std::max_element(std::begin(ratings),std::end(ratings)) + 1);
	result[0] = 1;

	std::sort(std::begin(ratings), std::end(ratings));

	for (int it = 0; it < ratings.size(); it++)
	{
		if (ratings[it] - 1 >= 0)
		{
			result[ratings[it]] = result[ratings[it] - 1];
		}
		if (ratings[it] - 2 >= 0)
		{
			result[ratings[it]] += result[ratings[it] - 2];
		}
		if (ratings[it] - 3 >= 0)
		{
			result[ratings[it]] += result[ratings[it] - 3];
		}
	}

	out << result.back();

	in.close();
	out.close();
}