#include "../../AOCHeaders/stdafx.h"


struct Bag
{
	Bag(const std::vector<std::string>& colors = {}, const std::vector<int>& numbers = {}, const int total = 0) : colors(colors), numbers(numbers), total(total) {}
	
	std::vector<std::string> colors;
	std::vector<int> numbers;
	int total;
};


std::string getBag(std::stringstream& ss)
{
	std::string firstColor, secondColor;

	ss >> firstColor;
	ss >> secondColor;

	return firstColor + " " + secondColor;
}


std::unordered_map<std::string, Bag> readInput(std::fstream& in)
{
	std::unordered_map<std::string, Bag> bags;
	std::string line, aux, bag, number;

	while (std::getline(in, line))
	{
		std::stringstream ss{ line };
		std::vector<std::string> colors;
		std::vector<int> numbers;
		int total{ 0 };

		bag = getBag(ss);
		ss >> aux >> aux;

		while (ss >> number && number != "no")
		{
			numbers.push_back(std::stoi(number));
			total += std::stoi(number);
			colors.push_back(getBag(ss));
			ss >> aux;
		}
		bags[bag] = Bag(colors, numbers);
	}

	return bags;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::unordered_map<std::string, Bag> bags = readInput(in);
	std::unordered_set<std::string> uncountedBags;

	for(const auto& bag : bags)
	{
		if (bag.second.colors.size() != 0)
		{
			uncountedBags.insert(bag.first);
		}
	}

	while (!uncountedBags.empty())
	{
		for (const auto& currBag : uncountedBags)
		{
			if (std::any_of(std::begin(bags[currBag].colors), std::end(bags[currBag].colors), [&uncountedBags](const auto& bag) {
				return uncountedBags.find(bag) != std::end(uncountedBags);
				}))
			{
				continue;
			}

			for (int i = 0; i < bags[currBag].colors.size(); i++)
			{
				bags[currBag].total += bags[currBag].numbers[i] * bags[bags[currBag].colors[i]].total + bags[currBag].numbers[i];
			}
			
			uncountedBags.erase(currBag);
			break;
		}
	}

	out << bags["shiny gold"].total;

	in.close();
	out.close();
}