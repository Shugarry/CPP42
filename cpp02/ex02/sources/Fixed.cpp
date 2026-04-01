#include "../headers/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : raw_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	raw_value = other.raw_value;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	raw_value = num << fractional_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	raw_value = roundf(num * (1 << fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		raw_value = other.raw_value;
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return raw_value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	raw_value = raw;
}

int Fixed::toInt() const
{
	return raw_value >> fractional_bits;
}

float Fixed::toFloat() const
{
	return (float)raw_value / (1 << fractional_bits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->raw_value > other.raw_value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->raw_value < other.raw_value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->raw_value >= other.raw_value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->raw_value <= other.raw_value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->raw_value == other.raw_value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->raw_value != other.raw_value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed tmp;
	tmp.raw_value = (this->raw_value + other.raw_value);
	return tmp;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed tmp;
	tmp.raw_value = (this->raw_value - other.raw_value);
	return tmp;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed tmp(this->toFloat() * other.toFloat());
	return tmp;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed tmp(this->toFloat() / other.toFloat());
	return tmp;
}

Fixed& Fixed::operator++()
{
	++raw_value;
	return *this;
}

Fixed& Fixed::operator--()
{
	--raw_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	raw_value++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	raw_value++;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}
