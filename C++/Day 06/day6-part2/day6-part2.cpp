#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::array<int, 26> yesAnswers;
	std::string line;
	int sum{ 0 }, lines{ 0 };

	while (std::getline(in, line))
	{
		yesAnswers.fill(0);
		lines = 0;

		while (line != "")
		{
			for (const auto& c : line)
			{
				yesAnswers[c - 'a']++;
			}
			lines++;
			if (!std::getline(in, line))
			{
				break;
			}
		}

		sum += std::count(std::begin(yesAnswers), std::end(yesAnswers), lines);
	}

	out << sum;

	in.close();
	out.close();
}