#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::array<bool, 26> yesAnswers;
	std::string line;
	int sum{ 0 };

	while (std::getline(in, line))
	{
		yesAnswers.fill(false);

		while (line != "")
		{
			for (const auto& c : line)
			{
				yesAnswers[c - 'a'] = true;
			}
			if (!std::getline(in, line))
			{
				break;
			}
		}
		
		sum += std::count(std::begin(yesAnswers), std::end(yesAnswers), true);
	}

	out << sum;

	in.close();
	out.close();
}