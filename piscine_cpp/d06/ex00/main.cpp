#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>

void castChar(double value, bool impossible)
{
	std::cout << "char: ";
	char c = static_cast<char>(value);
	if (value != value || value > 250 || value < 0 || impossible)
		std::cout << "impossible" << std::endl;
	else if (value < 32 || value > 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void castInt(double value, bool impossible)
{
	std::cout << "int: ";
	if (value != value || std::isinf(value) || impossible
        || value > INT_MAX || value < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

}

int	getPrecision(char *str)
{
	int	dot = 0;
	int	length = 0;

	while (str[dot] && str[dot] != '.')
		dot++;
	length = dot + 1;
	while (str[length] && isdigit(str[length]))
		length++;
	return ((length - dot) > 1 ? (length - dot) - 1 : 1);
}

int main(int argc, char **argv)
{
	double	value;
	int		precision;
	bool	impossible = false;

	if(argc < 2)
		return 0;

    value = atof(argv[1]);
	if (value == value && !(std::isinf(value)) &&
            (!isdigit(argv[1][0]) && argv[1][0] != '-' && argv[1][0] != '+'))
	{
		if (argv[1][1])
			impossible = true;
		value = (argv[1][0]);
	}

	precision = getPrecision(argv[1]);

	castChar(value, impossible);
	castInt(value, impossible);

	if (impossible)
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << std::fixed;
		std::cout << std::setprecision(precision);
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
}