#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::string password;
	int lowest{ 0 }, highest{ 0 }, countPasswords{ 0 };
	char letter{}, aux{};

	while (in >> lowest >> letter >> highest >> letter >> aux >> password)
	{
		if (((password[lowest - 1] == letter) || (password[highest - 1] == letter))
			&& (password[lowest - 1] != password[highest - 1]))
		{
			countPasswords++;
		}
	}

	out << countPasswords;

	in.close();
	out.close();
}