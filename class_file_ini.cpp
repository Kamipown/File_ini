#include "class_file_ini.h"

using namespace std;

class_file_ini::class_file_ini(string filename)
{
		this->read_file(filename);
		this->print_file();
		modified = false;
}

class_file_ini::~class_file_ini(void)
{
	
}

void		class_file_ini::read_file(string filename)
{
	ifstream	file;
	string		line;
	string		name;
	string		value;
	unsigned int	i;

	file.open(filename.c_str(), ios::in);
	if (file)
		while (getline(file, line))
		{
			if (line != "")
			{
				i = 0;
				while (line[i] && (line[i] == ' ' || line[i] == '='))
					++i;
				while (line[i] && line[i] != ' ' && line[i] != '=')
				{
					name += line[i];
					++i;
				}
				while (line[i] && (line[i] == ' ' || line[i] == '='))
					++i;
				while (line[i] && line[i] != ' ' && line[i] != '=')
				{
					value += line[i];
					++i;
				}
				if (name != "" && value != "")
					file_data[name] = value;
				name = "";
				value = "";
			}
		}
	file.close();
}

void		class_file_ini::print_file(void)
{
	map<string, string>::const_iterator it;

	it = file_data.begin();
	while (it != file_data.end())
	{
	    std::cout << it->first << "=" << it->second << std::endl;
	    ++it;
	}
	std::cout << std::endl;
}

int			class_file_ini::get_int_value(const std::string &name)
{
	int value;

	value = atoi(this->file_data[name].c_str());
	return (value);
}

std::string	class_file_ini::get_string_value(const std::string &name)
{
	return (this->file_data[name]);
}

void		class_file_ini::set_value(const std::string name, int value)
{
	string	s;

	s = "0";
	this->file_data[name] = s;
	this->modified = true;
}

void		class_file_ini::set_value(const std::string name, const std::string &value)
{
	this->file_data[name] = value;
	this->modified = true;
}
