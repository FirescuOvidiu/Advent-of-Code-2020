#include "../../AOCHeaders/stdafx.h"


bool checkProperty(const std::vector<long long>& v,  const int i, const int numbersBefore)
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


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<long long> v(std::istream_iterator<long long>{in}, {});
	long long numbersBefore{ 25 };
	bool check{ true };

	for (int i = numbersBefore; i < v.size(); i++)
	{
		if (checkProperty(v,i, numbersBefore))
		{
			out << v[i];
			break;
		}
	}

	in.close();
	out.close();
}