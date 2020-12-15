#include "../../AOCHeaders/stdafx.h"


std::vector<long long> decToBinary(long long n)
{
	std::vector<long long> binaryNum(36, 0);

	int i = 0;
	while (n > 0) 
	{
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	return binaryNum;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::unordered_map<long long, long long> mem;
	std::vector<std::pair<long, long>> mask;
	std::vector<long long> floatingBits;
	std::bitset<36> result, auxResult;
	std::string line, aux;
	long long curMememoryAddress{ 0 }, value{ 0 };
	int countFloatingBits{ 0 }, it{ 0 };
	bool haveInput{ true };
	char c{};

	int cc = 0;

	std::getline(in, line);
	while (haveInput)
	{
		cc++;
		std::stringstream ss(line);

		ss >> aux >> aux;
		haveInput = false;

		for (int pos = 35; pos >= 0; pos--)
		{
			ss >> c;
			if (c == '0')
			{
				continue;
			}
			if (c == 'X')
			{
				mask.push_back({ pos, 0 });
			}
			else
			{
				mask.push_back({ pos, 1 });
			}
		}

		while (std::getline(in, line) && line[1] == 'e')
		{
			haveInput = true;
			ss.clear();
			ss.str(line);

			ss >> c >> c >> c >> c >> curMememoryAddress >> c >> c >> value;
			result = curMememoryAddress;
			countFloatingBits = 0;

			for (const auto& m : mask)
			{
				result[m.first] = m.second;
				if (m.second == 0)
				{
					countFloatingBits++;
				}
			}
			for (int i = 0; i < pow(2, countFloatingBits); i++)
			{
				auxResult = result;
				floatingBits = decToBinary(i);
				it = 0;
				for (const auto& m : mask)
				{
					if (m.second == 0)
					{
						auxResult[m.first] = floatingBits[it++];
					}
				}
				mem[auxResult.to_ullong()] = value;
			}
		}
		mask.clear();
	}

	out << std::accumulate(std::begin(mem), std::end(mem), (long long)0, [](long long total, const auto& m) {
		return total + m.second;
		});

	in.close();
	out.close();
}