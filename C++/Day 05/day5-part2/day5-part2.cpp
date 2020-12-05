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
				f -= std::ceil((f - b) / 2);
				break;

			case 'B':
				b += std::ceil((f - b) / 2);
				break;

			case 'L':
				l -= std::ceil((l - r) / 2);
				break;

			case 'R':
				r += std::ceil((l - r) / 2);
				break;
			}
		}

		row = std::min(b, f);
		column = std::min(l, r);
		id = row * 8 + column;
		seatID.insert(id);
	}

	for (auto id = seatID.begin(); id != seatID.end(); id++)
	{
		auto nextId = std::next(id);
		if ((nextId != seatID.end()) && (abs(*id - *nextId) == 2))
		{
			out << std::min(*id, *nextId) + 1;
			break;
		}
	}

	in.close();
	out.close();
}