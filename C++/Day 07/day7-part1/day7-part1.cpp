#include "../../AOCHeaders/stdafx.h"


std::string getBag(std::stringstream& ss)
{
	std::string firstColor, secondColor;

	ss >> firstColor;
	ss >> secondColor;

	return firstColor + " " + secondColor;
}


std::unordered_map<std::string, std::vector<std::string>> readInput(std::fstream& in)
{
	std::unordered_map<std::string, std::vector<std::string>> bags;
	std::string line, bag, aux;

	while (std::getline(in, line))
	{
		std::stringstream ss{ line };
		std::vector<std::string> v;
		bag = getBag(ss);
		ss >> aux >> aux;

		while (ss >> aux && aux != "no")
		{
			v.push_back(getBag(ss));
			ss >> aux;
		}
		bags[bag] = v;
	}

	return bags;
}



bool checkContain(std::unordered_map<std::string, std::vector<std::string>>& bags, const std::string& startBag)
{
	std::queue<std::string> currBags;

	for (const auto& bag : bags[startBag])
	{
		currBags.push(bag);
	}

	while (!currBags.empty())
	{
		std::string currBag = currBags.front();
		currBags.pop();

		if (currBag == "shiny gold")
		{
			return true;
		}
		else
		{
			for(const auto & bag : bags[currBag])
			{
				currBags.push(bag);
			}
		}
	}

	return false;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::unordered_map<std::string, std::vector<std::string>> bags = readInput(in);

	out << std::count_if(std::begin(bags), std::end(bags), [&bags](const auto& bag) {
		return checkContain(bags, bag.first);
		});

	in.close();
	out.close();
}