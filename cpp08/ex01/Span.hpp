#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <exception>
#include <iterator>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _data;

public:
    Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

    void addNumber(int n);
    int shortestSpan() const;
	int longestSpan() const;

    template <typename It>
    void addRange(It begin, It end)
    {
        if (_data.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Too many numbers");

        _data.insert(_data.end(), begin, end);
    }
};


#endif