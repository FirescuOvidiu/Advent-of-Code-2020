#include "../../AOCHeaders/stdafx.h"


std::vector<std::pair<std::string, int>> readInput(std::fstream& in)
{
	std::vector<std::pair<std::string, int>> instructions;
	std::string operation;
	int argument{ 0 };

	while (in >> operation >> argument)
	{
		instructions.push_back({ operation, argument });
	}

	return instructions;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<std::pair<std::string, int>> instructions = readInput(in);
	std::vector<bool> visited(instructions.size(), false);
	int acc{ 0 }, pos{ 0 };

	while(!visited[pos])
	{
		visited[pos] = true;
		if (instructions[pos].first == "jmp")
		{
			pos += instructions[pos].second;
			continue;
		}

		if (instructions[pos].first == "acc")
		{
			acc += instructions[pos].second;
		}
		pos++;
	}

	out << acc;

	in.close();
	out.close();
}