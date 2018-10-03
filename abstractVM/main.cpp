#include <iostream>
#include <fstream>
#include "AbstractVM.hpp"
#include "CmdLine.hpp"

void    read_from_file(char *file, AbstractVM &vm)
{
    std::ifstream	in_file(file);
    std::string		str;
	auto			func_map = vm.getFunc();

    for (int line_count = 1; getline(in_file, str); line_count++)
    {
        CmdLine line(str);

		try
		{
			line.validate(func_map);
			line.call();
		}
		catch(std::exception &e)
		{
			std::cout << "error in line: " << line_count << " - ";
			std::cout << e.what() << " - ";
			std::cout << "\"" << line.getCmdStr() << "\"" << std::endl;
			exit(1);
		}
	}
}

int main(int argc, char **argv)
{
    AbstractVM vm;

    if (argc > 1)
        read_from_file(argv[1], vm);
//  else
//        read_from_stdin();
    return 0;
}