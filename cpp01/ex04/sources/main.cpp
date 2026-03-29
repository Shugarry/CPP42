#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Format: <filename> <s1> <s2>" << std::endl;
		return 0;
	}
	if (!av[1] || !av[2] || !av[3] || !*av[1] || !*av[2] || !*av[3])
	{
		std::cout << "An argument is invalid" << std::endl;
		return 0;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	int s1_len = s1.length();

	std::ifstream read_file(filename.c_str());
	if (!read_file.is_open()) {
		std::cout << "Error opening input file" << std::endl;
		return 1;
	}
	std::ofstream write_file((filename + ".replace").c_str());
	if (!write_file.is_open()) {
		std::cout << "Error creating output file" << std::endl;
		read_file.close();
		return 1;
	}

	std::string buffer;
	while (getline(read_file, buffer))
	{
		int len = buffer.length();
		for(int i = 0; i < len; i++)
		{
			if (i + s1_len <= len && buffer.compare(i, s1_len, s1) == 0)
			{
				write_file << s2;
				i += s1_len - 1;
			}
			else
				write_file << buffer[i];
		}
		write_file << '\n';
	}
	read_file.close();
	write_file.close();
	return 0;
}
