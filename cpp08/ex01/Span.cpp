#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_data = other._data;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_data.size() >= _maxSize)
        throw std::runtime_error("Span is full");

    _data.push_back(n);
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers");
    
    std::vector<int>::const_iterator min = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator max = std::max_element(_data.begin(), _data.end());

    return (*max - *min);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough numbers");
    
    std::vector<int> tmp = _data;
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];
    
    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    
    return minSpan;
}



