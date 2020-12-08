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


std::optional<int> findACC(const std::vector<std::pair<std::string, int>>& instructions)
{
	std::vector<bool> visited(instructions.size(), false);
	int acc{ 0 }, pos{ 0 };

	while ((pos < instructions.size()) && (!visited[pos]))
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

	if (pos >= instructions.size())
	{
		return acc;
	}
	else
	{
		return {};
	}
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<std::pair<std::string, int>> instructions = readInput(in);

	for (auto& instruction : instructions)
	{
		if (instruction.first == "jmp")
		{
			instruction.first = "nop";
			if (auto acc = findACC(instructions))
			{
				out << acc.value();
				break;
			}
			instruction.first = "jmp";
			continue;
		}

		if (instruction.first == "nop")
		{
			instruction.first = "jmp";
			if (auto acc = findACC(instructions))
			{
				out << acc.value();
				break;
			}
			instruction.first = "nop";
		}
	}

	in.close();
	out.close();
}