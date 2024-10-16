/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:19:42 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/11 11:42:20 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// stack memory allocation
void	randomChump(std::string name)
{
	Zombie randomChump(name);
	randomChump.announce();
	
}