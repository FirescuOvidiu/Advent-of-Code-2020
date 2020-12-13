#include "../../AOCHeaders/stdafx.h"


std::vector<std::pair<int,int>> readInput(std::fstream& in)
{
	std::vector<std::pair<int, int>> busses;
	int bus{ 0 }, t{ 0 }, aux{ 0 };
	char c{};

	in >> aux;
	while (in >> c)
	{
		while (isdigit(c))
		{
			bus = bus * 10 + (c - '0');
			if (!(in >> c))
			{
				break;
			}
		}

		if (bus > 0)
		{
			busses.push_back({ t, bus });
			bus = 0;
		}
		else
		{
			in >> c;
		}
		t++;
	}

	return busses;
}


long long mul_inv(long long a, long long b)
{
	long long b0{ b }, t{ 0 }, q{ 0 };
	long long x0{ 0 }, x1{ 1 };

	if (b == 1)
	{
		return 1;
	}
	while (a > 1) 
	{
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0)
	{
		x1 += b0;
	}

	return x1;
}


long long chinese_remainder(const std::vector<long long>& n, const std::vector<long long>& a, const long long lenght)
{
	long long p{ 0 }, i{ 0 }, prod{ 1 }, sum{ 0 };

	for (i = 0; i < lenght; i++)
	{
		prod *= n[i];
	}

	for (i = 0; i < lenght; i++) 
	{
		p = prod / n[i];
		sum += a[i] * mul_inv(p, n[i]) * p;
	}

	return sum % prod;
}


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::vector<std::pair<int,int>> busses = readInput(in);
	std::vector<long long> n, a;

	for (const auto& bus : busses)
	{
		n.push_back(bus.second);
		a.push_back((-bus.first + bus.second) % bus.second);
	}

	out << chinese_remainder(n, a, busses.size());

	in.close();
	out.close();
}