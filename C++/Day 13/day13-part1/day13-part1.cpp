#include "../../AOCHeaders/stdafx.h"


std::vector<int> readInput(std::fstream& in)
{
	std::vector<int> busses;
	int bus{ 0 };
	char c{};

	while (in >> c)
	{
		while (isdigit(c))
		{
			bus = bus * 10 + (c - '0');
			if (!(in >> c))
			{
				break;
			}
		}

		if (bus > 0)
		{
			busses.push_back(bus);
			bus = 0;
		}
		else
		{
			in >> c;
		}
	}

	return busses;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<int> busses;
	int earliestTimestamp{ 0 };

	in >> earliestTimestamp;
	busses = readInput(in);

	for (int timestamp = earliestTimestamp;; timestamp++)
	{
		for (const auto& bus : busses)
		{
			if (timestamp % bus == 0)
			{
				out << (timestamp - earliestTimestamp) * bus;
				exit(0);
			}
		}
	}

	in.close();
	out.close();
}