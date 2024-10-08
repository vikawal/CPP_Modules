/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:44:07 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/07 12:35:20 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "book.hpp"

int main(void)
{
	PhoneBook book;
	std::string command;
	while (command != "EXIT" && command != "exit")
	{
		if (!std::cin.eof())
		{
			std::cout << "Enter command: ";
			std::getline(std::cin, command);
		}
		else
		{
			std::cout << std::endl;
			return (0);
		}
		if (command.compare("ADD") == 0 || command.compare("add") == 0)
			book.add_contact();
		else if (command.compare("SEARCH") == 0 || command.compare("search") == 0)
			book.search();
		else if (command != "EXIT" && command != "exit")
			std::cout << "Invalid command! Enter valid one!" << std::endl;
	}
	return (0);
}