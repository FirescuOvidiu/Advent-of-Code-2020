#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::unordered_map<long long, long long> mem;
	std::vector<std::pair<int, bool>> mask;
	std::bitset<36> result;
	std::string line, aux;
	long long curMememoryAddress{ 0 }, value{ 0 };
	bool haveInput{ true };
	char c{};

	std::getline(in, line);
	while (haveInput)
	{
		std::stringstream ss{ line };

		ss >> aux >> aux;
		haveInput = false;

		for (int pos = 35; pos >= 0; pos--)
		{
			ss >> c;
			if (c == 'X')
			{
				continue;
			}
			mask.push_back({ pos, c - '0' });
		}

		while (std::getline(in, line) && line[1] == 'e')
		{
			haveInput = true;
			ss.clear();
			ss.str(line);

			ss >> c >> c >> c >> c >> curMememoryAddress >> c >> c >> value;
			result = value;
			for (const auto& m : mask)
			{
				result[m.first] = m.second;
			}
			mem[curMememoryAddress] = result.to_ullong();
		}

		mask.clear();
	}

	out << std::accumulate(std::begin(mem), std::end(mem), (long long)0, [](long long total, const auto& m) {
		return total + m.second;
		});

	in.close();
	out.close();
}