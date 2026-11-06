#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(Fixed const& other) {
	*this = other;
}

Fixed&	Fixed::operator=(Fixed const& other) {
	if( this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(int const n) : _value(n << _fractionalBits) {}

Fixed::Fixed(float const f) : _value(roundf(f * (1 << _fractionalBits))) {}

int		Fixed::getRawBits( void ) const {
	return _value;
}

void	Fixed::setRawBits( int const raw ) {
	_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)_value / (1 << _fractionalBits);
}

int		Fixed::toInt( void ) const {
	return _value >> _fractionalBits;
}

std::ostream&	operator<<(std::ostream& out, Fixed const& f) {
	out << f.toFloat();
	return out;
}

//bool
bool	Fixed::operator>(Fixed const& other) const {return _value > other._value;}
bool	Fixed::operator<(Fixed const& other) const {return _value < other._value;}
bool	Fixed::operator>=(Fixed const& other) const {return _value >= other._value;}
bool	Fixed::operator<=(Fixed const& other) const {return _value <= other._value;}
bool	Fixed::operator==(Fixed const& other) const {return _value == other._value;}
bool	Fixed::operator!=(Fixed const& other) const {return _value != other._value;}

// +-*/
Fixed	Fixed::operator+(Fixed const& other) const {
	Fixed	result;
	result._value = _value + other._value;
	return result;
}
//-
Fixed	Fixed::operator-(Fixed const& other) const {
	Fixed	result;
	result._value = _value - other._value;
	return result;
}
//*
Fixed	Fixed::operator*(Fixed const& other) const {
	Fixed	result;
	result._value = ((long)_value * other._value) >> _fractionalBits;
	return result;
}
// /
Fixed	Fixed::operator/(Fixed const& other) const {
	Fixed	result;
	result._value = ((long)_value << _fractionalBits) / other._value;
	return result;
}

// ++ --
Fixed&	Fixed::operator++(){
	_value++;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed old(*this);
	_value++;
	return old;
}

Fixed&	Fixed::operator--(){
	_value--;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed old(*this);
	_value--;
	return old;
}

// min max & const
Fixed&	Fixed::min(Fixed& a, Fixed& b){
	return(a<b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b){
	return(a>b) ? a : b;
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b){
	return(a<b) ? a : b;
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b){
	return(a>b) ? a : b;
}
