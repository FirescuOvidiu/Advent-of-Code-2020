#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<int> v(std::istream_iterator<int>{in}, {});
	int size{ (int)v.size() };

	for (int i = 0; i < size - 2; i++)
	{
		for (int j = i + 1; j < size - 1; j++)
		{
			for (int k = j + 1; k < size; k++)
			{
				if (v[i] + v[j] + v[k] == 2020)
				{
					out << v[i] * v[j] * v[k];
					i = j = k = size;
				}
			}
		}
	}

	in.close();
	out.close();
}