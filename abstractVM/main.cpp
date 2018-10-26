#include <iostream>
#include <fstream>
#include "AbstractVM.hpp"
#include "CmdLine.hpp"

void    read_from_file(char *file, AbstractVM &vm)
{
    std::ifstream	in_file(file);
    std::string		str;
	auto			func_map = vm.getFunc();

    for (int line_count = 1; std::getline(in_file, str); line_count++)
    {
        CmdLine line(str);

		try
		{
			line.validate(func_map);
			line.call(vm);
		}
		catch(std::exception &e)
		{
			std::cout << "error in line: " << line_count << " - ";
			std::cout << "\"" << line.getCmdStr() << "\": ";
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "error: no exit command found" << std::endl;
}

void    read_from_stdin(AbstractVM &vm)
{
    std::string		str;
    auto			func_map = vm.getFunc();

    for (int line_count = 1; std::getline(std::cin, str); line_count++)
    {
        CmdLine line(str);

        try
        {
            line.validate(func_map);
			if (line.getCmdStr()[0] == ';' && line.getCmdStr()[1] == ';')
				break;
            line.call(vm);
        }
        catch(std::exception &e)
        {
            std::cout << "error in line: " << line_count << " - ";
            std::cout << "\"" << line.getCmdStr() << "\": ";
            std::cout << e.what() << std::endl;
            break;
        }
    }
}

int main(int argc, char **argv)
{
    AbstractVM vm;

    if (argc > 1)
        read_from_file(argv[1], vm);
	else
        read_from_stdin(vm);
    return 0;
}