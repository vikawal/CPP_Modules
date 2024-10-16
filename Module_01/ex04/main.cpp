/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:45:40 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/15 13:26:47 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static void inform()
{
	std::cout << "You need to provide 3 arguments:" << std::endl; 
	std::cout << "1.the name of file to open" << std::endl;
	std::cout << "2.string to be replaced" << std::endl; 
	std::cout << "3.string to replace with" << std::endl;
	std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
	std::cout << "Example: ./replace file.txt hello world" << std::endl;
	
}

static void replace_s1_s2(std::string& filename, const std::string& s1, const std::string& s2)
//we use references
{
	size_t position = 0;
	
	if (s1.empty())
	{
		std::cout << "File is empty" << std::endl;
		return;
	}
	while ((position = filename.find(s1, position)) != std::string::npos) //npos-> no position found - stop loop
	{
		filename.erase(position, s1.length());
		filename.insert(position, s2);
		position += s2.length();
		//Move the position forward by the length of s2 to avoid infinite loops
	}
}
static std::string get_file_as_string(std::ifstream& file)
{
	std::stringstream buffer;
	if (file.good()) // best practice in file handling in C++ -> ensure file stream is ready for operations
//NOT bad()  reading or writing operation fails. 
//NOT fail() same cases as bad(), + format error 
//NOT eof()  file open for reading has reached the end.
		buffer << file.rdbuf(); //reading whole file into buffer
	else
	{
		std::cerr << "Error reading file" << std::endl;
		return("");
	}
	return (buffer.str()); //buffer.str() returns the content of the buffer as a string
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		inform();
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string newFile = filename + ".replace";
	
	//opening input file
	std::ifstream infile(filename);
	if (!infile.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return (1);
	}
	//opening output file
	std::ofstream outfile(newFile);
	if (!outfile.is_open())
	{
		std::cerr << "Error opening output file" << std::endl;
		return (1);
	}

	std::string fileContent = get_file_as_string(infile);
	infile.close();

	replace_s1_s2(fileContent, s1, s2);
	outfile << fileContent;
	outfile.close();

	return (0);
}