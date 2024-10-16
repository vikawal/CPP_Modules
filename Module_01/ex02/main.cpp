/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:37:41 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/11 12:57:52 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (void)
{
	//initilization
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	//printing memory addresses (same)
	std::cout << "1. memory address of the string variable\n" << &string << std::endl;
	std::cout << "2. memory address held by stringPTR\n" << stringPTR << std::endl;
	std::cout << "3. memory address held by stringREF\n" << &stringREF << std::endl;
	std::cout << std::endl;

	//printing values (same)
	std::cout << "4. value of the string variable\n" << string << std::endl;
	std::cout << "5. value pointed to by stringPTR\n" << *stringPTR << std::endl;
	std::cout << "6. value pointed to by stringREF\n" << stringREF << std::endl;
}