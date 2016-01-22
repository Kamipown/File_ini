#include "class_file_ini.h"

using namespace std;

class_file_ini::class_file_ini(void)
{

}

class_file_ini::class_file_ini(const std::string &filename)
{
	this->read_file(filename);
}

void			class_file_ini::read_file(const std::string &filename)
{
	ifstream		file;
	string			line;
	string			name;
	string			value;
	unsigned int	i;

	file.open(filename.c_str(), ios::in);
	if (!file)
		return ;
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

void			class_file_ini::write_file(const std::string &filename)
{
	map<string, string>::const_iterator it;
	ofstream	file;

	file.open(filename.c_str(), ios::out | ios::trunc);
	if (!file)
		return ;
	it = file_data.begin();
	while (it != file_data.end())
	{
	    file << it->first << "=" << it->second << std::endl;
	    ++it;
	}
	file.close();
}

void			class_file_ini::print_data(void)
{
	map<string, string>::const_iterator it;

	it = file_data.begin();
	while (it != file_data.end())
	{
	    std::cout << it->first << "+" << it->second << std::endl;
	    ++it;
	}
	std::cout << std::endl;
}

int				class_file_ini::get_int_value(const std::string &name)
{
	int		value;

	value = atoi(this->file_data[name].c_str());
	return (value);
}

std::string		class_file_ini::get_string_value(const std::string &name)
{
	return (this->file_data[name]);
}

static string	int_to_string(int n)
{
	string	str;
	bool	neg;
	char	c;
	int		i;

	i = 0;
	if (n == 0)
		return ("0");
	if (n < 0)
	{
		n = -n;
		neg = true;
	}
	else
		neg = false;
	while (n)
	{
		str += '0' + (n % 10);
		n /= 10;
	}
	if (neg)
		str += '-';
	while (i < (str.size() / 2))
	{
		c = str[i];
		str[i] = str[str.size() - i - 1];
		str[str.size() - i - 1] = c;
		++i;
	}
	return (str);
}

void			class_file_ini::set_value(const std::string name, const int &value)
{
	this->file_data[name] = int_to_string(value);
}

void			class_file_ini::set_value(const std::string name, const std::string &value)
{
	this->file_data[name] = value;
}