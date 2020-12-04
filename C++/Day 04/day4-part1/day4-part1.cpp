#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::string line, field;
	int validFields{ 0 }, validPassports{ 0 };

	while (std::getline(in, line))
	{
		validFields = 0;
		while (line != "")
		{
			std::stringstream ss{ line };

			while (ss >> field)
			{
				if (field.substr(0, 3) != "cid")
				{
					validFields++;
				}
			}
			if (!std::getline(in, line))
			{
				break;
			}
		}

		if (validFields == 7)
		{
			validPassports++;
		}
	}

	out << validPassports;

	in.close();
	out.close();
}