/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:45:36 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/22 13:17:20 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void)//:_value(0)
{
	//std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy; //COPY value of the copied object -> the new one (using the assignment operator =).
}

Fixed &Fixed::operator = (Fixed const &copy)
{
	//std::cout << "Assigment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return (*this);
	//operator is used when we assign one Fixed object to another after 
	//both have been constructed
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

//NEW ex01
Fixed::Fixed(const int new_value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = new_value << this->_bits;
}
/*When we pass an integer value to the constructor, it shifts the value 
to the left by 8 bits (1<<8 = 256), which effectively multiplies it by 256.
10(any number) ->  10 << 8 = 10 *256 = 2560;
or 42.42(any number) * 256 = 10818.72 ;
AND roundf(10818.72) = 10819  */

/* 1 << bits is used instead of pow(2, m_bits) because we are only
allowed to use roundf function 
The bitwise << moves m_bits position to de left in binary, it's the equivalent
to 2^m_bits */

/*****POW function in C++ is used to raise a number (the base) 
***to the power of an exponent pow(2.0, 3.0 ->=2×2×2 = 8) */

Fixed::Fixed(float const new_value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(new_value * (1 << this->_bits)); 
	//roundf -> round a floating-point number to the nearest integer.
}
// Fixed::Fixed(float const new_value)
// {
//     std::cout << "Float constructor called" << std::endl;
//     this->_value = roundf(new_value * static_cast<int>(pow(2, this->_bits)));
// }
/*When we pass a floating-point value, it is multiplied by 2828 (256) and rounded. 
The result is stored as the integer _value.
42.42f -> round(42.42 * 256) = 10859 */

float Fixed::toFloat(void) const
{
	return ((double)this->_value / (double)(1 << this->_bits));
}
/*method divides  by 256 to return the original floating-point value.
10859 -> 10859 / 256 = 42.4219   */

int Fixed::toInt (void) const
{
	return (this->_value >> this->_bits);
}
/*method shifts the value to the right by 8 bits (>> 8), dividing by 256 and 
returning the integer part.
 10859/256 = 42.41796875 -> 10859 >> 8 = 42    */


// Overloaded << operator
std::ostream &operator <<( std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}
/*overload allows to output Fixed objects directly.
 It converts the Fixed object to a floating-point number using 
 toFloat() and outputs it.*/

/* std::ostream& is a base class for all output streams in C++. 
This includes 
std::cout (for console output), 
std::ofstream (for file output), 
std::ostringstream (for string output), 
and other streams.*/

//NEW 02 OPERATOR COMPARE functions
bool Fixed::operator > (Fixed const &compare) const
{
	if (this->_value > compare._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator < (Fixed const &compare) const
{
	if (this->_value < compare._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator >= (Fixed const &compare) const
{
	if (this->_value >= compare._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator <= (Fixed const &compare) const
{
	if (this->_value <= compare._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator == (Fixed const &compare) const
{
	if (this->_value == compare._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator != (Fixed const &compare) const
{
	if (this->_value != compare._value)
		return (true);
	else
		return (false);
}

//NEW 02 OPERATOR OPERATION functions

Fixed Fixed::operator + (Fixed const &operation)
{
	return (this->toFloat() + operation.toFloat());
}

Fixed Fixed::operator - (Fixed const &operation)
{
	return (this->toFloat() - operation.toFloat());
}

Fixed Fixed::operator * (Fixed const &operation)
{
	return (this->toFloat() * operation.toFloat());
}

Fixed Fixed::operator / (Fixed const &operation)
{
	return (this->toFloat() / operation.toFloat());
}

//NEW 02 OPERATOR OVERLOAD functions as PREFIX
Fixed& Fixed::operator ++ (void)
{
	this->_value++;
	return (*this);
}

Fixed& Fixed::operator -- (void)
{
	this->_value--;
	return (*this);
}

//NEW 02 OPERATOR OVERLOAD functions as POSTFIX

Fixed Fixed::operator ++ (int)
{
	Fixed temp (*this);
	
	this->operator++(); // Call prefix version
	return (temp); // // return the current value before incrementing it
}

Fixed Fixed::operator -- (int)
{
	Fixed temp (*this);
	
	this->operator--(); //// Call prefix version
	return (temp); // return the current value before incrementing it.
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
//MIN and MAX
const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (b);
	else
		return (a);
}