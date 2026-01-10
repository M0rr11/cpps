#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

