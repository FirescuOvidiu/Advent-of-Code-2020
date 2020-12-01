#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<int> v(std::istream_iterator<int>{in}, {});

	for (int i = 0; i < v.size() - 2; i++)
	{
		for (int j = i + 1; j < v.size() - 1; j++)
		{
			for (int k = j + 1; k < v.size(); k++)
			{
				if (v[i] + v[j] + v[k] == 2020)
				{
					out << v[i] * v[j] * v[k];
					i = v.size(), j = v.size(), k = v.size();
				}
			}
		}
	}

	in.close();
	out.close();
}