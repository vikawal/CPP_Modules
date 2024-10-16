/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:15:09 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/15 14:56:22 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl is here" << std::endl;
}
Harl::~Harl(void)
{
	std::cout << "Harl is gone" << std::endl;
}

void Harl::debug(void)
{
	std::cout <<  "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // easy to add more options
	void (Harl::*functionPointer[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
// functionPointer is an array of pointers to member functions of Harl (private), which are called using the -> operator.
// those functions take no parameters and return nothing

	for (int i = 0; i < 4; i++)
	{
		if(level == levels[i])
		{
			(this->*functionPointer[i])(); //dereferences the function pointer to get the actual function
			// and calls it. The this-> is necessary because we call a member function of the class.
			return ;
		}
			
			
	}
	
	 std::cout << "[UNKNOWN]: That's not a valid complaint level! Try DEBUG, INFO, WARNING, or ERROR." << std::endl;
}
