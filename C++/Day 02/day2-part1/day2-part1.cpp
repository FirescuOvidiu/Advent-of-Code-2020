#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	std::string password;
	int lowest{ 0 }, highest{ 0 }, countPasswords{ 0 }, countLetters{ 0 };
	char letter{}, aux{};

	while (in >> lowest >> aux >> highest >> letter >> aux >> password)
	{
		countLetters = std::count(std::begin(password), std::end(password), letter);

		if ((countLetters >= lowest) && (countLetters <= highest))
		{
			countPasswords++;
		}
	}

	out << countPasswords;

	in.close();
	out.close();
}