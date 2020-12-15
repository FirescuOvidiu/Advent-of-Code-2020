#include "../../AOCHeaders/stdafx.h"


std::vector<int> readInput(std::fstream& in)
{
	std::vector<int> startingNumbers;
	std::string line;
	int number{ 0 };
	char c{};

	std::getline(in, line);
	std::stringstream ss(line);

	while (ss >> number)
	{
		startingNumbers.push_back(number);
		ss >> c;
	}

	return startingNumbers;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::unordered_map<int, std::vector<int>> visited;
	std::vector<int> startingNumbers = readInput(in);
	int lastNumber = startingNumbers.back(), auxLastNumber;


	for (int it = 0; it < startingNumbers.size(); it++)
	{
		visited[startingNumbers[it]].push_back(it + 1);
	}

	for (int turn = startingNumbers.size() + 1; turn <= 30000000; turn++)
	{
		if ((visited[lastNumber].size() == 1) || (visited[lastNumber].size() == 0))
		{
			visited[0].push_back(turn);
			lastNumber = 0;
		}
		else
		{
			if (visited[lastNumber].size() >= 2)
			{
				auxLastNumber = visited[lastNumber][visited[lastNumber].size() - 1] - visited[lastNumber][visited[lastNumber].size() - 2];
				visited[visited[lastNumber][visited[lastNumber].size() - 1] - visited[lastNumber][visited[lastNumber].size() - 2]].push_back(turn);
				lastNumber = auxLastNumber;
			}
		}
	}

	out << lastNumber;

	in.close();
	out.close();
}