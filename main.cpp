#include "class_file_ini.h"

int		main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./a.exe file" << std::endl;
		return (0);
	}

	class_file_ini test_ini(argv[1]);
	
	test_ini.print_data();

	std::cout << test_ini.get_int_value("width") << std::endl;
	std::cout << test_ini.get_int_value("height") << std::endl;
	std::cout << test_ini.get_int_value("screenmode") << std::endl;
/*
	std::cout << std::endl;

	std::cout << test_ini.get_int_value("width") << std::endl;
	std::cout << test_ini.get_int_value("height") << std::endl;
	std::cout << test_ini.get_int_value("fullscreen") << std::endl;

	std::string s = "0";
	if (s[0])
		std::cout << s << std::endl;
	*/
	return (0);
}