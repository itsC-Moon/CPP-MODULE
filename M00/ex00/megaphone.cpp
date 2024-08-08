#include <iostream>

int main(int ac, char *argv[])
{
	char *str;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (*++argv)
		{
			str = *argv;
			for (int i = 0; str[i]; i++)
				str[i] = std::toupper(str[i]);
			std::cout << *argv;

		}
		std::cout << std::endl;
	}
	return 0;
}
