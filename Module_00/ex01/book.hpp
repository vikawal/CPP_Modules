/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:03:38 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/08 14:50:35 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BOOK_HPP
# define BOOK_HPP

#include <iostream>
#include <iomanip> // For std::setw 
#include "contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		void	search(void);
		void	add_contact(void);
	
	private:
		std::string prompt[5];
		Contact contacts[8];
		int index;

		void	show_added_contact(void);
		void	show_all_contacts(int j);
		void	show_index_contact(void);
		
		bool	is_valid_input(const std::string& str);
		bool	is_valid_phone_number(const std::string& str);
};

#endif