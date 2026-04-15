#include "Span.hpp"

int main()
{
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;

    Span bigSpan(10000);
    for (int i = 0; i < 10000; ++i)
        bigSpan.addNumber(i);
    std::cout << bigSpan.shortestSpan() << std::endl;
}