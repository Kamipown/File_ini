#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <string>
#include <stdlib.h>

class class_file_ini
{
	private:
		std::map <std::string, std::string> file_data;
		bool modified;

		void		read_file(std::string filename);

	public:
		class_file_ini(std::string filename);
		~class_file_ini(void);
		
		void		print_data(void);

		int			get_int_value(const std::string &name);
		std::string	get_string_value(const std::string &name);

		void		set_value(const std::string name, int value);
		void		set_value(const std::string name, const std::string &value);

};