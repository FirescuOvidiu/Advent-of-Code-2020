#include "../../AOCHeaders/stdafx.h"


bool checkProperty(const std::vector<long long>& v, const int i, const int numbersBefore)
{
	for (int j = i - numbersBefore; j < i - 1; j++)
	{
		for (int k = j + 1; k < i; k++)
		{
			if (v[j] + v[k] == v[i])
			{
				return false;
			}
		}
	}

	return true;
}


long long findInvalidNumber(const std::vector<long long>& v)
{
	long long numbersBefore{ 25 };
	bool check{ true };

	for (int i = numbersBefore; i < v.size(); i++)
	{
		if (checkProperty(v, i, numbersBefore))
		{
			return v[i];
		}
	}
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<long long> v(std::istream_iterator<long long>{in}, {});
	long long invalidNumber = findInvalidNumber(v), sum{ 0 };

	for (int times = 2; times < v.size(); times++)
	{
		for (int i = 0; i < v.size() - times; i++)
		{
			sum = 0;
			for (int j = i; j < i + times && sum <= invalidNumber; j++)
			{
				sum += v[j];
			}

			if (sum == invalidNumber)
			{
				long long min{ v[i] }, max{ v[i] };

				for (int j = i; j < i + times; j++)
				{
					min = std::min(min, v[j]);
					max = std::max(max, v[j]);
				}
				out << min + max;
				times = v.size();
				break;
			}
		}
	}

	in.close();
	out.close();
}