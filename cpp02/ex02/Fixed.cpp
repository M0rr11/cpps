#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPointValue(0){
}

Fixed::Fixed(const int value)
{
    this->fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    this->fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(){
}

int Fixed::getRawBits( void ) const
{
    return this->fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->fixedPointValue >> fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->fixedPointValue != other.fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
    this->fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixedPointValue--;
    return temp;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
