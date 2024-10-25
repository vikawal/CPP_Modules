/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:45:44 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/22 15:17:30 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <math.h>
// #include <fstream> 
// #include <sstream>
// #include <string>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8; // 2 ^ 8  = 256
		//value is shifted by 8 bits to the left or right depending on the operation

	public:
	//constructor
		Fixed(); //by default
	
		Fixed(const Fixed &copy); // full new object copy is created
		~Fixed(void);
		
		Fixed(const int new_value);
		Fixed(const float new_value);

//overloaded operator =
		Fixed &operator=(Fixed const &copy);

//FOR ex02 NEW
// The 6 comparison operators: 
		bool operator > (Fixed const &compare) const;
		bool operator < (Fixed const &compare) const;
		bool operator >= (Fixed const &compare) const;
		bool operator <= (Fixed const &compare) const;
		bool operator == (Fixed const &compare) const;
		bool operator != (Fixed const &compare) const;
//The 4 arithmetic operators:
		Fixed operator + (Fixed const &operation);
		Fixed operator - (Fixed const &operation);
		Fixed operator * (Fixed const &operation);
		Fixed operator / (Fixed const &operation);
// The 4 increment/decrement
		Fixed& operator ++ (void); //prefix
		Fixed& operator -- (void); // prefix
		Fixed operator ++ (int);//suffix
		Fixed operator -- (int);//suffix

// public methos of Class
		int getRawBits(void) const; //getter
		void setRawBits(int const raw); //setter

		float toFloat( void ) const;
		int toInt( void ) const;
// NEW 02 public methods:
		
		static Fixed& min(Fixed &a, Fixed &b);
/*allows modification of the passed objects (a and b). 
It returns a reference to a non-constant Fixed object -> the caller CAN change 
the returned object after the function call.*/
		static const Fixed& min (Fixed const &a, Fixed const &b);
/* This version works with constant objects (Fixed const &). 
It returns a reference to a constant Fixed object -> the caller cannot change
the returned object after the function call. -> to ensure the objects you’re 
working with won’t be changed inside the function or afterward.*/
		
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max (Fixed const &a, Fixed const &b);
		
};
//  "Friend" function for the insertion (<<) operator
std::ostream &operator << (std::ostream &out, const Fixed &fixed);
#endif

/*A friend function is useful when you need a non-member function to 
access the private or protected members of a class. It is often used 
for operator overloading (like << or >>), where the function needs to 
access class internals but should not be a member of the class itself. 
By using a friend function, we maintain ENCAPSULATION and give only 
selective access to the class’s private data.*/



