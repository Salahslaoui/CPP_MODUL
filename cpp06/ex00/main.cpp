#include  "ScalarConverter.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "enter 2 arguments!" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
}
