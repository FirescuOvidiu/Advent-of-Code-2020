#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::set<int> seatID;
	std::string line;
	double b{ 0 }, f{ 127 }, r{ 0 }, l{ 7 };
	int row{ 0 }, column{ 0 }, id{ 0 };

	while (std::getline(in, line))
	{
		b = 0, f = 127, r = 0, l = 7;
		for (const auto& c : line)
		{
			switch (c)
			{
			case 'F':
				f -= (f - b) / 2;
				break;

			case 'B':
				b += (f - b) / 2;
				break;

			case 'L':
				l -= (l - r) / 2;
				break;

			case 'R':
				r += (l - r) / 2;
				break;
			}
		}

		row = std::min(std::ceil(b), std::ceil(f));
		column = std::min(std::ceil(l), std::ceil(r));
		id = row * 8 + column;
		seatID.insert(id);
	}

	auto result = std::adjacent_find(seatID.begin(), seatID.end(), [](const auto& first, const auto& second)
		{
			return abs(first - second) == 2;
		});

	out << std::min(*result, *std::next(result)) + 1;

	in.close();
	out.close();
}