#include "../../AOCHeaders/stdafx.h"


bool checkYearFields(std::string& field, const int low, const int high)
{
	int number = std::stoi(field.substr(4));

	return ((number >= low) && (number <= high));
}


bool checkHeightField(std::string& field)
{
	std::stringstream ss(field.substr(4));
	std::string unit;
	int number{ 0 };

	ss >> number >> unit;

	if (unit == "cm")
	{
		return (number >= 150) && (number <= 193);
	}
	if (unit == "in")
	{
		return ((number >= 59) && (number <= 76));
	}

	return false;
}


bool checkHairField(std::string& field)
{
	if (field[4] != '#')
	{
		return false;
	}
	if (field.substr(5).size() != 6)
	{
		return false;
	}
	for (int it = 5; it < field.size(); it++)
	{
		if ((!isdigit(field[it]) && (!islower(field[it]))))
		{
			return false;
		}
	}

	return true;
}


bool checkEyeField(std::string& field)
{
	return ((field.substr(4) == "amb") ||
		(field.substr(4) == "blu") ||
		(field.substr(4) == "brn") ||
		(field.substr(4) == "gry") ||
		(field.substr(4) == "grn") ||
		(field.substr(4) == "hzl") ||
		(field.substr(4) == "oth"));
}


bool checkIdField(std::string& field)
{
	if (field.substr(4).size() != 9)
	{
		return false;
	}
	for (int it = 4; it < field.size(); it++)
	{
		if (!isdigit(field[it]))
		{
			return false;
		}
	}

	return true;
}


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
				if(field.substr(0, 3) == "cid")
				{
					continue;
				}

				if ((field.substr(0, 3) == "byr") && (checkYearFields(field, 1920, 2002)))
				{
					validFields++;
					continue;
				}

				if ((field.substr(0, 3) == "iyr") && (checkYearFields(field, 2010, 2020)))
				{
					validFields++;
					continue;
				}

				if ((field.substr(0, 3) == "eyr") && (checkYearFields(field, 2020, 2030)))
				{
					validFields++;
					continue;
				}
				if ((field.substr(0, 3) == "hgt") && (checkHeightField(field)))
				{
					validFields++;
					continue;
				}

				if ((field.substr(0, 3) == "hcl") && (checkHairField(field)))
				{
					validFields++;
					continue;
				}

				if ((field.substr(0, 3) == "ecl") && (checkEyeField(field)))
				{
					validFields++;
					continue;
				}

				if ((field.substr(0, 3) == "pid") && (checkIdField(field)))
				{
					validFields++;
					continue;
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