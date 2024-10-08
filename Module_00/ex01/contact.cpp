/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:47:32 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/01 17:02:20 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void)
{
	return ;
}

void Contact::fill_contact_data(int index, std::string input)
{
	this->data[index] = input;
}

std::string Contact::get_contact_data(int index)
{
	return (this->data[index]);
}