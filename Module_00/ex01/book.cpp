/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:16:16 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/08 14:51:54 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "book.hpp"

PhoneBook::PhoneBook(void) : index(0)
{
	prompt[0] = "Enter first name: ";
	prompt[1] = "Enter last name: ";
	prompt[2] = "Enter nickname: ";
	prompt[3] = "Enter phone number: ";
	prompt[4] = "Enter darkest secret: ";
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Welcome to the LOVELY_phonebook!" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Enter one of possible commands! -------->>>>" << std::endl;
	std::cout << "ADD - add a new contact" << std::endl;
	std::cout << "SEARCH - search for a contact by index" << std::endl;
	std::cout << "EXIT - exit the program" << std::endl;
}

//functions of book: add, search, exit
void PhoneBook::add_contact(void)
{
	if (this->index == 8) //full Phone_book (max = 8 contacts)
	{
		std::cout << "Phonebook is full! Adding a new contact will overwrite the oldest one!" << std::endl;
		std::cout << "Do you want to continue? (y/n): ";
		std::string input;
		std::getline(std::cin, input);
		if (input.empty() || input[0] != 'y')
			return ;
		this->index = 0;
		
	}
	std::string input;
	for (int j(0); j < 5;)
	{
		std::cout << this->prompt[j];
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return ;
		}
		if (j == 3) //phone number
        {
            if (input.empty() || !is_valid_phone_number(input))
            {
                std::cout << "Invalid phone number! Please enter digits, '+' or '-'." << std::endl;
                continue;
            }
        }
		if (input.empty() || !is_valid_input(input))
			std::cout << "No empty fields allowed! Fill your info!" << std::endl;
		else
		{
			this->contacts[this->index].fill_contact_data(j, input);
			j++;
		}
	}
	show_added_contact();
	this->index++;
}

bool PhoneBook::is_valid_input(const std::string& str)
{
	for (unsigned long j(0); j < str.length(); j++)
	{
		if(!(std::isspace(str[j])))
			return (true);
	}
	return (false);
}

bool PhoneBook::is_valid_phone_number(const std::string& str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
		char c = str[i];
        if (!std::isdigit(c) && c != '+' && c != '-')
        {
            return false; 
        }
    }
    return true; 
}


void PhoneBook::show_added_contact(void)
{
	std::cout << std:: endl << "Contact added!" << std::endl << std::endl;
	for (int j(0); j < 5; j++)
	{
		std::cout << prompt[j].substr(6) << this->contacts[this->index].get_contact_data(j) << std::endl;
	}
	
}
void PhoneBook::search(void)
{
	std::cout << "All contacts:" << std::endl;
	int j = 0;
	while (j < 8 && !(this->contacts[j].get_contact_data(0).empty()))
	{
		show_all_contacts(j);
		j++;
	}
	std::cout << "CHOOSE the contact" << std::endl;
	show_index_contact();
}

void PhoneBook::show_all_contacts(int j)
{
    // Print contact index (right-aligned in a printing width of 10 characters)
    std::cout << std::setw(10) << j + 1 << "|";

    for (int i = 0; i < 3; i++)
    {
        std::string data = this->contacts[j].get_contact_data(i);
      
        if (data.length() > 10)
            data = data.substr(0, 9) + "."; // cut to 9 characters and add '.'
        
        // Print data in a field of width 10, right-aligned
        std::cout << std::setw(10) << std::right << data << "|";
    }

    std::cout << std::endl;
}

void PhoneBook::show_index_contact(void)
{
	std::string index; //user input
	int number (0); //ascii of input
	while (1)
	{
		std::cout << "Give index of the contact: ";
		std::getline(std::cin, index); //read input and store in index
		if(std::cin.eof()) //Ctrl+D or Ctrl+Z to stop loop by user
		{
			std::cout << std::endl;
			return ;
		}
		if ((index.length() == 1) && '1' <= index[0] && index[0] <= '8')
			break; //valid index
		else
			std::cout << "NO such index (min index = 1, max = 8)!" << std::endl;
	}
	number = index[0] - '0';
	if (this->contacts[number - 1].get_contact_data(0).empty())
	{
		std::cout << "No contact saved at this index." << std::endl;
		return ;

	}
	std::cout << "--------------------------------------------" << std::endl;
	for (int i(0); i < 5; i++)
		std::cout << prompt[i].substr(6) << this->contacts[number - 1].get_contact_data(i) << std::endl;
		// std::cout << prompt[i] << this->contacts[number - 1].get_contact_data(i) << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
}

// void PhoneBook::display_wished_contact(void)
// {
//     std::string index;
//     int num = 0;
//     while (1)
//     {
//         std::cout << "Give index for wished contact: ";
//         std::getline(std::cin, index);
//         if(std::cin.eof())
//         {
//             std::cout << std::endl;
//             return ;
//         }
//         if ((index.length() == 1) && '1' <= index[0] && index[0] <= '8')
//             break;
//         else
//             std::cout << "Wrong index!" << std::endl;
//     }
//     num = index[0] - '0';
//     if (this->contacts[num - 1].get_contact_info(0).empty())
//     {
//         std::cout << "Sry no saved contact at given index." << std::endl;
//         return ;
//     }
//     std::cout << "____________________________________"<< std::endl << std::endl;
//     for (int j = 0; j < 5; j++)
//     {
//         std::cout << prompt[j].substr(6) << this->contacts[num - 1].get_contact_info(j) << std::endl;
//     }
//     std::cout << "____________________________________"<< std::endl << std::endl;
// }