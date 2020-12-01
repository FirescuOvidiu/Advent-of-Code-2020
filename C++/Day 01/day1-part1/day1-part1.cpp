#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<int> v(std::istream_iterator<int>{in}, {});
	int size{ (int)v.size() };

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (v[i] + v[j] == 2020)
			{
				out << v[i] * v[j];
				i = j = size;
			}
		}
	}

	in.close();
	out.close();
}