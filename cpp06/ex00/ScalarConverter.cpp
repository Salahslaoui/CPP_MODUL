#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &op)
{
	(void)op;
	return (*this);
}

std::string	parse(std::string input)
{
	int i = 0;
	int flag = 0;
	int sign = 0;
	unsigned long	j = 0;

	if (input.length() == 1)
	{
		if (isprint(input[0]) && (!isdigit(input[0])))
			return ("CHAR");
	}
	if (input.length() >= 1)
	{
		while(input[i])
		{
			if (input[i] == '+' || input[i] == '-')
			{
				sign++;
				i++;
				continue;
			}
			if (!isdigit(input[i]) && !input[i + 1] && input[i] == 'f' && flag == 1)
			{
				if (j == input.length() - 2 || (sign == 1 && j == input.length() - 3))
					return ("FLOAT");
			}
			if (isdigit(input[i]))
			{
				j++;
				i++;
				continue;
			}
			if (input[i] == '.')
				flag++;
			if (flag > 1 || sign > 1)
				return ("OTHER");
			i++;
		}
		if (j == input.length() || (sign == 1 && j == input.length() - 1))
			return ("INT");
		if ((flag == 1 && j == input.length() - 1) || (sign == 1 && j == input.length() - 2))
			return ("DOUBLE");
	}
	return ("OTHER");
}

void ScalarConverter::convert(std::string input)
{
	std::string str = parse(input);
	char c;
	char *end = NULL;
	long l;

	if (str == "CHAR")
	{
		if(isprint(input[0]))
			std:: cout << "char: " << input << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std:: cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std:: cout << "float: " << std::fixed << static_cast<float>(input[0]) << "f" << std::endl;
		std:: cout << "double: " << static_cast<double>(input[0]) << std::endl;
	}
	if (str == "INT")
	{
		l = strtol(input.c_str(), &end, 10);
		if(isprint(static_cast<char>(l)))
		{
			c = static_cast<char>(l);
			std:: cout << "char: '" << c << "'" << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;
		if (l > 2147483647 || l < -2147483648)
			std::cout << "int: impossible" << std::endl;
		else
			std:: cout << "int: " << l << std::endl;
		std:: cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(l) << "f" << std::endl;
		std:: cout << "double: " << static_cast<double>(l) << std::endl;
	}
	if (str == "FLOAT")
	{
		float f = strtof(input.c_str(), &end);
		if(isprint(static_cast<char>(f)))
		{
			c = static_cast<char>(f);
			std:: cout << "char: '" << c << "'" << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;
		if (strtol(input.c_str(), &end, 10) > 2147483647 || strtol(input.c_str(), &end, 10) < -2147483648)
    		std::cout << "int: impossible" << std::endl;
		else
    		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std:: cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std:: cout << "double: " << static_cast<double>(f) << std::endl;
	}
	if (str == "DOUBLE")
	{
		double d = strtod(input.c_str(), &end);
		if(isprint(static_cast<char>(d)))
		{
			c = static_cast<char>(d);
			std:: cout << "char: '" << c << "'" << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;
		if (d > 2147483647 || d < -2147483648)
			std::cout << "int: impossible" << std::endl;
		else
			std:: cout << "int: " << static_cast<int>(d) << std::endl;
		std:: cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std:: cout << "double: " << d << std::endl;
	}
	if (str == "OTHER")
	{
		if (input == "nan")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << strtof(input.c_str(), &end) << "f" << std::endl;
			std::cout << "double: " << std::fixed << strtod(input.c_str(), &end) << std::endl;
		}
		if (input == "+inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << strtof(input.c_str(), &end) << "f" << std::endl;
			std::cout << "double: " << std::fixed << strtod(input.c_str(), &end) << std::endl;
		}
		if (input == "-inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << strtof(input.c_str(), &end) << "f" << std::endl;
			std::cout << "double: " << std::fixed << strtod(input.c_str(), &end) << std::endl;
		}
		else
			std::cout << "unknown type!!" << std::endl;
	}
}

ScalarConverter::~ScalarConverter()
{}
