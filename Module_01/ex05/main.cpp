/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:46:59 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/15 14:48:39 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//WHY POINTERS TO MEMBER FUNCTIONS?
// Using function pointers allows for dynamic dispatch based on user input. 
// Instead of using multiple if or switch statements to call the correct function based on the level,
// we associate each string with a specific function.

int main (void)
{
	Harl harl;
	std::cout << "What Harl wants to say?" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	harl.complain("BLA");
	std::cout << std::endl;
	
	std::cout << "Now try yourself. 5 attempts" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "input: ";
		std::string input;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cerr << "EOF detected" << std::endl;
			exit (1);
		}
		harl.complain(input);
		std::cout << std::endl;
	}
	return (0);
}