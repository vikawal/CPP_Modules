/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:11:31 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/18 13:29:44 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <fstream> 
#include <sstream>
#include <string>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;

	public:
	//constructor
		Fixed(); //by default
		///copy assignment operator
		//object is already constructed, we are just
		//makeing a copy later (eg. myFixedNumber2 = myFixedNumber1)
		Fixed(const Fixed &copy); // 
//A copy constructor is a constructor whose first parameter is of type 
//reference to the class itself (mostly const) and which can be invoked 
//with a single argument of this type

//Similar to copying, MOVING also uses the value of an object to 
//set the value to another object. But!! the content is actually 
//transferred from one object (the source) to the other (the destination): 
//the source loses that content, which is taken over by the destination. 
//This moving only happens when the source of the value is an unnamed object. 
		~Fixed(void);

//overloaded operator =
		Fixed &operator=(Fixed const &copy);
// public methos of Class
		int getRawBits(void) const; //getter
		void setRawBits(int const raw); //setter
};

#endif